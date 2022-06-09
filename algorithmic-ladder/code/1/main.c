#include <inttypes.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define VALUE_SIZE sizeof(uint32_t)
#define ADDR_SIZE sizeof(size_t)
#define SIZE (VALUE_SIZE + ADDR_SIZE * 2)

#define GET_VALUE(p) (*(uint32_t *)(p))
#define SET_VALUE(p, val) (*(uint32_t *)(p) = (val))

#define GET_ADDR(p) (*(size_t *)(p))
#define SET_ADDR(p, val) (*(size_t *)(p) = (val))

#define GET_PREV(p) (*(size_t *)((p) + VALUE_SIZE))
#define SET_PREV(p, val) (*(size_t *)((p) + VALUE_SIZE) = (val))

#define GET_NEXT(p) (*(size_t *)((p) + VALUE_SIZE + ADDR_SIZE))
#define SET_NEXT(p, val) (*(size_t *)((p) + VALUE_SIZE + ADDR_SIZE) = (val))

int main() {
  uint32_t n, k, m;
  scanf("%" PRIu32 " %" PRIu32 " %" PRIu32, &n, &k, &m);

  void *bp = malloc(n * SIZE);
  for (uint32_t i = 1; i <= n; ++i) {
    void *curr = bp + ((i - 1) * SIZE);
    SET_VALUE(curr, i);
    if (i != 1)
      SET_PREV(curr, curr - SIZE);
    if (i != n)
      SET_NEXT(curr, curr + SIZE);
  }
  SET_PREV(bp, bp + (n - 1) * SIZE);
  SET_NEXT(bp + (n - 1) * SIZE, bp);

  void *pk = bp;
  void *pm = bp + (n - 1) * SIZE;
  uint32_t remains = n;
  uint32_t k_mod, m_mod;

  while (remains) {
    // 88 -> 97
    k_mod = !(k % remains) ? remains : k % remains;
    m_mod = !(m % remains) ? remains : m % remains;

    for (uint32_t i = 0; i < k_mod - 1; ++i)
      pk = GET_NEXT(pk);
    for (uint32_t i = 0; i < m_mod - 1; ++i)
      pm = GET_PREV(pm);

    uint32_t value_k = GET_VALUE(pk);
    uint32_t value_m = GET_VALUE(pm);

    if (value_k == value_m) {
      printf("%" PRIu32, value_k);
      remains -= 1;

      break;
    } else {
      printf("%" PRIu32 " ", value_k);
      printf("%" PRIu32 " ", value_m);
      remains -= 2;

      if (pk == GET_PREV(pm)) {
        void *pk_p = GET_PREV(pk);
        void *pm_n = GET_NEXT(pm);

        SET_NEXT(pk_p, pm_n);
        SET_PREV(pm_n, pk_p);

        pk = pm_n;
        pm = pk_p;
      } else if (pk == GET_NEXT(pm)) {
        void *pk_n = GET_NEXT(pk);
        void *pm_p = GET_PREV(pm);

        SET_NEXT(pm_p, pk_n);
        SET_PREV(pk_n, pm_p);

        pk = pk_n;
        pm = pm_p;
      } else {
        void *pk_n = GET_NEXT(pk);
        void *pk_p = GET_PREV(pk);
        void *pm_n = GET_NEXT(pm);
        void *pm_p = GET_PREV(pm);

        SET_NEXT(pk_p, pk_n);
        SET_PREV(pk_n, pk_p);
        SET_NEXT(pm_p, pm_n);
        SET_PREV(pm_n, pm_p);

        pk = pk_n;
        pm = pm_p;
      }
    }
  }

  /* printf("\nremaining: %" PRIu32 "\n", remains); */

  free(bp);
}
