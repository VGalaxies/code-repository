#define SIZE 4096

int arr[SIZE][SIZE];

void foo() {
  for (int i = 0; i < SIZE; ++i) {
    for (int j = 0; j < SIZE; ++j) {
      arr[i][j] = i * j;
    }
  }
}

void bar() {
  for (int j = 0; j < SIZE; ++j) {
    for (int i = 0; i < SIZE; ++i) {
      arr[i][j] = i * j;
    }
  }
}


int main() {
  foo();
  bar();
}
