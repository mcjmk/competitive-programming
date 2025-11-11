#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5+5;
int parent[N][25];
int depth[N];
bool vis[N];
vector<int>G[N];
 
void dfs(int x, int dep){
	vis[x] = true;
	depth[x] = dep;
	for (auto g: G[x]){
		if (!vis[g]){
			parent[g][0] = x;
			dfs(g, dep+1);
		}
	}
}
 
int lca(int a, int b){
	if (depth[b] < depth[a])
		swap(a, b);
 
	for (int i=24; i>=0; i--)
		if (depth[parent[b][i]] >= depth[a])
			b = parent[b][i];
			
	if (a == b)
		return a;
 
	for (int i=24; i>=0; i--){
		if (parent[a][i] != parent[b][i]){
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}
 
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, q;
	cin >> n >> q;	
	
	int a, b;
	for (int i=2; i<=n; i++){
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a); 
	}
	parent[1][0] = 1; 
	dfs(1, 0); 
 
	for (int i=1; i <= 24; i++){
		for (int j=1; j<=n; j++)
			parent[j][i] = parent[parent[j][i-1]][i-1];
	}
	
	while (q--){
		cin >> a >> b;
		cout << depth[a]+depth[b] - 2*depth[lca(a, b)] << "\n";
	}
 
}
