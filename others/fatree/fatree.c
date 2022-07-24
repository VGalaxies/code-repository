#include <assert.h>
#include <err.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <wchar.h>
#include <math.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

// #include <uchar.h>
// typedef char16_t c16;

// maybe memory leak
#define panic_on(cond, msg)                                                    \
  do {                                                                         \
    if (cond) {                                                                \
      err(EXIT_FAILURE, msg);                                                  \
    }                                                                          \
  } while (0)

/* FAT32 */

struct fat32_header {
  u8 BS_jmpBoot[3];
  u8 BS_OEMName[8];
  u16 BPB_BytsPerSec;
  u8 BPB_SecPerClus;
  u16 BPB_RsvdSecCnt;
  u8 BPB_NumFATs;
  u16 BPB_RootEntCnt;
  u16 BPB_TotSec16;
  u8 BPB_Media;
  u16 BPB_FATSz16;
  u16 BPB_SecPerTrk;
  u16 BPB_NumHeads;
  u32 BPB_HiddSec;
  u32 BPB_TotSec32;
  u32 BPB_FATSz32;
  u16 BPB_ExtFlags;
  u16 BPB_FSVer;
  u32 BPB_RootClus;
  u16 BPB_FSInfo;
  u16 BPB_BkBootSec;
  u8 BPB_Reserved[12];
  u8 BS_DrvNum;
  u8 BS_Reserved1;
  u8 BS_BootSig;
  u32 BS_VolID;
  u8 BS_VolLab[11];
  u8 BS_FilSysType[8];
  u8 __padding_1[420];
  u16 Signature_word;
} __attribute__((packed));

struct fat32_dent {
  u8 DIR_Name[11];
  u8 DIR_Attr;
  u8 DIR_NTRes;
  u8 DIR_CrtTimeTenth;
  u16 DIR_CrtTime;
  u16 DIR_CrtDate;
  u16 DIR_LastAccDate;
  u16 DIR_FstClusHI;
  u16 DIR_WrtTime;
  u16 DIR_WrtDate;
  u16 DIR_FstClusLO;
  u32 DIR_FileSize;
} __attribute__((packed));

struct fat32_ldent {
  u8 LDIR_Ord;
  u16 LDIR_Name1[5];
  u8 LDIR_Attr;
  u8 LDIR_Type;
  u8 LDIR_Chksum;
  u16 LDIR_Name2[6];
  u16 LDIR_FstClusLO;
  u16 LDIR_Name3[2];
} __attribute__((packed));

#define CLUS_INVALID 0xffffff7

#define ATTR_READ_ONLY 0x01
#define ATTR_HIDDEN 0x02
#define ATTR_SYSTEM 0x04
#define ATTR_VOLUME_ID 0x08
#define ATTR_DIRECTORY 0x10
#define ATTR_ARCHIVE 0x20

#define ATTR_LONG_NAME                                                         \
  (ATTR_READ_ONLY | ATTR_HIDDEN | ATTR_SYSTEM | ATTR_VOLUME_ID)

#define LAST_LONG_ENTRY 0x40

/* BMP */

struct bitmap_header {
  u16 magic;
  u32 size;
  u16 reserved[2];
  u32 offset;
} __attribute__((packed));

struct bitmap_info_header { // BITMAPINFOHEADER
  u32 header_size;
  u32 width_in_pixels;
  u32 height_in_pixels;
  u16 color_planes_num;
  u16 bits_per_pixel;
  u32 compression_method;
  u32 image_size;
  u32 horizontal_resolution;
  u32 vertical_resolution;
  u32 colors_num;
  u32 important_colors_num;
} __attribute__((packed));

/* declaration */

struct fat32_header *hdr;
static u8 vis[65536];

/* subroutines */

