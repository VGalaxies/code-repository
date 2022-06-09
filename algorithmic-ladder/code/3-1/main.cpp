#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100005;
int n, l, r, diameter;
int first_furthest[maxn], second_furthest[maxn];
vector<int> adjs[maxn];

void dfs(int curr) {
  int child, l, r;

  switch (adjs[curr].size()) {
  case 0:
    break;
  case 1:
    child = adjs[curr].at(0);
    dfs(child);
    first_furthest[curr] = first_furthest[child] + 1;
    second_furthest[curr] = 0;
    break;
  case 2:
    l = adjs[curr].at(0);
    r = adjs[curr].at(1);
    dfs(l);
    dfs(r);
    if (first_furthest[l] >= first_furthest[r]) {
      first_furthest[curr] = first_furthest[l] + 1;
      second_furthest[curr] = first_furthest[r] + 1;
    } else {
      first_furthest[curr] = first_furthest[r] + 1;
      second_furthest[curr] = first_furthest[l] + 1;
    }
    break;
  default:
    assert(0);
  }

  diameter = max(diameter, first_furthest[curr] + second_furthest[curr]);
}

int main() {
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    scanf("%d%d", &l, &r);
    if (l != -1) {
      adjs[i].push_back(l);
    }
    if (r != -1) {
      adjs[i].push_back(r);
    }
  }

  dfs(0);

  printf("%d", 2 * n - 2 - diameter);
}
