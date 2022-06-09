

# C++ 高级程序设计 OJ

## 翻转数字

```c++
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long n, res;
char str[32];

void reverse() {
  size_t length = strlen(str + 1);
  size_t i, j;
  for (i = 1, j = length; i < j; ++i, --j) {
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
  }
}

int main() {
  scanf("%ld", &n);
  if (n >= 0) {
    snprintf(str + 1, 30, "%ld", n);
  } else {
    snprintf(str, 31, "%ld", n);
  }
  reverse();
  res = atol(str + 1);
  if (n >= 0) {
    if (res >= INT32_MAX) {
      printf("-1\n");
    } else {
      printf("%ld\n", res);
    }
  } else {
    if (res >= INT32_MAX + 1L) {
      printf("-1\n");
    } else {
      printf("-%ld\n", res);
    }
  }
}
```



## 部分乘积

```c++
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n, now;
long res = 1;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &now);
    res = res * now;
    if (res > INT32_MAX) {
      printf("-1\n");
      return 0;
    } else {
      printf("%ld ", res);
    }
  }
}
```



## 特殊元素

```c++
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int res = 0, now;

int main() {
  while (scanf("%d", &now) != EOF) {
    res = res ^ now;
  }
  printf("%d\n", res);
}
```



## Base64 编码

https://www.base64encoder.io/

```c++
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int total = 0;
char arr[3];

void dec_to_bin(int num, char *base) {
  int curr = 1;
  for (int i = 0; i < 8; i++) {
    curr = num % 2;
    num = num / 2;
    base[7 - i] = curr;
  }
}

int bin_to_dec(char *base) {
  int res = 0;
  for (int i = 0; i < 8; ++i) {
    res = res * 2 + base[i];
  }
  return res;
}

void copy(char *dst, char *src, int n) {
  for (int i = 0; i < n; ++i) {
    dst[i] = src[i];
  }
}

static const char *table[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
    "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z",
    "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m",
    "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z",
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "+", "/",
};

void handle_three() {
  char ori[24];
  char temp[32];

  memset(ori, 0, sizeof ori);
  memset(temp, 0, sizeof temp);

  dec_to_bin(arr[0], ori);
  dec_to_bin(arr[1], ori + 8);
  dec_to_bin(arr[2], ori + 16);

  copy(temp + 2, ori, 6);
  copy(temp + 10, ori + 6, 6);
  copy(temp + 18, ori + 12, 6);
  copy(temp + 26, ori + 18, 6);

  for (int i = 0; i < 4; ++i) {
    printf("%s", table[bin_to_dec(temp + i * 8)]);
  }
}

void handle_two() {
  char ori[16];
  char temp[24];

  memset(ori, 0, sizeof ori);
  memset(temp, 0, sizeof temp);

  dec_to_bin(arr[0], ori);
  dec_to_bin(arr[1], ori + 8);

  copy(temp + 2, ori, 6);
  copy(temp + 10, ori + 6, 6);
  copy(temp + 18, ori + 12, 4);

  for (int i = 0; i < 3; ++i) {
    printf("%s", table[bin_to_dec(temp + i * 8)]);
  }
  printf("=");
}

void handle_one() {
  char ori[8];
  char temp[16];

  memset(ori, 0, sizeof ori);
  memset(temp, 0, sizeof temp);

  dec_to_bin(arr[0], ori);

  copy(temp + 2, ori, 6);
  copy(temp + 10, ori + 6, 2);

  for (int i = 0; i < 2; ++i) {
    printf("%s", table[bin_to_dec(temp + i * 8)]);
  }
  printf("==");
}

int main() {
  char c;
  while ((c = getchar()) != EOF) {
    if (total == 3) {
      handle_three();
      total = 0;
    }
    arr[total] = c;
    total++;
  }

  if (total == 3) {
    handle_three();
  } else if (total == 2) {
    handle_two();
  } else if (total == 1) {
    handle_one();
  }
}
```





## 单词计数

```c++
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int character = 0, word = 0, line = 0;
bool flag = true;

int main() {
  char c;
  while ((c = getchar()) != EOF) {
    switch (c) {
    case '\n':
      if (!flag) {
        word++;
        flag = true;
      }
      character++;
      line++;
      break;
    case ' ':
      if (!flag) {
        word++;
        flag = true;
      }
      character++;
      break;
    default:
      flag = false;
      character++;
    }
  }

  printf("%d %d %d\n", character, word, line);
}
```



## 螺旋打印矩阵

```c++
#include <cstdio>

#define MAXN 5050
static int arr[MAXN][MAXN];
static bool vis[MAXN][MAXN];
static int m, n;

enum { UP, DOWN, LEFT, RIGHT };

static int pos = RIGHT;
static int count = 0;
static int curr_x = 0, curr_y = 0;

int main() {
  std::scanf("%d%d", &m, &n);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      std::scanf("%d", &arr[i][j]);
      vis[i][j] = true;
    }
  }

  while (count < m * n) {
    if (curr_x < 0 || curr_y < 0 || !vis[curr_x][curr_y]) {
      switch (pos) {
      case RIGHT:
        curr_y--;
        curr_x++;
        pos = DOWN;
        break;
      case LEFT:
        curr_y++;
        curr_x--;
        pos = UP;
        break;
      case DOWN:
        curr_x--;
        curr_y--;
        pos = LEFT;
        break;
      case UP:
        curr_x++;
        curr_y++;
        pos = RIGHT;
        break;
      default:
        break;
      }
    }
    vis[curr_x][curr_y] = false;
    printf("%d ", arr[curr_x][curr_y]);
    count++;

    switch (pos) {
    case RIGHT:
      curr_y++;
      break;
    case LEFT:
      curr_y--;
      break;
    case DOWN:
      curr_x++;
      break;
    case UP:
      curr_x--;
      break;
    default:
      break;
    }
  }
}
```



## 旋转矩阵

```c++
#include <cstdio>

#define MAXN 5050
static int arr[MAXN][MAXN];
static int n;
static int deg;

int main() {
  std::scanf("%d%d", &n, &deg);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::scanf("%d", &arr[i][j]);
    }
  }
  deg = deg % 360;
  switch (deg) {
  case 0:
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::printf("%d ", arr[i][j]);
      }
      std::printf("\n");
    }
    break;
  case 90:
    for (int i = 0; i < n; ++i) {
      for (int j = n - 1; j >= 0; --j) {
        std::printf("%d ", arr[j][i]);
      }
      std::printf("\n");
    }
    break;
  case 180:
    for (int i = n - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        std::printf("%d ", arr[i][j]);
      }
      std::printf("\n");
    }
    break;
  case 270:
    for (int j = n - 1; j >= 0; --j) {
      for (int i = 0; i < n; ++i) {
        std::printf("%d ", arr[i][j]);
      }
      std::printf("\n");
    }
    break;
  default:
    break;
  }
}
```



## ArrayList

```c++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

static char cmd[20];
int operand;
int n;

struct MyArray {
  int *data{NULL};
  int size{};
  int capacity{};

  void add(int x) {
    if (capacity == 0) {
      capacity = 10;
      data = (int *)malloc(capacity * sizeof(int));
      data[size] = x;
      size++;
    } else {
      if (size == capacity) {
        capacity = capacity + (capacity >> 1);
        data = (int *)realloc(data, capacity * sizeof(int));
      }
      data[size] = x;
      size++;
    }
  }

  void remove(int x) {
    int index{-1};
    for (int i = 0; i < size; ++i) {
      if (data[i] == x) {
        index = i;
        break;
      }
    }
    if (index != -1) {
      for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
      }
      size--;
    }
  }

  int get(int i) {
    if (i < 0 || i >= size) {
      return -1;
    }
    return data[i];
  }

  int getSize() { return size; }

  int getCapacity() { return capacity; }

  void print() {
    if (size == 0) {
      printf("empty\n");
    } else {
      for (int i = 0; i < size; ++i) {
        printf("%d ", data[i]);
        printf("\n");
      }
    }
  }
};

MyArray arr;

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", cmd, &operand);
    if (!strcmp(cmd, "add")) {
      arr.add(operand);
    } else if (!strcmp(cmd, "remove")) {
      arr.remove(operand);
    } else if (!strcmp(cmd, "get")) {
      cout << arr.get(operand) << endl;
    } else if (!strcmp(cmd, "getSize")) {
      cout << arr.getSize() << endl;
    } else if (!strcmp(cmd, "getCapacity")) {
      cout << arr.getCapacity() << endl;
    } else {
    }
    // arr.print();
  }
}
```



## Z 形变换

```c++
#include <cstdio>
#include <iostream>
#include <string>

std::string str;
int n;
#define MAXN 25
static char arr[MAXN][MAXN];
int count = 0;
int curr_x = 0;
int curr_y = 0;

enum { UP, DOWN };
int pos = DOWN;

int main() {
  std::cin >> str >> n;

  if (n == 1) {
    std::cout << str;
    return 0;
  }

  while (count < str.length()) {
    switch (pos) {
    case DOWN:
      if (curr_x >= n) {
        curr_x -= 2;
        curr_y++;
        pos = UP;
      }
      break;
    case UP:
      if (curr_x <= 0) {
        curr_x = 0;
        curr_y++;
        pos = DOWN;
      }
      break;
    default:
      break;
    }

    arr[curr_x][curr_y] = str.at(count);
    count++;

    switch (pos) {
    case DOWN:
      curr_x++;
      break;
    case UP:
      curr_x--;
      break;
    default:
      break;
    }
  }

  for (int i = 0; i < MAXN; ++i) {
    for (int j = 0; j < MAXN; ++j) {
      if (arr[i][j] != 0) {
        std::printf("%c", arr[i][j]);
      } else {
        // std::printf(" ");
      }
    }
    // std::printf("\n");
  }
}
```



