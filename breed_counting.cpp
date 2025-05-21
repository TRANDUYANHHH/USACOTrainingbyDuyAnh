/**
 * author: tranDuyAnh
**/
// link to the problem: https://usaco.org/index.php?page=viewproblem2&cpid=572
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define ll long long

const int mod = 1e9 + 7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> a(3, vector<int>(n + 1));
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    x--;
    for(int j : {0, 1, 2}){
      a[j][i] = a[j][i - 1] + (x == j);
    }
  }
  while(q--){
    int l, r;
    cin >> l >> r;
    for(int i : {0, 1, 2}){
      cout << a[i][r] - a[i][l - 1];
      if(i < 2) cout << ' ';
    }
    cout << endl;
  }
  return 0;
}
