// @author: tranDuyAnh
//link: https://usaco.org/index.php?page=viewproblem2&cpid=644
#include <bits/stdc++.h>

using namespace std;
vector<int> G[3005];
bool vis[3005];
int N, M;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	auto bfs = [&](int s){
		queue<int> q;
		q.push(s);
		vis[s] = true;
		while(!q.empty()){
			int u = q.front();	
			q.pop();
			for(int v : G[u]){
				if(!vis[v]){
					vis[v] = true;
					q.push(v);
				}
			}
		}
		for(int i = 0; i < N; i++){
			if(!vis[i]){
				return false;
			}
		}
		return true;
	};
	vector<int> close;
	auto f = [&](){
		memset(vis, false, sizeof(vis));
		for(int x : close){
			vis[x] = true;	
		}	
		for(int i = 0; i < N; i++){
			if(!vis[i]){
				return bfs(i);
			}	
		}
		return true;
	};
	cout << (bfs(0) ? "YES" : "NO") << '\n';	
	for(int i = 0; i < N; i++){
		int x;
		cin >> x;
		x--;
		close.push_back(x);
		if(i == N - 1){
			break;
		}
		cout << (f() ? "YES" : "NO") << '\n';
	}
	return 0;
}

