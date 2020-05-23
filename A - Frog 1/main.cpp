#include<bits/stdc++.h>

#define endl "\n"
#define IOS                \
  ios::sync_with_stdio(0); \
  cin.tie(0);              \
  cout.tie(0);

using namespace std;

const int MAX_NUM = 1e5;
int a[MAX_NUM];
int dp[MAX_NUM];
int n;

int rec (int i) {
  if (i == n - 1) return 0;
  if (dp[i] != -1) return dp[i];
  int cost = abs(a[i] - a[i + 1]) + rec(i + 1);
  if (i + 2 <= n - 1) {
    cost = min(cost, abs(a[i] - a[i + 2]) + rec(i + 2));
  }
  return dp[i] = cost;
}

int main() {
  IOS;
  cin >> n;
  memset(dp, -1, sizeof(dp));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cout << rec(0) << endl;
  return 0;
}
