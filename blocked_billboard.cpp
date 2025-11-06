// link: https://usaco.org/index.php?page=viewproblem2&cpid=759
#include <bits/stdc++.h>

using namespace std;

int area(vector<int> x){
	return (x[2] - x[0]) * (x[3] - x[1]);
}

int insec(pair<int,int> x, pair<int, int> a){
	return max(0, min(x.second, a.second) - max(x.first, a.first));
}

int calc(vector<int> x, vector<int> a){
	return area(x) - insec(make_pair(x[0], x[2]), make_pair(a[0], a[2])) * insec(make_pair(x[1], x[3]), make_pair(a[1], a[3]));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);
	vector<int> a(4), b(4), x(4);
	for(int &xx : a) cin >> xx;
	for(int &xx : b) cin >> xx;
	for(int &xx : x) cin >> xx;
	cout << calc(a, x) + calc(b, x);
	return 0;
}
