// @author: tranDuyAnh
// link: https://usaco.org/index.php?page=viewproblem2&cpid=668
#include <bits/stdc++.h>

using namespace std;
vector<int> G[205];
bool vis[205];
int N;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	cin >> N;
	vector<int> x(N), y(N), p(N);
	for(int i = 0; i < N; i++){
		cin >> x[i] >> y[i] >> p[i];
	}	
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(i != j){
		int dx = abs(x[i] - x[j]);
		int dy = abs(y[i] - y[j]);
		if(dx * dx + dy * dy <= p[i] * p[i]){
			G[i].push_back(j);
		}
	}
	auto bfs = [&](int s){
		memset(vis, false, sizeof(vis));
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
		int cnt = 0;
		for(int i = 0; i < N; i++){
			if(vis[i]) cnt++;
		}
		return cnt;
	};
	int mx = 1;
	for(int i = 0; i < N; i++){
		mx = max(mx, bfs(i));
	}
	cout << mx;
	return 0;
}
