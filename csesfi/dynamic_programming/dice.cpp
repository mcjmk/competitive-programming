
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; 
	cin>>n;
	
	vector<int>count(n+1);
	count[0] = 1;
	for (int i=1; i<=n; i++){
		for (int c=1; c<=6; c++){
			if (i-c >= 0) {
				count[i] += count[i-c];
				count[i] %= MOD;
			}
		} 
	}
	cout<<count[n];
}
