/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;

// link: https://codeforces.com/contest/702/problem/C

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 3e5 + 5, mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> c(n), b(m);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	sort(all(c));
	sort(all(b));
	int mx = 0;
	int l = 0;
	for(int i = 0; i < n; i++){
		while(l < m && b[l] < c[i]) l++;
		int mn = INT_MAX;
		if(l < m){
			mn = min(mn, b[l] - c[i]);
		}	
		if(l > 0){
			mn = min(mn, c[i] - b[l - 1]);
		}
		mx = max(mx, mn);
	}
	cout << mx;
	return 0;
}
 
