#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+3;
bool vis[N];
bool color[N];

vector<int>G[N];

bool bipartite = true;

void dfs(int v, int from){
    vis[v] = true;
    color[v] = !color[from];
    for (auto x : G[v]){
        if (!vis[x])
            dfs(x, v);
        else if (color[x] == color[v])
            bipartite = false;
    }
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m; 
	cin >> n >> m;

    int a, b;
    for (int i=0; i<m; i++){
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i=1; i<=n; i++){
        if (!vis[i])
            dfs(i, i);
    }

    if (bipartite)
        for (int i=1; i<=n; i++)
            cout<<int(color[i]) + 1<<" ";

    else
        cout<<"IMPOSSIBLE";

}