## BF 解释器

### 基本知识

可将 8 个指令分为两类：数据操纵指令和控制流指令。

数据操纵指令定义如下：

| 指令 | 含义                                               |
| :--- | :------------------------------------------------- |
| `>`  | 数据指针向右移动一个位置                           |
| `<`  | 数据指针向左移动一个位置                           |
| `+`  | 数据指针指向的字节的值加一                         |
| `-`  | 数据指针指向的字节的值减一                         |
| `,`  | 从输入流中读取一个字节，将其存入数据指针指向的位置 |
| `.`  | 将数据指针指向的字节写入输出流中                   |

上述指令均为顺序执行。对于 `,` 指令，如果遇到 `EOF`，应当将数据指针所指的字节的值改为 `0`

控制流包含两个：`[` 和 `]`，这类指令不会影响数据指针和数据指针指向的字节的值，只会影响下一条需要执行的指令。

| 指令 | 含义                                                         |
| :--- | :----------------------------------------------------------- |
| `[`  | 如果数据指针指向的单元值为 `0`，向后跳转到对应的 `]` 指令的下一条指令处 |
| `]`  | 如果数据指针指向的单元值不为 `0`，向前跳转到对应的 `[` 指令的下一条指令处 |



```c++
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

map<int, int> l_to_r{};
map<int, int> r_to_l{};
stack<int> temp_stack{};

#define log(format, ...) printf("\33[1;35m" format "\33[0m\n", ##__VA_ARGS__)

string cmd;
static int arr[1005];
int data_index = 0;
int cmd_index = 0;

int main() {
  string cmd;
  getline(cin, cmd);
  // cout << cmd << endl;

  for (size_t i = 0; i < cmd.length(); ++i) {
    char curr_cmd = cmd.at(i);
    if (curr_cmd == '[') {
      temp_stack.push(i);
    } else if (curr_cmd == ']') {
      assert(!temp_stack.empty());
      int j = temp_stack.top();
      temp_stack.pop();
      l_to_r.emplace(j, i);
      r_to_l.emplace(i, j);
    }
  }

  while (true) {
    if (cmd_index >= cmd.length()) {
      break;
    }

    char curr_cmd = cmd.at(cmd_index);
    // log("curr_cmd: %c", curr_cmd);

    switch (curr_cmd) {
    case ',': {
      char val;
      if (!cin.get(val)) {
        arr[data_index] = 0;
      } else {
        arr[data_index] = val;
      }
      cmd_index++;
      break;
    }
    case '.': {
      printf("%c", arr[data_index]);
      cmd_index++;
      break;
    }
    case '>': {
      data_index++;
      cmd_index++;
      break;
    }
    case '<': {
      data_index--;
      cmd_index++;
      break;
    }
    case '+': {
      arr[data_index]++;
      cmd_index++;
      break;
    }
    case '-': {
      arr[data_index]--;
      cmd_index++;
      break;
    }
    case '[': {
      if (arr[data_index] == 0) {
        auto search = l_to_r.find(cmd_index);
        if (search == l_to_r.end()) {
          assert(0);
        } else {
          cmd_index = search->second + 1;
        }
      } else {
        cmd_index++;
      }
      break;
    }
    case ']': {
      if (arr[data_index] != 0) {
        auto search = r_to_l.find(cmd_index);
        if (search == r_to_l.end()) {
          assert(0);
        } else {
          cmd_index = search->second + 1;
        }
      } else {
        cmd_index++;
      }
      break;
    }
    default:
      break;
    }
  }
}
```

先预处理指令



## 翻转链表

```c++
#include <cstdlib>
#include <cstdio>

typedef struct ListNode *List;

struct ListNode {
  List next;
  int elem;
};

List head = NULL;

int main() {
  int elem;
  while (scanf("%d", &elem) != EOF) {
    List node = (List)malloc(sizeof(struct ListNode));
    node->elem = elem;
    node->next = head;
    head = node;
  }

  List curr = head;
  while (curr) {
    printf("%d ", curr->elem);
    curr = curr->next;
  }
}
```



## 矩阵连乘

```c++
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
using namespace std;

/**
 * The Matrix type defines a common
 * interface for matrix operations.
 */
template <typename T> class Matrix {
protected:
  /**
   * TODO(P0): Add implementation
   *
   * Construct a new Matrix instance.
   * @param rows The number of rows
   * @param cols The number of columns
   *
   */
  Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
    linear_ = new T[static_cast<size_t>(rows * cols)];
  }

  /** The number of rows in the matrix */
  int rows_;
  /** The number of columns in the matrix */
  int cols_;

  /**
   * TODO(P0): Allocate the array in the constructor.
   * TODO(P0): Deallocate the array in the destructor.
   * A flattened array containing the elements of the matrix.
   */
  T *linear_;

public:
  /** @return The number of rows in the matrix */
  virtual int GetRowCount() const = 0;

  /** @return The number of columns in the matrix */
  virtual int GetColumnCount() const = 0;

  /**
   * Get the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @return The (i,j)th matrix element
   * @throws OUT_OF_RANGE if either index is out of range
   */
  virtual T GetElement(int i, int j) const = 0;

  /**
   * Set the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @param val The value to insert
   * @throws OUT_OF_RANGE if either index is out of range
   */
  virtual void SetElement(int i, int j, T val) = 0;

  /**
   * Fill the elements of the matrix from `source`.
   *
   * Throw OUT_OF_RANGE in the event that `source`
   * does not contain the required number of elements.
   *
   * @param source The source container
   * @throws OUT_OF_RANGE if `source` is incorrect size
   */
  virtual void FillFrom(const std::vector<T> &source) = 0;

  /**
   * Destroy a matrix instance.
   * TODO(P0): Add implementation
   */
  virtual ~Matrix() { delete[] linear_; }
};

/**
 * The RowMatrix type is a concrete matrix implementation.
 * It implements the interface defined by the Matrix type.
 */
template <typename T> class RowMatrix : public Matrix<T> {
public:
  /**
   * TODO(P0): Add implementation
   *
   * Construct a new RowMatrix instance.
   * @param rows The number of rows
   * @param cols The number of columns
   */
  RowMatrix(int rows, int cols) : Matrix<T>(rows, cols) {
    data_ = new T *[rows];
    for (int i = 0; i < rows; ++i) {
      data_[i] = this->linear_ + i * cols;
    }
  }

  /**
   * TODO(P0): Add implementation
   * @return The number of rows in the matrix
   */
  int GetRowCount() const override { return this->rows_; }

  /**
   * TODO(P0): Add implementation
   * @return The number of columns in the matrix
   */
  int GetColumnCount() const override { return this->cols_; }

  /**
   * TODO(P0): Add implementation
   *
   * Get the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @return The (i,j)th matrix element
   * @throws OUT_OF_RANGE if either index is out of range
   */
  T GetElement(int i, int j) const override {
    if (i >= this->rows_ || j >= this->cols_ || i < 0 || j < 0) {
      throw std::out_of_range("Index out of range.");
    }
    return data_[i][j];
  }

  /**
   * Set the (i,j)th matrix element.
   *
   * Throw OUT_OF_RANGE if either index is out of range.
   *
   * @param i The row index
   * @param j The column index
   * @param val The value to insert
   * @throws OUT_OF_RANGE if either index is out of range
   */
  void SetElement(int i, int j, T val) override {
    if (i >= this->rows_ || j >= this->cols_ || i < 0 || j < 0) {
      throw std::out_of_range("Index out of range.");
    }
    data_[i][j] = val;
  }

  /**
   * TODO(P0): Add implementation
   *
   * Fill the elements of the matrix from `source`.
   *
   * Throw OUT_OF_RANGE in the event that `source`
   * does not contain the required number of elements.
   *
   * @param source The source container
   * @throws OUT_OF_RANGE if `source` is incorrect size
   */
  void FillFrom(const std::vector<T> &source) override {
    int number = source.size();
    if (number != (this->rows_ * this->cols_)) {
      throw std::out_of_range("Source is incorrect size.");
    }
    for (int i = 0; i < number; ++i) {
      this->linear_[i] = source.at(i);
    }
  }

  /**
   * TODO(P0): Add implementation
   *
   * Destroy a RowMatrix instance.
   */
  ~RowMatrix() override { delete[] data_; }

private:
  /**
   * A 2D array containing the elements of the matrix in row-major format.
   *
   * TODO(P0):
   * - Allocate the array of row pointers in the constructor.
   * - Use these pointers to point to corresponding elements of the `linear`
   * array.
   * - Don't forget to deallocate the array in the destructor.
   */
  T **data_;
};

/**
 * The RowMatrixOperations class defines operations
 * that may be performed on instances of `RowMatrix`.
 */
template <typename T> class RowMatrixOperations {
public:
  /**
   * Compute (`matrixA` + `matrixB`) and return the result.
   * Return `nullptr` if dimensions mismatch for input matrices.
   * @param matrixA Input matrix
   * @param matrixB Input matrix
   * @return The result of matrix addition
   */
  static std::unique_ptr<RowMatrix<T>> Add(const RowMatrix<T> *matrixA,
                                           const RowMatrix<T> *matrixB) {
    // TODO(P0): Add implementation

    int col_a = matrixA->GetColumnCount();
    int col_b = matrixB->GetColumnCount();
    int row_a = matrixA->GetRowCount();
    int row_b = matrixB->GetRowCount();

    if (col_a != col_b || row_a != row_b) {
      return nullptr;
    }

    std::unique_ptr<RowMatrix<T>> res =
        std::make_unique<RowMatrix<T>>(row_a, col_a);
    for (int i = 0; i < row_a; ++i) {
      for (int j = 0; j < col_a; ++j) {
        T val = matrixA->GetElement(i, j) + matrixB->GetElement(i, j);
        res->SetElement(i, j, val);
      }
    }

    return res;
  }

  /**
   * Compute the matrix multiplication (`matrixA` * `matrixB` and return the
   * result. Return `nullptr` if dimensions mismatch for input matrices.
   * @param matrixA Input matrix
   * @param matrixB Input matrix
   * @return The result of matrix multiplication
   */
  static std::unique_ptr<RowMatrix<T>> Multiply(const RowMatrix<T> *matrixA,
                                                const RowMatrix<T> *matrixB) {
    // TODO(P0): Add implementation

    int col_a = matrixA->GetColumnCount();
    int col_b = matrixB->GetColumnCount();
    int row_a = matrixA->GetRowCount();
    int row_b = matrixB->GetRowCount();

    if (col_a != row_b) {
      return nullptr;
    }

    std::unique_ptr<RowMatrix<T>> res =
        std::make_unique<RowMatrix<T>>(row_a, col_b);
    for (int i = 0; i < row_a; ++i) {
      for (int j = 0; j < col_b; ++j) {
        T val{};
        for (int k = 0; k < col_a; ++k) {
          val += matrixA->GetElement(i, k) * matrixB->GetElement(k, j);
        }
        res->SetElement(i, j, val);
      }
    }

    return res;
  }
};

vector<unique_ptr<RowMatrix<int>>> matrixs{};

int main() {
  size_t n, col, row;
  int elem;
  vector<int> source;
  cin >> n;
  for (size_t i = 0; i < n; ++i) {
    source.clear();
    cin >> row >> col;
    for (size_t i = 0; i < col * row; ++i) {
      cin >> elem;
      source.push_back(elem);
    }
    auto matrix = std::make_unique<RowMatrix<int>>(row, col);
    matrix->FillFrom(source);
    matrixs.push_back(std::move(matrix));
  }

  std::unique_ptr<RowMatrix<int>> res;

  for (size_t i = 0; i < matrixs.size() - 1; ++i) {
    if (i == 0) {
      res = RowMatrixOperations<int>::Multiply(matrixs.at(0).get(),
                                               matrixs.at(1).get());
    } else {
      res = RowMatrixOperations<int>::Multiply(res.get(),
                                               matrixs.at(i + 1).get());
    }
  }

  row = res->GetRowCount();
  col = res->GetColumnCount();

  for (size_t i = 0; i < row; ++i) {
    for (size_t j = 0; j < col; ++j) {
      cout << res->GetElement(i, j) << " ";
    }
    cout << endl;
  }
}
```





