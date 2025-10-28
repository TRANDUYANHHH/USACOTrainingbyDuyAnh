// link: https://usaco.org/index.php?page=viewproblem2&cpid=833
#include <bits/stdc++.h>

using namespace std;

map<string, string> mp;

vector<string> FIND(string cur){
	vector<string> ans;
	while(true){
		ans.push_back(cur);
		if(mp.find(cur) == mp.end()){
			break;
		}
		cur = mp[cur];
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("family.in", "r", stdin);
	freopen("family.out", "w", stdout);
	int n;
	string a, b;
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++){
		string x, y;
		cin >> x >> y;
		mp[y] = x;
	}
	vector<string> fa = FIND(a);
	vector<string> fb = FIND(b);
	if(fa.back() != fb.back()){
		cout << "NOT RELATED";
		return 0;
	}
	if(mp.find(a) != mp.end() && mp.find(b) != mp.end() && mp[a] == mp[b]){
		cout << "SIBLINGS";
		return 0;
	}
	for(int i = 0; i < (int)fa.size(); i++){
		if(fa[i] == b){
			if(i == 1){
				cout << b << " is the mother of " << a;
			}
			if(i == 2){
				cout << b << " is the grand-mother of " << a;
			}
			if(i > 2){
				cout << b << " is the ";
				for(int j = 0; j < i - 2; j++){
					cout << "great-";
				}
				cout << "grand-mother of " << a;
			}
			return 0;
		}
		if(fa[i] == mp[b]){
			if(i > 1){
				cout << b << " is the ";
				for(int j = 0; j < i - 2; j++){
					cout << "great-";
				}
				cout << "aunt of " << a;
				return 0;
			}
		}
	}
	for(int i = 0; i < (int)fb.size(); i++){
		if(fb[i] == a){
			if(i == 1){
				cout << a << " is the mother of " << b;
			}
			if(i == 2){
				cout << a << " is the grand-mother of " << b;
			}
			if(i > 2){
				cout << a << " is the ";
				for(int j = 0; j < i - 2; j++){
					cout << "great-";
				}
				cout << "grand-mother of " << b;
			}
			return 0;
		}
		if(fb[i] == mp[a]){
			if(i > 1){
				cout << a << " is the ";
				for(int j = 0; j < i - 2; j++){
					cout << "great-";
				}
				cout << "aunt of " << b;
			}
			return 0;
		}
	}
	cout << "COUSINS";
}
