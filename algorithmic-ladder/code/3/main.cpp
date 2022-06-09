#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

size_t n;
const size_t maxn = 100005;
int l, r;
vector<int> adjs[maxn];
unsigned distance_to[maxn];

void dfs(size_t curr, size_t prev) {
  for (int adj : adjs[curr]) {
    if (adj == prev)
      continue;
    distance_to[adj] = distance_to[curr] + 1;
    dfs(adj, curr);
  }
}

int main() {
  scanf("%zu", &n);

  for (size_t i = 0; i < n; ++i) {
    scanf("%d%d", &l, &r);
    if (l != -1) {
      adjs[i].push_back(l);
      adjs[l].push_back(i);
    }
    if (r != -1) {
      adjs[i].push_back(r);
      adjs[r].push_back(i);
    }
  }

  dfs(0, 0);
  size_t index = max_element(distance_to, distance_to + n) - distance_to;
  memset(distance_to, 0, sizeof(distance_to));
  dfs(index, index);
  unsigned distance = *max_element(distance_to, distance_to + n);

  printf("%zu", 2 * n - 2 - distance);
}