## sort

```c++
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

size_t n, c;
vector<string> arr{};

int main() {
  cin >> n;
  cin >> ws;
  for (size_t i = 0; i < n; ++i) {
    string s;
    getline(cin, s);
    arr.push_back(s);
  }

  cin >> c;
  char cmd;
  for (size_t i = 0; i < c; ++i) {
    cin >> cmd;
    switch (cmd) {
    case '-':
      sort(arr.begin(), arr.end());
      break;
    case 'n':
      sort(arr.begin(), arr.end(),
           [](string x, string y) { return stoi(x) < stoi(y); });
      break;
    case 'd':
      sort(arr.begin(), arr.end(), [](string x, string y) {
        string s{}, t{};
        for (size_t i = 0; i < x.length(); ++i) {
          char c = x.at(i);
          if (isdigit(c) || isalpha(c) || c == ' ') {
            s += c;
          }
        }

        for (size_t i = 0; i < y.length(); ++i) {
          char c = y.at(i);
          if (isdigit(c) || isalpha(c) || c == ' ') {
            t += c;
          }
        }

        return s < t;
      });
      break;
    case 'i':
      sort(arr.begin(), arr.end(), [](string x, string y) {
        string s, t;
        transform(x.begin(), x.end(), s.begin(), ::tolower);
        transform(y.begin(), y.end(), t.begin(), ::tolower);
        if (x == y) {
          return s < t;
        } else {
          return x < y;
        }
      });
      break;
    case 'r':
      sort(arr.begin(), arr.end());
      reverse(arr.begin(), arr.end());
      break;
    default:
      break;
    }

    for (auto &s : arr) {
      cout << s << endl;
    }
  }
}
```



## 双端队列

```c++
#include <cstdio>
#include <cstdlib>
#include <cstring>

struct Node {
  Node *next;
  Node *prev;
  int val;
};

struct Deque {
  int size;
  Node *front;
  Node *rear;
};

void push_front(Deque *self, int value);
void push_back(Deque *self, int value);
void pop_front(Deque *self);
void pop_back(Deque *self);

static char cmd[20];
int operand;
int n;

int main() {
  struct Deque deque;
  deque.size = 0;
  deque.front = (Node *)malloc(sizeof(struct Node));
  deque.rear = (Node *)malloc(sizeof(struct Node));
  deque.rear->prev = deque.front;
  deque.rear->next = NULL;
  deque.front->next = deque.rear;
  deque.front->prev = NULL;

  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s%d", cmd, &operand);
    if (!strcmp(cmd, "pushFront")) {
      Node *node = (Node *)malloc(sizeof(struct Node));
      node->val = operand;

      node->next = deque.front->next;
      deque.front->next->prev = node;
      deque.front->next = node;
      node->prev = deque.front;

      deque.size++;
    } else if (!strcmp(cmd, "pushBack")) {
      Node *node = (Node *)malloc(sizeof(struct Node));
      node->val = operand;

      node->prev = deque.rear->prev;
      deque.rear->prev->next = node;
      deque.rear->prev = node;
      node->next = deque.rear;

      deque.size++;
    } else if (!strcmp(cmd, "popFront")) {
      if (deque.size == 0) {
        printf("-1\n");
      } else {
        printf("%d\n", deque.front->next->val);

        deque.front->next = deque.front->next->next;
        deque.front->next->prev = deque.front;

        deque.size--;
      }
    } else if (!strcmp(cmd, "popBack")) {
      if (deque.size == 0) {
        printf("-1\n");
      } else {
        printf("%d\n", deque.rear->prev->val);

        deque.rear->prev = deque.rear->prev->prev;
        deque.rear->prev->next = deque.rear;

        deque.size--;
      }
    } else if (!strcmp(cmd, "getSize")) {
      printf("%d\n", deque.size);
    } else {
    }
  }
}
```



## HashDict

```c++
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<long long, string> record{};

struct Entry {
  unsigned long long size{};
  int key;
  string value;
  struct Entry *next;
};

struct HashDict {
  unsigned long long table_size{};
  Entry **table{};

  void init(unsigned long long size) {
    table = (Entry **)malloc(size * sizeof(struct Entry *));
    table_size = size;
    for (unsigned long long i = 0; i < size; ++i) {
      table[i] = (Entry *)malloc(sizeof(struct Entry));
      table[i]->size = 0;
      table[i]->next = NULL;
    }
  }

  void clear() {
    for (unsigned long long i = 0; i < table_size; ++i) {
      Entry *curr = table[i];
      while (curr) {
        curr->size = 0;
        curr->key = 0;
        // curr->value.clear();
        Entry *tmp = curr;
        curr = curr->next;
        free(tmp);
        tmp = NULL;
      }
      table[i] = NULL;
    }
    free(table);
    table = NULL;
  }

  unsigned long long table_hash(long long key) {
    return std::llabs(3 * key * key * key + 5 * key * key + 7 * key + 11);
  }

  void add(long long key, string value) {
    record.emplace(key, value);

    unsigned long long pos = table_hash(key) % table_size;
    Entry *curr = table[pos]->next;
    Entry *prev = table[pos];

    while (curr) {
      if (curr->key > key) {
        break;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }

    Entry *node = (Entry *)malloc(sizeof(struct Entry));
    node->key = key;
    node->value = value;
    node->next = curr;
    prev->next = node;

    table[pos]->size++;

    if (record.size() > table_size || table[pos]->size > 4) {
      rehash();
    }
  }

  void remove(long long key) {
    record.erase(key);

    unsigned long long pos = table_hash(key) % table_size;
    Entry *curr = table[pos]->next;
    Entry *prev = table[pos];

    while (curr) {
      if (curr->key == key) {
        break;
      } else {
        prev = curr;
        curr = curr->next;
      }
    }

    prev->next = curr->next;
    free(curr);

    table[pos]->size--;
  }

  void print(unsigned long long pos) {
    Entry *curr = table[pos]->next;
    if (curr == NULL) {
      cout << "null" << endl;
    } else {
      while (curr) {
        cout << curr->key << ":" << curr->value;
        if (curr->next) {
          cout << "->";
        }
        curr = curr->next;
      }
      cout << endl;
    }
  }

  void rehash() {
    clear();
    table_size = table_size * 2 + 1;
    init(table_size);

    for (auto &[k, v] : record) {
      add(k, v);
    }
  }
};

long long k;
string v, cmd;
size_t i, n;
unsigned long long pos;

int main() {
  HashDict dict;
  cin >> i;
  dict.init(i);

  cin >> n;
  for (size_t i = 0; i < n; ++i) {
    cin >> cmd;
    if (cmd == "add") {
      cin >> k >> v;
      dict.add(k, v);
    } else if (cmd == "delete") {
      cin >> k;
      dict.remove(k);
    } else if (cmd == "search") {
      cin >> pos;
      dict.print(pos);
    }
  }
}
```

