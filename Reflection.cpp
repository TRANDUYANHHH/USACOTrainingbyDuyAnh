// @author : tranDuyAnh
// created: 2025-09-11 14:50
// link: https://usaco.org/index.php?page=viewproblem2&cpid=1491
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, U;
	cin >> N >> U;
	vector<string> A(N);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	int op = 0;
	for(int i = 0; i < N / 2; i++) for(int j = 0; j < N / 2; j++){
		int cnt = 0;
		vector<int> dx = {i, N - i - 1};
		vector<int> dy = {j, N - j - 1};
		for(int x : dx){
			for(int y : dy){
				cnt += (A[x][y] == '#');
			}
		}
		op += min(cnt, 4 - cnt);
	}
	cout << op << '\n';
	for(;U--;){
		int i, j;
		cin >> i >> j;
		--i, --j;
		vector<int> dx = {i, N - i - 1};
		vector<int> dy = {j, N - j - 1};
		int cnt = 0;
		for(int x : dx){
			for(int y : dy){
				cnt += (A[x][y] == '#');
			}
		}
		op -= min(cnt, 4 - cnt);
		A[i][j] = (A[i][j] == '#' ? '.' : '#');
		cnt = 0;
		for(int x : dx){
			for(int y : dy){
				cnt += (A[x][y] == '#');
			}
		}
		op += min(cnt, 4 - cnt);
		cout << op << '\n';
	}
	return 0;
}
