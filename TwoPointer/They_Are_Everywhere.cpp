/**
 *  author: @tranDuyAnh
 **/
#include <bits/stdc++.h>

using namespace std;
// link: https://codeforces.com/problemset/problem/701/C
#define ll long long
#define all(x) (x).begin(), (x).end()
const int maxn = 3e5 + 5, mod = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<char> se;
	for(char c : s) se.insert(c);
	map<char,vector<int>> mp;
	for(int i = 0; i < n; i++){
		mp[s[i]].push_back(i);
	}
	auto check = [&](int l, int r){
		for(char c : se){
			auto it = lower_bound(all(mp[c]), l);
			if(it == mp[c].end() || *it > r){
				return false;
			}
		}
		return true;
	};
	int mn = n;
	int l = 0;
	for(int i = 0; i < n; i++){
		while(l < n && !check(i, l)){
			l++;
		}
		if(l < n){
			mn = min(mn, l - i + 1);
		}
	}
	cout << mn;
	return 0;
}