23/25



## 铁匠铸造

```c++
#include <climits>
#include <cstdio>
#include <cstring>

#define MAX_WORKER 1000
#define MAX_LIST 1000
#define MAX_ORDER 100000

int num;
int limit;
int N;

static struct Worker {
  int uid;
  int type;

  int order_id;
  int order_index;
  int avai_time;

  int finish_order_list[MAX_LIST];
  int finish_order_list_index;
} workers[MAX_WORKER];

enum { PENDING = 0, DONE, DOING, DISCARDED };

static struct Order {
  int oid;
  int priority;
  int order_time;
  int type;
  int state;
} orders[MAX_ORDER];

static char cmd[128];
int oid, priority, order_time, type, uid;

static int curr_order_index;
static int pending_orders_count;

void add_order(int oid, int priority, int order_time, int type) {
  if (pending_orders_count == limit) {
    int target_priority = INT_MAX;
    int target_index = -1;
    for (int i = 0; i < curr_order_index; ++i) {
      if (orders[i].priority < target_priority && orders[i].state == PENDING) {
        target_priority = orders[i].priority;
        target_index = i;
      }
    }

    orders[target_index].state = DISCARDED;

    orders[curr_order_index].oid = oid;
    orders[curr_order_index].priority = priority;
    orders[curr_order_index].order_time = order_time;
    orders[curr_order_index].type = type;
    orders[curr_order_index].state = PENDING;

    curr_order_index++;
  } else {
    orders[curr_order_index].oid = oid;
    orders[curr_order_index].priority = priority;
    orders[curr_order_index].order_time = order_time;
    orders[curr_order_index].type = type;
    orders[curr_order_index].state = PENDING;

    pending_orders_count++;
    curr_order_index++;
  }
}

void queryUser(int uid) {
  for (int i = 0; i < num; ++i) {
    if (workers[i].uid == uid) {
      if (workers[i].avai_time == -1) {
        printf("worker %d resting\n", uid);
      } else {
        printf("worker %d doing order %d\n", uid, workers[i].order_id);
      }
    }
  }
}

void queryOrder(int oid) {
  for (int i = 0; i < curr_order_index; ++i) {
    if (orders[i].oid == oid) {
      switch (orders[i].state) {
        case PENDING:
          printf("order %d pending\n", oid);
          break;
        case DONE:
          printf("order %d done\n", oid);
          break;
        case DOING:
          printf("order %d doing\n", oid);
          break;
        case DISCARDED:
          printf("order %d discarded\n", oid);
          break;
      }
    }
  }
}

void queryOrders(int uid) {
  for (int i = 0; i < num; ++i) {
    if (workers[i].uid == uid) {
      for (int j = 0; j < workers[i].finish_order_list_index; ++j) {
        printf("%d ", workers[i].finish_order_list[j]);
      }
    }
  }
  printf("\n");
}

int select_order(int type) {
  int target_priority = INT_MIN;
  int target_index = -1;

  for (int i = 0; i < curr_order_index; ++i) {
    Order target_order = orders[i];
    if (target_order.state == PENDING && target_order.type == type &&
        target_order.priority > target_priority) {
      target_priority = target_order.priority;
      target_index = i;
    }
  }

  return target_index;
}

void logic(int curr_time) {
  if (curr_time == 0) {
    return;
  }

  for (int i = 0; i < num; ++i) {
    if (workers[i].avai_time == curr_time || workers[i].avai_time == -1) {
      if (workers[i].avai_time == curr_time) {
        workers[i].finish_order_list[workers[i].finish_order_list_index] =
            workers[i].order_id;
        workers[i].finish_order_list_index++;

        orders[workers[i].order_index].state = DONE;  // intro order_index
      }

      int order_index = select_order(workers[i].type);
      if (order_index != -1) {
        workers[i].avai_time = curr_time + orders[order_index].order_time;
        workers[i].order_id = orders[order_index].oid;
        workers[i].order_index = order_index;

        orders[order_index].state = DOING;
        pending_orders_count--;
      } else {
        workers[i].avai_time = -1;
        workers[i].order_id = -1;
        workers[i].order_index = -1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &num, &limit);
  for (int i = 0; i < num; ++i) {
    scanf("%d %d", &workers[i].uid, &workers[i].type);
    workers[i].order_id = -1;
    workers[i].avai_time = -1;
    workers[i].order_index = -1;
  }
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    logic(i);

    scanf("%s", cmd);
    if (!strcmp(cmd, "add")) {
      scanf("%d %d %d %d", &oid, &priority, &order_time, &type);
      // printf("%d %d %d %d\n", oid, priority, order_time, type);
      add_order(oid, priority, order_time, type);
    } else if (!strcmp(cmd, "queryUser")) {
      scanf("%d", &uid);
      // printf("%d\n", uid);
      queryUser(uid);
    } else if (!strcmp(cmd, "queryOrder")) {
      scanf("%d", &oid);
      // printf("%d\n", oid);
      queryOrder(oid);
    } else if (!strcmp(cmd, "queryOrders")) {
      scanf("%d", &uid);
      // printf("%d\n", uid);
      queryOrders(uid);
    }
  }
}
```





## My_Container

```c++
#include <cstdlib>
#include <cstring>
#include <iostream>

class MyContainer {
public:
  MyContainer(int size) : _size(size) {
    // TODO
    _data = new int[_size]();
    _count++;
  }

  ~MyContainer() {
    // TODO
    delete[] _data;
    _count--;
  }

  MyContainer(const MyContainer &Other) {
    // TODO
    _size = Other._size;
    _data = new int[_size]();
    memcpy(_data, Other._data, _size * sizeof(int));
    _count++;
  }

  MyContainer &operator=(const MyContainer &Other) {
    // TODO
    if (this->_data != Other._data) {
      auto new_data = new int[_size]();
      memcpy(new_data, Other._data, _size * sizeof(int));
      delete[] _data;
      _data = new_data;
      _size = Other._size;
      return *this;
      _count++;
    }
    return *this;
  }

  int size() const { return _size; }

  int *data() const { return _data; }

  static int count() { return _count; }

  static int _count;

private:
  // C++11 引入的 initializer_list
  int *_data{nullptr};
  int _size{0};
};

int MyContainer::_count = 0;

void test1() {
  MyContainer m(5);
  std::cout << m.count() << std::endl;

  MyContainer m2(m);
  std::cout << m2.count() << std::endl;

  MyContainer m3 = m2;
  std::cout << m3.count() << std::endl;
}

void test2() {
  MyContainer m1(5);
  std::cout << m1.count() << std::endl;

  MyContainer m2 = m1;
  std::cout << m2.count() << std::endl;
  std::cout << (m2.data() == m1.data()) << std::endl;
}

void test3() {
  MyContainer m1(3);
  std::cout << m1.count() << std::endl;

  MyContainer m2 = m1;
  std::cout << m2.count() << std::endl;
  std::cout << (m2.data() == m1.data()) << std::endl;

  m1 = m2;
  std::cout << m1.count() << std::endl;
  std::cout << (m2.data() == m1.data()) << std::endl;

  m2 = m1;
  std::cout << m2.count() << std::endl;
  std::cout << (m2.data() == m1.data()) << std::endl;

  int *prev_ptr = m1.data();
  m1 = m1;
  std::cout << m1.count() << std::endl;
  std::cout << (m1.data() == prev_ptr) << std::endl;
}

void test4() {
  MyContainer m1(3);
  std::cout << m1.count() << std::endl;

  {
    MyContainer m2 = m1;
    std::cout << m2.count() << std::endl;
    std::cout << (m2.data() == m1.data()) << std::endl;

    m1 = m2;
    std::cout << m1.count() << std::endl;
    std::cout << (m2.data() == m1.data()) << std::endl;

    m2 = m1;
    std::cout << m2.count() << std::endl;
    std::cout << (m2.data() == m1.data()) << std::endl;
  }

  std::cout << m1.count() << std::endl;
}

int main() {
  test1();
  test2();
  test3();
  test4();
  return 0;
}
```



## Shared_Container

