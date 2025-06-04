/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;
//link: https://usaco.org/index.php?page=viewproblem2&cpid=894
#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 3e5 + 5, mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("planting.in", "r", stdin);
	freopen("planting.out", "w", stdout);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n - 1; i++){
		int x, y;
		cin >> x >> y;
		x--; y--;
		a[x]++;
		a[y]++;
	}
	cout << *max_element(all(a)) + 1;
	return 0;
}

