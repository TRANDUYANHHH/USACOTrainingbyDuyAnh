// @author: tranDuyAnh
// link: https://usaco.org/index.php?page=viewproblem2&cpid=944
#include <bits/stdc++.h>

using namespace std;
#define ll long long 

vector<int> G[1<<17];
int X[1<<17], Y[1<<17];
bool vis[1<<17];
int N, M;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);
	cin >> N >> M;
	for(int i = 0; i < N; i++){
		cin >> X[i] >> Y[i];
	}
	for(int i = 0; i < M; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ll mn = (long long)1e18;
	auto bfs = [&](int s){
		queue<int> q;
		q.push(s);
		vis[s] = true;
		int minx = X[s], miny = Y[s];
		int maxx = X[s], maxy = Y[s];
		while(!q.empty()){
			int u = q.front();
			q.pop();
			minx = min(minx, X[u]);
			maxx = max(maxx, X[u]);
			miny = min(miny, Y[u]);
			maxy = max(maxy, Y[u]);
			for(int v : G[u]){
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
		mn = min(mn, 2ll *((maxx - minx) + (maxy - miny)));
	};
	for(int i = 0; i < N; i++){
		if(!vis[i]){
			bfs(i);
		}
	}
	cout << mn;
	return 0;
}