```c
#include <cassert>
#include <iostream>
#include <map>
#include <utility>

class Content {
public:
  explicit Content(int id) : id(id) {
    std::cout << "create " << std::to_string(id) << std::endl;
  }

  ~Content() { std::cout << "destroy " << std::to_string(id) << std::endl; }

private:
  int id{-1};
  char data[1024]{};
};

class SharedContainer {
public:
  // TODO
  explicit SharedContainer(int mem_id) {
    auto search = _map.find(mem_id);
    if (search != _map.end()) {
      _data = search->second.first;
      _map[mem_id].second++;
      _id = mem_id;
    } else {
      _data = new Content{mem_id};
      _map.emplace(mem_id, std::make_pair(_data, 1));
      _id = mem_id;
    }
  }
  // TODO
  ~SharedContainer() {
    auto search = _map.find(_id);
    assert(search != _map.end());
    if (search->second.second == 1) {
      search->second.first->~Content();
      _map.erase(_id);
    } else {
      _map[_id].second--;
    }
  }
  // TODO
  SharedContainer(const SharedContainer &other) {
    auto search = _map.find(other._id);
    assert(search != _map.end());
    this->_data = _map[_id].first;
    this->_id = other._id;
    _map[_id].second++;
  }
  // TODO
  SharedContainer &operator=(const SharedContainer &other) {
    if (this->_data == other._data) {
      return *this;
    }

    int mem_id_lhs = this->_id;
    int mem_id_rhs = other._id;
    assert(mem_id_lhs != mem_id_rhs);

    {
      auto search = _map.find(mem_id_lhs);
      assert(search != _map.end());
      if (_map[mem_id_lhs].second == 1) {
        search->second.first->~Content();
        _map.erase(mem_id_lhs);
      } else {
        _map[mem_id_lhs].second--;
      }
    }

    {
      auto search = _map.find(mem_id_rhs);
      assert(search != _map.end());
      _map[mem_id_rhs].second++;
      this->_data = _map[mem_id_rhs].first;
      this->_id = mem_id_rhs;
    }

    return *this;
  }
  // TODO
  int get_count() const {
    auto search = _map.find(_id);
    if (search->first) {
      return search->second.second;
    } else {
      return 0;
    }
  }

  SharedContainer(const SharedContainer &&) = delete;
  SharedContainer &operator=(const SharedContainer &&) = delete;

  static std::map<int, std::pair<Content *, int>> _map;

private:
  Content *_data{nullptr};
  int _id{-1};
  // TODO: design your own reference counting mechanism
};

std::map<int, std::pair<Content *, int>> SharedContainer::_map{};

void test1() {
  SharedContainer m1(1);
  SharedContainer m2 = m1;
  SharedContainer m3(m2);
  std::cout << m1.get_count() << std::endl;
  std::cout << m2.get_count() << std::endl;
  std::cout << m3.get_count() << std::endl;
}

void test2() {
  SharedContainer m1(1);
  SharedContainer m2 = m1;
  m1 = m1;
  {
    SharedContainer m3 = m1;
    std::cout << m1.get_count() << std::endl;
  }
  std::cout << m1.get_count() << std::endl;
  std::cout << m2.get_count() << std::endl;
}

void test3() {
  SharedContainer m1(1);
  SharedContainer m2(2);
  m1 = m2;
  std::cout << m1.get_count() << std::endl;
  std::cout << m2.get_count() << std::endl;
  {
    SharedContainer m3(3);
    m1 = m3;
    std::cout << m1.get_count() << std::endl;
    std::cout << m2.get_count() << std::endl;
    std::cout << m3.get_count() << std::endl;
  }
  std::cout << m1.get_count() << std::endl;
  std::cout << m2.get_count() << std::endl;
}

int main() {
  test1();
  test2();
  test3();
  return 0;
}
```





## Memory_Context

```c++
#include <cassert>
#include <functional>
#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// 除了 TODO 标出的部分，不要修改原有的声明和定义，否则后果自负！

class MemoryContext {
public:
  /**
   * @param parent 父节点，可能为 nullptr
   */
  MemoryContext(MemoryContext *parent);

  ~MemoryContext();

  // 禁止拷贝和移动
  MemoryContext(const MemoryContext &) = delete;
  MemoryContext &operator=(const MemoryContext &) = delete;
  MemoryContext(MemoryContext &&) = delete;
  MemoryContext &operator=(MemoryContext &&) = delete;

  using chunk_id_t = std::string;

  void alloc(const chunk_id_t &chunk_id);

private:
  // TODO: your code
  MemoryContext *parent;
  std::vector<MemoryContext *> children{};
  std::vector<chunk_id_t> chunks{};
};

MemoryContext::MemoryContext(MemoryContext *parent) {
  // TODO: your code
  this->parent = parent;
  if (parent != nullptr) {
    parent->children.push_back(this);
  }
}

MemoryContext::~MemoryContext() {
  // TODO: your code
  for (MemoryContext *mc : children) {
    mc->~MemoryContext();
  }
  for (auto it = chunks.rbegin(); it != chunks.rend(); ++it) {
    std::cout << "Chunk " << *it << " freed." << std::endl;
  }
}

void MemoryContext::alloc(const chunk_id_t &chunk_id) {
  // TODO: your code
  this->chunks.emplace_back(chunk_id);
}

void test_1() {
  std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
  A->alloc("1");
  A->alloc("2");
  A->alloc("3");
}

void test_2() {
  std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
  MemoryContext *B = new MemoryContext(A.get());
  MemoryContext *C = new MemoryContext(B);

  A->alloc("1");
  A->alloc("2");
  A->alloc("3");
  B->alloc("1/1");
  B->alloc("1/2");
  B->alloc("1/3");
  C->alloc("1/1/1");
  C->alloc("1/1/2");
  C->alloc("1/1/3");
}

void test_3() {
  std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
  MemoryContext *B = new MemoryContext(A.get());
  MemoryContext *C = new MemoryContext(A.get());
  MemoryContext *D = new MemoryContext(B);
  MemoryContext *E = new MemoryContext(C);
  MemoryContext *F = new MemoryContext(C);
  MemoryContext *G = new MemoryContext(E);

  A->alloc("1");
  A->alloc("2");
  A->alloc("3");
  B->alloc("1/1");
  C->alloc("1/2");
  D->alloc("1/1/1");
  D->alloc("1/1/2");
  G->alloc("1/2/1/1");
}

void test_4() {
  std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
  MemoryContext *B = new MemoryContext(A.get());
  MemoryContext *C = new MemoryContext(A.get());
  MemoryContext *D = new MemoryContext(B);
  MemoryContext *E = new MemoryContext(B);
  MemoryContext *F = new MemoryContext(C);
  MemoryContext *G = new MemoryContext(C);

  A->alloc("1");
  A->alloc("2");
  A->alloc("3");
  B->alloc("1/1");
  C->alloc("1/2");
  D->alloc("1/1/1");
  D->alloc("1/1/3");
  E->alloc("1/1/2");
  F->alloc("1/2/1");
  G->alloc("1/2/3");
  G->alloc("1/2/5");
  G->alloc("1/2/2");
  G->alloc("1/2/4");
}

void test_5() {
  std::unique_ptr<MemoryContext> A = std::make_unique<MemoryContext>(nullptr);
  MemoryContext *B = new MemoryContext(A.get());
  MemoryContext *C = new MemoryContext(A.get());
  MemoryContext *D = new MemoryContext(B);
  MemoryContext *G = new MemoryContext(C);

  A->alloc("2");
  A->alloc("1");
  A->alloc("3");
  A->alloc("4");
  B->alloc("2/1");
  B->alloc("3/5");
  C->alloc("1024/2");
  C->alloc("1024/1");
  G->alloc("8192/1/4095");
}

#define REGISTER_TEST_CASE(name)                                               \
  { #name, name }

int main() {
  std::unordered_map<std::string, std::function<void()>>
      test_functions_by_name = {
          REGISTER_TEST_CASE(test_1), REGISTER_TEST_CASE(test_2),
          REGISTER_TEST_CASE(test_3), REGISTER_TEST_CASE(test_4),
          REGISTER_TEST_CASE(test_5),
      };

  std::string test_case_name;
  std::cin >> test_case_name;
  auto it = test_functions_by_name.find(test_case_name);
  assert(it != test_functions_by_name.end());
  auto fn = it->second;
  fn();
}
```



## XO

