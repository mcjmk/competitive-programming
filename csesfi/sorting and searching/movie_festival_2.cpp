#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, k;
	cin >> n >> k;
	
	vector<pair<int,int>>v;
	int a, b;
	for (int i=0; i<n; i++){
		cin >> a >> b;
		v.push_back({b, a});
	}
	
	sort(v.begin(), v.end());
	multiset<int>ms;
	
	for (int i=0; i<k; i++)
		ms.insert(0);
	
	int ans = 0;
	for (int i=0; i<v.size(); i++){
		auto g = ms.upper_bound(v[i].second);
		if (g != ms.begin()){
			g--;
			ms.erase(g);
			ms.insert(v[i].first);
			ans++;
		}
	}
	
	cout << ans;
	
	return 0;
}
