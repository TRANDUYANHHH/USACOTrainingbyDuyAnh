// link: https://www.codechef.com/problems/TRPTSTIC
#include <bits/stdc++.h>

using namespace std;

void solve(){
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> A(n, vector<int>(m));
  long long sum = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> A[i][j];
      sum = sum + A[i][j];
    }
  }
  if(sum < k + 1){
    cout << -1;
    return;
  }
  vector<vector<long long>> P(n + 1, vector<long long>(m + 1));
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + A[i - 1][j - 1];
    }
  }
  auto f = [&](int x){
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        if(!A[i - 1][j - 1]) continue;
        int x1 = max(1, i - x);
        int y1 = max(1, j - x);
        int x2 = min(n, i + x);
        int y2 = min(m, j + x);
        long long tt = P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
        if(tt >= k + 1){
          return true;
        }
      }
    }
    return false;
  };
  int l = 0, r = max(n, m);
  while(l < r){
    int mid = (l + r) / 2;
    if(f(mid)) r = mid;
    else l = mid + 1;
  }
  cout << r;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while(tt--){
    solve();
    cout << '\n';
  }
  return 0;
}