void *map_disk(const char *filename) {
  int fd = open(filename, O_RDWR);

  if (fd < 0) {
    goto release;
  }

  off_t size = lseek(fd, 0, SEEK_END);
  if (size == -1) {
    goto release;
  }

  struct fat32_header *hdr =
      mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
  if (hdr == (void *)-1) {
    goto release;
  }

  close(fd);

  assert(hdr->Signature_word == 0xaa55); // this is an MBR
  assert(hdr->BPB_TotSec32 * hdr->BPB_BytsPerSec == size);

  return hdr;

release:
  perror("map disk");
  if (fd > 0) {
    close(fd);
  }
  exit(1);
}

void *cluster_to_sec(int n) {
  // RTFM: Sec 3.5 and 4
  u32 data_sec = hdr->BPB_RsvdSecCnt + hdr->BPB_NumFATs * hdr->BPB_FATSz32;
  data_sec += (n - 2) * hdr->BPB_SecPerClus;
  return ((char *)hdr) + data_sec * hdr->BPB_BytsPerSec;
}

int sec_to_cluster(void *clus) {
  u32 data_sec = (clus - (void *)hdr) / hdr->BPB_BytsPerSec;
  return (data_sec - (hdr->BPB_RsvdSecCnt + hdr->BPB_NumFATs * hdr->BPB_FATSz32)) / hdr->BPB_SecPerClus + 2;
}

void get_filename(struct fat32_dent *dent, char *buf) {
  // RTFM: Sec 6.1
  int len = 0;
  for (int i = 0; i < sizeof(dent->DIR_Name); i++) {
    if (dent->DIR_Name[i] != ' ') {
      if (i == 8)
        buf[len++] = '.';
      buf[len++] = dent->DIR_Name[i];
    }
  }
  buf[len] = '\0';
}

unsigned char get_checksum(unsigned char *filename) {
  // RTFM: Sec 7.2
  short len;
  unsigned char sum;
  sum = 0;
  for (len = 11; len != 0; len--) {
    // NOTE: The operation is an unsigned char rotate right
    sum = ((sum & 1) ? 0x80 : 0) + (sum >> 1) + *filename++;
  }
  return sum;
}

int get_long_filename(struct fat32_ldent *ldent, wchar_t *buf,
                      unsigned char checksum) { // ldent -> pass short entry
  // RTFM: Sec 7
  int curr_ord = 1;
  int curr_index = 0;
  struct fat32_ldent *curr_ldent = ldent;
  while (1) {
    curr_ldent -= 1;

    if ((curr_ldent->LDIR_Ord & ~LAST_LONG_ENTRY) != curr_ord ||
        curr_ldent->LDIR_Attr != ATTR_LONG_NAME ||
        curr_ldent->LDIR_Chksum != checksum) {
      buf[curr_index++] = '\0';
      return -1; // fail
    }

    for (int i = 0; i < sizeof(curr_ldent->LDIR_Name1) / sizeof(u16); i++) {
      if (curr_ldent->LDIR_Name1[i] == 0) {
        buf[curr_index++] = '\0';
        return 0;
      }
      buf[curr_index++] = curr_ldent->LDIR_Name1[i];
    }

    for (int i = 0; i < sizeof(curr_ldent->LDIR_Name2) / sizeof(u16); i++) {
      if (curr_ldent->LDIR_Name2[i] == 0) {
        buf[curr_index++] = '\0';
        return 0;
      }
      buf[curr_index++] = curr_ldent->LDIR_Name2[i];
    }

    for (int i = 0; i < sizeof(curr_ldent->LDIR_Name3) / sizeof(u16); i++) {
      if (curr_ldent->LDIR_Name3[i] == 0) {
        buf[curr_index++] = '\0';
        return 0;
      }
      buf[curr_index++] = curr_ldent->LDIR_Name3[i];
    }

    if ((curr_ord | LAST_LONG_ENTRY) == curr_ldent->LDIR_Ord) {
      return 0;
    } else {
      curr_ord++;
    }
  }
}

size_t zero_count(char *data, size_t length) {
  size_t res = 0;
  for (size_t i = 0; i < length; ++i) {
    if (data[i] == 0) {
      res++;
    }
  }
  return res;
}

