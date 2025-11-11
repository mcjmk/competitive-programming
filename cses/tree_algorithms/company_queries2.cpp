#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int parent[N][25];
int depth[N];
bool vis[N];
vector<int>G[N];

void dfs(int x, int dep){
	if (vis[x]) return;
	vis[x] = true;
	depth[x] = dep;

	for (auto g: G[x]){
		if (!vis[g])
			dfs(g, dep+1);
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
	for (int i=2; i<=n; i++){
		cin >> parent[i][0];
		G[parent[i][0]].push_back(i);
	}
	parent[1][0] = 1; 
	for (int i=1; i <= 24; i++){
		for (int j=1; j<=n; j++)
			parent[j][i] = parent[parent[j][i-1]][i-1];
	}

	dfs(1, 1); 

	int a, b;
	while (q--){
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}

}