```c++
#include <cstdio>

#define MAXN 5050

enum ChessPiece {
  _,
  X,
  O,
};

enum Result {
  DRAW,
  X_WIN,
  O_WIN,
  GAMING,
};

static struct ChessBoard {
  int n{};
  int m{};
  int pieces_count{};

  ChessPiece board[MAXN][MAXN]{};

  void place_o(int x, int y) {
    board[x][y] = O;
    pieces_count++;
  }

  void place_x(int x, int y) {
    board[x][y] = X;
    pieces_count++;
  }

  Result check() {
    if (check_horizontal(O) || check_vertical(O) || check_main_diagonal(O) ||
        check_counter_diagonal(O)) {
      return O_WIN;
    }

    if (check_horizontal(X) || check_vertical(X) || check_main_diagonal(X) ||
        check_counter_diagonal(X)) {
      return X_WIN;
    }

    if (pieces_count == n * n) {
      return DRAW;
    }

    return GAMING;
  }

  bool check_horizontal(ChessPiece piece) {
    for (int i = 0; i <= n - 1; ++i) {
      for (int j = 0; j <= n - m; ++j) {
        bool res = true;
        for (int k = 0; k <= m - 1; ++k) {
          res &= (board[i][j + k] == piece);
        }
        if (res) {
          return true;
        }
      }
    }
    return false;
  }

  bool check_vertical(ChessPiece piece) {
    for (int i = 0; i <= n - 1; ++i) {
      for (int j = 0; j <= n - m; ++j) {
        bool res = true;
        for (int k = 0; k <= m - 1; ++k) {
          res &= (board[j + k][i] == piece);
        }
        if (res) {
          return true;
        }
      }
    }
    return false;
  }

  bool check_main_diagonal(ChessPiece piece) {
    for (int sum = m - 1; sum <= n - 1; ++sum) { // x + y
      int x = 0;
      int y = sum;
      int count = 0;
      do {
        bool res = true;
        for (int k = 0; k <= m - 1; ++k) {
          res &= (board[x + k][y - k] == piece);
        }
        if (res) {
          return true;
        }
        count++;
        x++;
        y--;
      } while (count <= sum - (m - 1));
    }

    for (int sum = n; sum <= n + m; ++sum) {
      int x = sum - (n - 1);
      int y = n - 1;
      int count = 0;
      do {
        bool res = true;
        for (int k = 0; k <= m - 1; ++k) {
          res &= (board[x + k][y - k] == piece);
        }
        if (res) {
          return true;
        }
        count++;
        x++;
        y--;
      } while (count <= (m + n) - sum);
    }

    return false;
  }

  bool check_counter_diagonal(ChessPiece piece) {
    for (int sub = n - m; sub >= 0; --sub) { // y - x
      int x = 0;
      int y = sub;
      int count = 0;
      do {
        bool res = true;
        for (int k = 0; k <= m - 1; ++k) {
          res &= (board[x + k][y + k] == piece);
        }
        if (res) {
          return true;
        }
        count++;
        x++;
        y++;
      } while (count <= (n - m) - sub);
    }

    for (int sub = 1; sub <= n - m; ++sub) { // x - y
      int x = sub;
      int y = 0;
      int count = 0;
      do {
        bool res = true;
        for (int k = 0; k <= m - 1; ++k) {
          res &= (board[x + k][y + k] == piece);
        }
        if (res) {
          return true;
        }
        count++;
        x++;
        y++;
      } while (count <= (n - m) - sub);
    }

    return false;
  }

} chess_board;

int x, y;
Result result;

int main() {
  scanf("%d %d", &chess_board.n, &chess_board.m);
  for (int i = 0;; ++i) {
    scanf("%d %d", &x, &y);
    (i % 2 == 0) ? chess_board.place_o(x, y) : chess_board.place_x(x, y);
    result = chess_board.check();
    if (result != GAMING) {
      break;
    }
  }
  switch (result) {
  case X_WIN:
    printf("X Success");
    break;
  case O_WIN:
    printf("O Success");
    break;
  case DRAW:
    printf("Dogfall");
    break;
  default:
    break;
  }
}
```







## UI_Design

```c++
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

struct RGB {
  int r, g, b;
};

std::ostream &operator<<(std::ostream &os, const RGB &rgb) {
  return os << rgb.r << " " << rgb.g << " " << rgb.b;
}

struct Rectangle {
  std::string id;
  RGB rgb;

  Rectangle(std::string _id) : id{_id}, rgb{0, 0, 0} {}
  double calculate_gray() const {
    return rgb.r * 0.299 + rgb.g * 0.587 + rgb.b * 0.114;
  }
  virtual void setRGB(int r, int g, int b) { rgb = {r, g, b}; }
};

struct SingleRectangle : Rectangle {
  SingleRectangle(std::string _id) : Rectangle{_id} {}
  void setRGB(int r, int g, int b) override { rgb = {r, 0, 0}; }
};

struct ReverseRectangle : Rectangle {
  ReverseRectangle(std::string _id) : Rectangle{_id} {}
  void setRGB(int r, int g, int b) override {
    rgb = {255 - r, 255 - g, 255 - b};
  }
};

struct Cmp {
  bool operator()(std::string lhs, std::string rhs) const {
    assert(lhs[0] == 'P' && rhs[0] == 'P');
    std::size_t pos{};
    int lhs_index = std::stoi(lhs.substr(1), &pos);
    int rhs_index = std::stoi(rhs.substr(1), &pos);
    return lhs_index < rhs_index;
  }
} cmp;

std::map<std::string, std::shared_ptr<Rectangle>, Cmp> rectangles;
std::map<std::string, std::vector<std::shared_ptr<Rectangle>>> groups;

int logs, N, r, g, b;
std::string cmd, type, id;

int main() {
  std::cin >> logs;

  for (int i = 0; i < logs; ++i) {
    std::cin >> cmd;
    if (cmd == "Add") {
      std::cin >> type >> id;
      if (type == "normal") {
        rectangles.emplace(id, std::make_shared<Rectangle>(id));
      } else if (type == "single") {
        rectangles.emplace(id, std::make_shared<SingleRectangle>(id));
      } else if (type == "reverse") {
        rectangles.emplace(id, std::make_shared<ReverseRectangle>(id));
      }
    } else if (cmd == "Group") {
      std::cin >> N;
      std::vector<std::shared_ptr<Rectangle>> temp{};
      for (int j = 0; j < N; ++j) {
        std::cin >> id;
        temp.emplace_back(rectangles[id]);
      }
      std::cin >> id;
      groups.emplace(id, temp);
    } else if (cmd == "Set") {
      std::cin >> id >> r >> g >> b;
      if (id[0] == 'P') {
        rectangles[id]->setRGB(r, g, b);
      } else if (id[0] == 'G') {
        for (auto it = groups[id].begin(); it != groups[id].end(); ++it) {
          it->get()->setRGB(r, g, b);
        }
      }
    }
  }

  while (std::cin >> cmd) {
    if (cmd == "Normal") {
      for (auto it = rectangles.begin(); it != rectangles.end(); ++it) {
        std::cout << it->second->id << " " << it->second->rgb << std::endl;
      }
    } else if (cmd == "Gray") {
      std::vector<std::shared_ptr<Rectangle>> temp{};
      for (auto it = rectangles.begin(); it != rectangles.end(); ++it) {
        temp.emplace_back(it->second);
      }
      std::sort(temp.begin(), temp.end(),
                [](const std::shared_ptr<Rectangle> &lhs,
                   const std::shared_ptr<Rectangle> &rhs) {
                  double lhs_gray = lhs->calculate_gray();
                  double rhs_gray = rhs->calculate_gray();
                  if (std::abs(lhs_gray - rhs_gray) < 0.0001) {
                    return cmp(lhs->id, rhs->id);
                  }
                  return lhs_gray < rhs_gray;
                  ;
                });
      for (auto it = temp.begin(); it != temp.end(); ++it) {
        std::cout << it->get()->id << " " << it->get()->rgb << std::endl;
      }
    }
  }
}
```



## 植物大战僵尸

```c++
#include <iostream>
#include <string>
#include <vector>
#include <climits>

struct Plant;
struct Zombie;

Plant * plants[5][9];
std::vector<Zombie *> zombies;

struct Zombie {
  int x;
  int y;
  int hp;
  int atk;
  int speed;

  Zombie(int _x, int _hp, int _atk, int _speed) :
                                                  x{_x}, y{9}, hp{_hp}, atk{_atk}, speed{_speed} {}

  void move();
  void attack() const;
  [[nodiscard]] bool is_win() const {
    return y < 0;
  }
};

struct Plant {
  virtual bool minus_hp(int atk) = 0;
  virtual void attack(int x, int y) = 0;
  virtual bool is_potato() = 0;
};

struct Pea : Plant {
  int hp;
  int atk;

  Pea(int _hp, int _atk) : hp{_hp}, atk{_atk} {}

  bool is_potato() override {
    return false;
  }

  bool minus_hp(int atk) override {
    hp -= atk;
    if (hp <= 0) {
      return true;
    }
    return false;
  }

  void attack(int x, int y) override {
    int target_y = INT_MAX;

    for (auto & zombie : zombies) {
      if (zombie) {
        if (zombie->x == x && zombie->y >= y) {
          if (zombie->y < target_y) {
            target_y = zombie->y;
          }
        }
      }
    }

    if (target_y != INT_MAX) {
      for (auto & zombie : zombies) {
        if (zombie) {
          if (zombie->x == x && zombie->y == target_y) {
            zombie->hp -= atk;
            if (zombie->hp <= 0) {
              zombie = nullptr; // mem leak
            }
          }
        }
      }
    }
  }
};

struct Nut : Plant {
  int hp;

  explicit Nut(int _hp) : hp{_hp} {}

  bool is_potato() override {
    return false;
  }

  bool minus_hp(int atk) override {
    hp -= atk;
    if (hp <= 0) {
      return true;
    }
    return false;
  }

  void attack(int x, int y) override {

  }
};

struct Potato : Plant {
  bool ready{};
  int atk;

  explicit Potato(int _atk) : atk{_atk} {}

  bool is_potato() override {
    ready = true;
    return true;
  }

  bool minus_hp(int atk) override {
    return false;
  }

  void attack(int x, int y) override {
    if (ready) {
      for (auto & zombie : zombies) {
        if (zombie && zombie->y >= 0) {
          int dis_x = zombie->x - x;
          int dis_y = zombie->y - y;
          if (-1 <= dis_x && dis_x <= 1 && -1 <= dis_y && dis_y <= 1) {
            zombie->hp -= atk;
            if (zombie->hp <= 0) {
              zombie = nullptr; // mem leak
            }
          }
        }
      }
      plants[x][y] = nullptr; // mem leak
    }
  }
};

void Zombie::move() {
  int target_y = y;
  for (int i = 0; i <= speed; ++i) {
    target_y = y - i;
    if (target_y < 0) {
      break;
    }
    if (plants[x][target_y] && !plants[x][target_y]->is_potato()) {
      break;
    }
  }
  this->y = target_y;
}

void Zombie::attack() const {
  if (y >= 0 && plants[x][y]) {
    bool res = plants[x][y]->minus_hp(atk);
    if (res) {
      plants[x][y] = nullptr; // mem leak
    }
  }
}

int num_p, num_z;
int hp, atk, speed, x, y;
std::string p_name;

int curr_round = 1;
void logic() {
  while (true) {
    int plants_count = 0;
    int zombies_count = 0;
    bool zombies_win = false;

    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (plants[i][j]) {
          plants[i][j]->attack(i, j);
        }
      }
    }

    for (Zombie * zombie : zombies) {
      if (zombie) {
        zombie->move();
      }
    }

    for (Zombie * zombie : zombies) {
      if (zombie) {
        zombies_count++;
        zombie->attack();
        zombies_win |= zombie->is_win();
      }
    }

    for (int i = 0; i < 5; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (plants[i][j]) {
          plants_count++;
        }
      }
    }

    std::cout << curr_round++ << " " << plants_count << " " << zombies_count << std::endl;

    if (zombies_count == 0) {
      std::cout << "plants win" << std::endl;
      break;
    }

    if (zombies_win) {
      std::cout << "zombies win" << std::endl;
      break;
    }
  }
}

int main() {
  std::cin >> num_p >> num_z;
  for (int i = 0 ; i < num_p; ++i) {
    std::cin >> p_name;
    if (p_name == "pea") {
      std::cin >> hp >> atk >> x >> y;
      plants[x][y] = new Pea{hp, atk};
    } else if (p_name == "nut") {
      std::cin >> hp >> x >> y;
      plants[x][y] = new Nut{hp};
    } else if (p_name == "potato") {
      std::cin >> atk >> x >> y;
      plants[x][y] = new Potato{atk};
    }
  }
  for (int i = 0; i < num_z; ++i) {
    std::cin >> hp >> atk >> speed >> x;
    zombies.push_back(new Zombie{x, hp, atk, speed});
  }
  logic();
}
```

