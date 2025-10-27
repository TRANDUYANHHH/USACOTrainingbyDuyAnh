// link: https://usaco.org/index.php?page=viewproblem2&cpid=1013
#include <bits/stdc++.h>

using namespace std;

vector<int> f(int l, int r, int n){
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = i;
    }
    while(l < r){
        swap(a[l], a[r]);
        l++, r--;
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--; r1--; l2--; r2--;
    vector<int> a = f(l1, r1, n);
    vector<int> b = f(l2, r2, n); 
    vector<int> pos(n);
    for(int i = 0; i < n; i++){
        vector<vector<int>> vis(2, vector<int>(n));
        vector<pair<int,int>> p;
        vector<int> tt;
        int cur = i;
        vis[0][cur] = 1;
        while(true){
            p.emplace_back(1, cur);
            cur = a[cur];
            if(vis[1][cur]) {
                bool ok = false;
                for(auto [x, y] : p){
                    if(x == 2 && y == cur){
                        ok = true;
                    }
                    if(ok){
                        tt.push_back(y);
                    }
                }
                break;
            }
            p.emplace_back(2, cur);
            vis[1][cur] = 1;
            cur = b[cur];
            if(vis[0][cur]) {
                bool ok = false;
                for(auto [x, y] : p){
                    if(x == 1 && y == cur){
                        ok = true;
                    }
                    if(ok){
                        tt.push_back(y);
                    }
                }
                break;
            }
            vis[0][cur] = 1;
        }
        if(2 * k < (int)p.size()){
            pos[i] = p[2 * k].second;
        } else {
            int v = (2 * k - p.size()) % (p.size());
            pos[i] = tt[v];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(pos[j] == i){
                cout << j + 1 << '\n';
                break;
            }
        }
    }
}
