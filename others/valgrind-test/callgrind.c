#include <unistd.h>

void bar();
void foo() {
  sleep(1);
  bar();
}
void bar() {
  sleep(1);
  foo();
}

int main() { foo(); }