18/20



## 斐波那契数列

```c++
#include <cstdint>
#include <functional>
#include <iostream>
#include <unordered_map>

template <uintmax_t N>
struct Fib {
  static constexpr uintmax_t value = Fib<N - 1>::value + Fib<N - 2>::value;
};

template<>
struct Fib<1> {
  static constexpr uintmax_t value = 1;
};

template<>
struct Fib<0> {
  static constexpr uintmax_t value = 0;
};

// TODO: your code

void test_1() { std::cout << Fib<0>::value << std::endl; }

void test_2() { std::cout << Fib<1>::value << std::endl; }

void test_3() { std::cout << Fib<2>::value << std::endl; }

void test_4() { std::cout << Fib<5>::value << std::endl; }

void test_5() { std::cout << Fib<20>::value << std::endl; }

int main() {
  std::unordered_map<std::string, std::function<void()>> test_cases_by_name = {
      {"test_1", test_1}, {"test_2", test_2}, {"test_3", test_3},
      {"test_4", test_4}, {"test_5", test_5},
  };
  std::string tname;
  std::cin >> tname;
  auto it = test_cases_by_name.find(tname);
  if (it == test_cases_by_name.end()) {
    std::cout << "输入只能是 test_<N>，其中 <N> 可取整数 1 到 5." << std::endl;
    return 1;
  }
  (it->second)();
}
```



## 整数流

```c++
#include <functional>
#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

class IntStream {
 public:
  explicit IntStream(int first) {
    this->curr = first;
    this->has_end = false;
  }
  IntStream(int first, int last) {
    this->curr = first;
    this->last = last;
  }
  IntStream(int first, int last, int stride) {
    this->curr = first;
    this->last = last;
    this->step = stride;
  }

  IntStream &operator++() {
    curr += step;
    return *this;
  }

  IntStream operator++(int) {
    curr += step;
    return *this;
  }

  int operator*() const {
    return curr;
  }

  operator bool() const {
    if (!has_end) {
      return true;
    }
    if (step > 0) {
      return curr < last;
    }
    if (step < 0) {
      return curr > last;
    }
    return true;
  }

  // TODO: your code
 private:
  bool has_end{true};
  int curr;
  int last;
  int step{1};
};

void print_answer(const IntStream &s, int expect) {
  std::cout << std::boolalpha;
  if (s) {
    std::cout << (*s == expect) << ' ' << *s << std::endl;
  } else {
    std::cout << false << std::endl;
  }
}

/**
 * @brief 测试 IntStream(int)
 */
void test_1() {
  IntStream s(0);
  for (size_t i = 0; i < 10; i++) {
    ++s;
  }
  print_answer(s, 10);
}

/**
 * @brief 测试 IntStream(int, int)
 */
void test_2() {
  IntStream s(0, 10);
  for (size_t i = 0; i < 9; i++) {
    s++;
  }
  print_answer(s, 9);
}

/**
 * @brief 测试 IntStream(int, int, int) - 不考虑溢出
 */
void test_3() {
  IntStream s(0, 10, 2);
  for (size_t i = 0; i < 4; i++) {
    ++s;
  }
  print_answer(s, 8);
}

/**
 * @brief 测试 IntStream(int, int, int) - 步长为负数
 */
void test_4() {
  IntStream s(10, 0, -1);
  for (size_t i = 0; i < 10; i++) {
    s++;
  }
  print_answer(s, 0);
}

/**
 * @brief 测试 IntStream(int, int, int) - 考虑溢出，大于最大值
 */
void test_5() {
  IntStream s(std::numeric_limits<int>::max() - 10000,
              std::numeric_limits<int>::max(), 123);
  for (size_t i = 0; i < 50; i++) {
    ++s;
  }
  print_answer(s, 2147479797);
}

/**
 * @brief 测试 IntStream(int, int, int) - 考虑溢出，小于最小值
 */
void test_6() {
  IntStream s(std::numeric_limits<int>::min() + 10000,
              std::numeric_limits<int>::min(), -123);
  for (size_t i = 0; i < 50; i++) {
    s++;
  }
  print_answer(s, -2147479798);
}

/**
 * @brief 测试步长为 0 的情况
 */
void test_7() {
  IntStream s(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(),
              0);
  for (size_t i = 0; i < 10000; i++) {
    s++;
  }
  print_answer(s, std::numeric_limits<int>::min());
}

/**
 * @brief 测试范围 [first, last) 非常大的情况
 */
void test_8() {
  IntStream s(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
  for (size_t i = 0; i < 10000; i++) {
    s++;
  }
  print_answer(s, std::numeric_limits<int>::min() + 10000);
}

int main() {
  std::unordered_map<std::string, std::function<void()>> test_cases_by_name = {
      {"test_1", test_1}, {"test_2", test_2}, {"test_3", test_3},
      {"test_4", test_4}, {"test_5", test_5}, {"test_6", test_6},
      {"test_7", test_7}, {"test_8", test_8},
  };
  std::string tname;
  std::cin >> tname;
  auto it = test_cases_by_name.find(tname);
  if (it == test_cases_by_name.end()) {
    std::cout << "输入只能是 test_<N>，其中 <N> 可取整数 1 到 8." << std::endl;
    return 1;
  }
  (it->second)();
}
```



## 有理数

```c++
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>

template <typename T>
T gcd(T a, T b) {
  return b > 0 ? gcd(b, a % b) : a;
}

template <typename T>
class Rational {
 public:
  Rational(const T &n, const T &d) {
    if (d == 0) {
      throw std::logic_error("denominator must be != 0");
    }
    this->n = n;
    this->d = d;
  }

  Rational(const Rational<T> &rhs) {
    this->n = rhs.n;
    this->d = rhs.d;
  }

  T numerator() const { return n; }

  T denominator() const { return d; }

  Rational<T> operator+(const Rational<T> &rhs) const {
    T res_n = this->n * rhs.d + this->d * rhs.n;
    T res_d = this->d * rhs.d;
    return Rational<T>(res_n, res_d);
  }
  Rational<T> operator-(const Rational<T> &rhs) const {
    T res_n = this->n * rhs.d - this->d * rhs.n;
    T res_d = this->d * rhs.d;
    return Rational<T>(res_n, res_d);
  }
  Rational<T> operator*(const Rational<T> &rhs) const {
    T res_n = this->n * rhs.n;
    T res_d = this->d * rhs.d;
    return Rational<T>(res_n, res_d);
  }
  Rational<T> operator/(const Rational<T> &rhs) const {
    T res_n = this->n * rhs.d;
    T res_d = this->d * rhs.n;
    return Rational<T>(res_n, res_d);
  }

  Rational<T> &operator=(const Rational<T> &rhs) {
    this->n = rhs.n;
    this->d = rhs.d;
    return *this;
  }

  friend std::ostream &operator<<(std::ostream &out, const Rational<T> &r) {
    if (r.n == 0) {
      return out << "0";
    }
    T g = gcd(r.n, r.d);
    T m = r.n / g;
    T e = r.d / g;
    if (e == 1) {
      return out << m;
    } else {
      return out << m << "/" << e;
    }
  }

  // TODO: your code
 private:
  T n;
  T d;
};

Rational<int> operator""_r(const char *str, size_t len) {
  char copy[strlen(str) + 1];
  memset(copy, 0, sizeof copy);
  strcpy(copy, str);
  const char *sub = strchr(str, '/');
  if (!sub) {
    throw std::logic_error("broken invariant"); 
  }
  copy[sub - str] = '\0';
  int n = atoi(copy);
  int d = atoi(sub + 1);
  return Rational<int>(n, d);
}

void test_1() {
  Rational<int> r(3, 4);
  std::cout << r << std::endl;
}

void test_2() {
  bool exception_thrown = false;
  bool expected_message = false;
  try {
    Rational<int> r = Rational<int>(1, 0);
  } catch (std::logic_error &exn) {
    exception_thrown = true;
    if (!strncmp(exn.what(), "denominator must be != 0", 24)) {
      expected_message = true;
    }
  } catch (...) {
  }
  if (exception_thrown) {
    std::cout << "std::logic_error thrown!" << std::endl;
    if (expected_message) {
      std::cout << "the message is as expected." << std::endl;
    }
  } else {
    std::cout << "Oops!" << std::endl;
  }
}

void test_3() {
  Rational<int> r(3, 4);
  std::cout << r.numerator() << ' ' << r.denominator() << std::endl;
}

void test_4() {
  Rational<int> lhs(1, 6), rhs(1, 3);
  std::cout << (lhs + rhs) << std::endl;
}

void test_5() {
  Rational<int> lhs(1, 2), rhs(1, 6);
  std::cout << (lhs - rhs) << std::endl;
}

void test_6() {
  Rational<int> lhs(2, 4), rhs(4, 6);
  std::cout << (lhs * rhs) << std::endl;
}

void test_7() {
  Rational<int> lhs(2, 4), rhs(4, 6);
  std::cout << (lhs / rhs) << std::endl;
}

void test_8() {
  Rational<int> r(3, 4);
  std::cout << r << std::endl;
  Rational<int> rhs(101, 203);
  r = rhs;
  std::cout << r << ' ' << rhs << std::endl;
}

void test_9() {
  auto r = "3/4"_r;
  std::cout << r << std::endl;
}

void test_10() { std::cout << Rational<int>(4, 2) << std::endl; }

void test_11() {
  std::cout << (Rational<int>(1, 2) - Rational<int>(2, 4)) << std::endl;
}

void test_12() { std::cout << Rational<int>(3, 6) << std::endl; }

int main() {
  std::unordered_map<std::string, std::function<void()>> test_cases_by_name = {
      {"test_1", test_1},   {"test_2", test_2},   {"test_3", test_3},
      {"test_4", test_4},   {"test_5", test_5},   {"test_6", test_6},
      {"test_7", test_7},   {"test_8", test_8},   {"test_9", test_9},
      {"test_10", test_10}, {"test_11", test_11}, {"test_12", test_12},
  };
  std::string tname;
  std::cin >> tname;
  auto it = test_cases_by_name.find(tname);
  if (it == test_cases_by_name.end()) {
    std::cout << "输入只能是 test_<N>，其中 <N> 可取整数 1 到 12." << std::endl;
    return 1;
  }
  (it->second)();
}
```



