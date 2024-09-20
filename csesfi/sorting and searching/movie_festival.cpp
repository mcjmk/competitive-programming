#include <bits/stdc++.h>
using namespace std;
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;
 
	vector<pair<int,int>>v;
	int a,b;
	for (int i=0; i<n; i++){
		cin>>a>>b;
		v.push_back({b,a});
	}
	sort(v.begin(), v.end());
 
	int end=0;
	int counter=0;
	for (int i=0; i<n; i++){
		if (v[i].second >= end){
			counter++;
			end=v[i].first;
		}	
	}
	cout<<counter;
}