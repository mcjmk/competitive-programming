#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n;
	
	int prev = 0, x;
	long long res = 0;
	
	for (int i; i<n; i++){
		cin>>x;
		if (x < prev){
			res += prev-x;
			x = prev; }
		prev = x;
	}
	cout<<res;