## Bit_Vector

```c++
#include <iostream>
#include <vector>
using namespace std;

class MyBitVector {
 private:
  // TODO: Add your private member variables here
  std::vector<int> data;

 public:
  explicit MyBitVector(int size) {
    // TODO: Add your constructor here, and initialize your bitvector with 0s
    data.resize(size, 0);
  }

  explicit MyBitVector(const string &s) {
    // TODO: Add your constructor here, and initialize your bitvector with the
    // given string of 0s and 1s
    data.resize(s.length(), 0);
    for (std::string::size_type i = 0; i < s.length(); ++i) {
      data.at(i) = s.at(i) - '0';
    }
  }

  void set(int index) {
    // TODO: Set the bit at index to 1
    data.at(index) = 1;
  }

  void clear(int index) {
    // TODO: Set the bit at index to 0
    data.at(index) = 0;
  }

  bool get(int index) {
    // TODO: Return the value of the bit at index
    return data.at(index) == 1;
  }

  void print() {
    // TODO: Print the bitvector to continuous 0s and 1s of given length
    for (int bit : data) {
      cout << bit;
    }
    cout << endl;
  }

  // TODO: operator overloads to generate new bitvectors from existing ones
  MyBitVector operator&(MyBitVector &other) {
    // TODO: bv = bv1 & bv2
    size_t length = this->data.size();
    MyBitVector res(length);
    for (size_t i = 0; i < length; ++i) {
      if (this->get(i) & other.get(i)) {
        res.set(i);
      }
    }
    return res;
  }

  MyBitVector operator|(MyBitVector &other) {
    // TODO: bv = bv1 | bv2
    size_t length = this->data.size();
    MyBitVector res(length);
    for (size_t i = 0; i < length; ++i) {
      if (this->get(i) | other.get(i)) {
        res.set(i);
      }
    }
    return res;
  }

  MyBitVector operator^(MyBitVector &other) {
    // TODO: bv = bv1 ^ bv2
    size_t length = this->data.size();
    MyBitVector res(length);
    for (size_t i = 0; i < length; ++i) {
      if (this->get(i) ^ other.get(i)) {
        res.set(i);
      }
    }
    return res;
  }

  MyBitVector operator~() {
    // TODO: bv1 = ~bv2
    // question: what if we want to modify the original bitvector without
    // creating a new one?
    size_t length = this->data.size();
    MyBitVector res(length);
    for (size_t i = 0; i < length; ++i) {
      if (!this->get(i)) {
        res.set(i);
      }
    }
    return res;
  }

  // TODO: operator overloads to modify existing bitvectors in place
  MyBitVector &operator&=(MyBitVector &other) {
    // TODO: bv1 &= bv2
    size_t length = this->data.size();
    MyBitVector res(length);
    for (size_t i = 0; i < length; ++i) {
      if (this->get(i) & other.get(i)) {
        this->set(i);
      } else {
        this->clear(i);
      }
    }
    return *this;
  }

  MyBitVector &operator|=(MyBitVector &other) {
    // TODO: bv1 |= bv2
    size_t length = this->data.size();
    MyBitVector res(length);
    for (size_t i = 0; i < length; ++i) {
      if (this->get(i) | other.get(i)) {
        this->set(i);
      } else {
        this->clear(i);
      }
    }
    return *this;
  }

  MyBitVector &operator^=(MyBitVector &other) {
    // TODO: bv1 ^= bv2
    size_t length = this->data.size();
    MyBitVector res(length);
    for (size_t i = 0; i < length; ++i) {
      if (this->get(i) ^ other.get(i)) {
        this->set(i);
      } else {
        this->clear(i);
      }
    }
    return *this;
  }
};

void test1() {
  MyBitVector bv1("01010100");
  MyBitVector bv2("11101111");
  MyBitVector bv3 = bv1 & bv2;
  bv1 &= bv2;
  bv1.print();
  bv2.print();
  bv3.print();
}

void test2() {
  MyBitVector bv1("00001000");
  MyBitVector bv2("11010011");
  MyBitVector bv3 = bv1 | bv2;
  bv1 |= bv2;
  bv1.print();
  bv2.print();
  bv3.print();
}

void test3() {
  MyBitVector bv1("00010010");
  MyBitVector bv2("10111001");
  MyBitVector bv3 = bv1 ^ bv2;
  bv1 ^= bv2;
  bv1.print();
  bv2.print();
  bv3.print();
}

void test4() {
  MyBitVector bv1("00100100");
  MyBitVector bv2 = ~bv1;
  bv1 = ~bv1;
  bv1.print();
  bv2.print();
}

void test5() {
  MyBitVector bv1("00000001");
  bv1.set(2);
  bv1.print();
}

#define TEST(x)                      \
  std::cout << "test" << #x << "\n"; \
  test##x();

int main() {
  TEST(1);
  TEST(2);
  TEST(3);
  TEST(4);
  TEST(5);
  return 0;
}
```



## Generic_Adder

```c++
#include <iostream>
#include <string>

class MyComplex {
 public:
  MyComplex(int real, int imag) : real(real), imag(imag) {}
  int real;
  int imag;
  MyComplex operator+(const MyComplex& other) const {
    return MyComplex(this->real + other.real, this->imag + other.imag);
  }
  friend std::ostream& operator<<(std::ostream& os, const MyComplex& mc) {
    return os << "(" << mc.real << "," << mc.imag << ")";
  }
};

template <typename Ty1, typename Ty2>
auto GenericAdder(Ty1 a, Ty2 b) {
  return a + b;
}

template <>
auto GenericAdder(int a, std::string b) {
  return std::to_string(a) + b;
}

template <>
auto GenericAdder(std::string a, int b) {
  return a + std::to_string(b);
}

template <>
auto GenericAdder(int a, MyComplex b) {
  return MyComplex(a, 0) + b;
}

template <typename Ty1, typename Ty2>
auto GenericAdder(Ty1* a, Ty2* b) {
  return GenericAdder(*a, *b);
}

void test1() {
  std::cout << GenericAdder(1, 2) << "\n";
  std::cout << GenericAdder(1.0, 2.0) << "\n";
  std::cout << GenericAdder(1, std::string("1")) << "\n";
}

void test2() {
  std::cout << GenericAdder(1, MyComplex(1, 3)) << "\n";
  std::cout << GenericAdder(MyComplex(1, 3), MyComplex(1, 3)) << "\n";
}

void test3() {
  MyComplex a{1, 3};
  MyComplex b{2, 6};
  std::cout << GenericAdder(&a, &b) << "\n";
}

void test4() {
  MyComplex a{1, 3};
  MyComplex b{2, 6};
  MyComplex* pa = &a;
  MyComplex* pb = &b;
  std::cout << GenericAdder(&pa, &pb) << "\n";
}

#define TEST(x)                      \
  std::cout << "test" << #x << "\n"; \
  test##x();

int main() {
  TEST(1);
  TEST(2);
  TEST(3);
  TEST(4);
  return 0;
}
```

