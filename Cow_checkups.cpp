// @author : tranDuyAnh
// created: 2025-09-11 15:41
// link: https://usaco.org/index.php?page=viewproblem2&cpid=1469
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 7505;
bool vis[maxn][maxn];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	vector<int> C(N + 1);
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		cin >> B[i];
	}
	for(int i = 0; i < N; i++){
		reverse(A.begin(), A.begin() + i + 1);
		int cnt = 0;
		for(int j = 0; j < N; j++){
			if(A[j] == B[j]){
				cnt++;
			}
		}
		int L = 0, R = i;
		while(L <= R){
			if(!vis[L][R]){
				C[cnt]++;
				vis[L][R] = true;
			}
			if(A[L] == B[L]) cnt--;
			if(A[L] == B[R]) cnt++;
			if(A[R] == B[R]) cnt--;
			if(A[R] == B[L]) cnt++;
			L++; R--;
		}
		reverse(A.begin(), A.begin() + i + 1);
	}
	for(int i = N - 1; i >= 0; i--){
		reverse(A.begin() + i, A.end());
		int cnt = 0;
		for(int j = 0; j < N; j++){
			if(A[j] == B[j]) cnt++;
		}
		int L = i, R = N - 1;
		while(L <= R){
			if(!vis[L][R]){
				C[cnt]++;
				vis[L][R] = true;
			}
			if(A[L] == B[L]) cnt--;
			if(A[L] == B[R]) cnt++;
			if(A[R] == B[R]) cnt--;
			if(A[R] == B[L]) cnt++;
			L++; R--;
		}
		reverse(A.begin() + i, A.end());
	}
	for(int i = 0; i <= N; i++){
		cout << C[i] << '\n';
	}
	return 0;
}
