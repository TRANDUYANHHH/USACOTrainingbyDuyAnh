/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;

// link: https://usaco.org/index.php?page=viewproblem2&cpid=738

#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 3e5 + 5, mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].second >> a[i].first;
	}
	sort(all(a));
	int l = 0, r = n - 1;
	int mn = 0;
	while(l <= r){
		if(l == r){
			mn = max(mn, a[l].first * 2);
			break;	
		}
		mn = max(mn, a[l].first + a[r].first);
		int x = min(a[l].second, a[r].second);
		a[l].second -= x;
		a[r].second -= x;
		if(a[l].second == 0) l++;
		if(a[r].second == 0) r--;
	}
	cout << mn;
	return 0;
}