double dot_product(char *lhs, char *rhs, size_t length) {
  size_t lhs_sum = 0;
  size_t rhs_sum = 0;
  double res = 0;
  for (size_t i = 0; i < length; ++i) {
    lhs_sum += lhs[i] * lhs[i];
    rhs_sum += rhs[i] * rhs[i];
    res += lhs[i] * rhs[i];
  }
  res /= sqrt(lhs_sum) * sqrt(rhs_sum);
  return res;
}

void *find_fit(char *lhs, char *rhs, size_t occupied, size_t row_size) {
  int data_clus_num = (hdr->BPB_TotSec32 - hdr->BPB_RsvdSecCnt -
                       hdr->BPB_FATSz32 * hdr->BPB_NumFATs) /
                      hdr->BPB_SecPerClus;
  void *target_clus_st = NULL;
  double target_res = -1;
  for (int i = 2; i < data_clus_num + 2; ++i) {
    if (!vis[i]) {
      memset(rhs + occupied, 0, row_size - occupied);
      void *data = cluster_to_sec(i);
      memcpy(rhs + occupied, data, row_size - occupied);
      double res = dot_product(lhs, rhs, row_size);
      if (res > target_res) {
        target_res = res;
        target_clus_st = data;
      }
    }
  }

  vis[sec_to_cluster(target_clus_st)] = 1;
  return target_clus_st;
}

char *analyse_data(int data_clus) {
  void *data = cluster_to_sec(data_clus);

  struct bitmap_header *bitmap_hdr = (struct bitmap_header *)data;
  if (bitmap_hdr->magic != 0x4d42 ||  // note order
      bitmap_hdr->offset != 54) {
    return NULL;
  };

  struct bitmap_info_header *bitmap_info_hdr =
      (struct bitmap_info_header *)(data + sizeof(struct bitmap_header));
  if (bitmap_info_hdr->header_size != 40 ||
      bitmap_info_hdr->bits_per_pixel != 24) {
    return NULL;
  }

  char template[] = "/tmp/XXXXXX.bmp";
  int fd = mkstemps(template, 4);
  panic_on(fd == -1, "mkstemps");

  ssize_t written_bytes;
  size_t header_size = sizeof(struct bitmap_header) + sizeof(struct bitmap_info_header);
  written_bytes = write(fd, data, header_size);
  panic_on(written_bytes != header_size, "write");

  size_t row_size = (24 * bitmap_info_hdr->width_in_pixels + 31) / 32 * 4;  // unit -> byte
  size_t data_size = row_size * bitmap_info_hdr->height_in_pixels;
  size_t bytes_per_clus = hdr->BPB_BytsPerSec * hdr->BPB_SecPerClus;
  if (row_size > bytes_per_clus) {
    written_bytes = write(fd, data + header_size, data_size);  //  TODO -> out of range
    panic_on(written_bytes != data_size, "write");
  } else {
    void *curr_clus_st = data;
    void *curr_clus_ed = curr_clus_st + bytes_per_clus;
    void *curr_data = data + header_size;

    for (size_t i = 0; i < bitmap_info_hdr->height_in_pixels; ++i) {
      vis[sec_to_cluster(curr_clus_st)] = 1;

      if (curr_data + row_size <= curr_clus_ed) {
        written_bytes = write(fd, curr_data, row_size);
        panic_on(written_bytes != row_size, "write");
        curr_data += row_size;
      } else {  // across cluster
        // assume continuous first
        char *lhs = (char *)malloc(row_size);
        char *rhs = (char *)malloc(row_size);
        memcpy(lhs, curr_data - row_size, row_size);
        memcpy(rhs, curr_data, row_size);
        double res = dot_product(lhs, rhs, row_size);
        if (res < 0 && zero_count(rhs, row_size) > 16) {
          printf("%d -> %lf", sec_to_cluster(curr_clus_st), res);
          curr_clus_st = find_fit(lhs, rhs, curr_clus_ed - curr_data, row_size);
          printf(" -> %d\n", sec_to_cluster(curr_clus_st));
          int gap = row_size - (curr_clus_ed - curr_data);
          curr_clus_ed = curr_clus_st + bytes_per_clus;
          curr_data = curr_clus_st + gap;
        } else {
          curr_data += row_size;
          curr_clus_st = curr_clus_ed;
          curr_clus_ed = curr_clus_st + bytes_per_clus;
        }
        written_bytes = write(fd, rhs, row_size);
        panic_on(written_bytes != row_size, "write");
        free(lhs);
        free(rhs);
      }
    }
  }

  panic_on(close(fd) == -1, "close");

  char *cmd = malloc(32);
  memset(cmd, 0, 32);
  char *sha1sum = malloc(64);
  memset(sha1sum, 0, 64);

  sprintf(cmd, "sha1sum %s", template);
  FILE *fp = popen(cmd, "r");
  panic_on(fp < 0, "popen");
  fscanf(fp, "%s", sha1sum);
  panic_on(pclose(fp) == -1, "pclose");
  free(cmd);

  return sha1sum;
}

