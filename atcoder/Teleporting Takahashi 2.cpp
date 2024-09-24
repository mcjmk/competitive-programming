#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, k; 
	cin>>n>>m>>k;
	
	vector<pair<int,int>>v;
	int x,y;
	for (int i=0; i<m; i++) {
		cin>>x>>y;
		v.push_back({x-1,y-1});
	}

	vector<int>dp(n);
	dp[0]=1;
	int start=0, end=n-1;
	for (int i=1; i<=k; i++){
		queue<pair<int,int>>q;
		for (auto g : v)
			q.push({g.second, dp[(g.first + start) % n]});
		start = ( start - 1 +n) % n;
		end = (( end- 1 ) + n) % n;

		while (q.size()){
			auto g = q.front();
			dp[(g.first + start ) % n] = (dp[(g.first + start) % n] + g.second) % MOD;
			q.pop(); 
		}	 
	}
	long long res = 0;
	for (int i = 0; i<n; i++)
		res = (res + dp[i] ) % MOD;
	cout<<res;
}

