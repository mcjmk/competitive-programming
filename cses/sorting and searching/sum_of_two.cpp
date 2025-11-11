#include <bits/stdc++.h>
using namespace std;
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, x;
	cin>>n>>x;
 
	vector<pair<int,int>>v;
	int a;
	for (int i=0; i<n; i++){
		cin>>a;
		v.push_back({a, i+1});
	}
 
	sort(v.begin(),v.end());
 
	for (int i=0; i<n-1; i++){
		int k=0;
		for (int b = n/2; b >= 1; b/=2){
			while (b+k < n && v[i].first + v[b+k].first <= x) k += b;
		}
		if (v[i].first + v[k].first == x && i != k){
			cout<<min(v[i].second, v[k].second)<<" "<<max(v[i].second, v[k].second);
			return 0;
		}
	}
	cout<<"IMPOSSIBLE";
}