void analyse_dent(struct fat32_dent *dent) {
  char filename[32];
  memset(filename, 0, sizeof(filename));
  get_filename(dent, filename);

  if (((struct fat32_ldent *)(dent - 1))->LDIR_Ord == 1 ||
      ((struct fat32_ldent *)(dent - 1))->LDIR_Ord == (1 | LAST_LONG_ENTRY)) {
    wchar_t long_filename[256];
    wmemset(long_filename, 0, sizeof(long_filename) / sizeof(wchar_t));
    int res = get_long_filename((struct fat32_ldent *)dent, long_filename,
                                get_checksum(dent->DIR_Name));
    if (res != -1) {
      int data_clus = dent->DIR_FstClusLO | (dent->DIR_FstClusHI << 16);
      char *sha1sum = (char *)analyse_data(data_clus);
      if (sha1sum != NULL) {
        printf("%s  %ls\n", sha1sum, long_filename);
        fflush(stdout);
        free(sha1sum);
      }
    }
  }
}

void analyse_cluster(int data_clus) {
  void *clus = cluster_to_sec(data_clus);
  int ndents =
      hdr->BPB_BytsPerSec * hdr->BPB_SecPerClus / sizeof(struct fat32_dent);
  for (int d = 0; d < ndents; d++) {
    struct fat32_dent *dent = (struct fat32_dent *)clus + d;
    if (dent->DIR_Name[8] == 'B' && dent->DIR_Name[9] == 'M' &&
        dent->DIR_Name[10] == 'P') { // characteristic
      vis[data_clus] = 1;
      analyse_dent(dent);
    }
  }
}

void scan_clusters() {
  int data_clus_num = (hdr->BPB_TotSec32 - hdr->BPB_RsvdSecCnt -
                       hdr->BPB_FATSz32 * hdr->BPB_NumFATs) /
                      hdr->BPB_SecPerClus;
  for (int i = 2; i < data_clus_num + 2; ++i) {
    analyse_cluster(i);
  }
}

/* program entry */

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s fs-image\n", argv[0]);
    exit(1);
  }

  setbuf(stdout, NULL);

  assert(sizeof(struct fat32_header) == 512); // defensive
  assert(sizeof(struct fat32_dent) == 32);    // defensive
  assert(sizeof(struct fat32_ldent) == 32);   // defensive

  assert(sizeof(struct bitmap_header) == 14);      // defensive
  assert(sizeof(struct bitmap_info_header) == 40); // defensive

  // map disk image to memory
  hdr = map_disk(argv[1]);

  // file recovery
  scan_clusters();

  // unmap
  munmap(hdr, hdr->BPB_TotSec32 * hdr->BPB_BytsPerSec);
}
