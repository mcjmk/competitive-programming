#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+3;
vector<int>G[N];
int dp[N];
 
int dfs(int v){
	dp[v] = G[v].size();
	for (auto x : G[v])
		dp[v] += dfs(x);
	return dp[v];
}
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int n; 
	cin>>n;
	
	int boss; 
	for (int i=2; i<=n; i++){
		cin>>boss;
		G[boss].push_back(i);
	}
	dfs(1);
	for (int i=1; i<=n; i++)
		cout<<dp[i]<<" ";
}
