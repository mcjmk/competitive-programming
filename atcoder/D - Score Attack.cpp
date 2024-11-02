#include <bits/stdc++.h>
using namespace std;
 
constexpr int N = 2550;
const long long INF = 1e14;
 
long long dis[N];
vector<tuple<int,int,int>>edges;
bool vis[N];
vector<int>G[N];

void dfs(int x){
	if (vis[x]) return;
	vis[x] = true;
	for (auto g: G[x]){
		if (!vis[g])
			dfs(g);
	}
}

bool bellman_ford(int start, int n){
	for (int i=1; i<=n; i++)
		dis[i] = INF;
	dis[start]=0; 
 
	for (int i=1; i<=n-1; i++){
		for (auto e : edges){
			int a, b, w;
			tie(a, b, w) = e;
			if (dis[a] != INF && dis[b] > dis[a] + w)
				dis[b] = dis[a] + w;
		}
	}
	
	bool negative_cycle_to_n=false;
	for (auto e : edges){
		int a, b, w;
		tie(a, b, w) = e;
		
		if (dis[a] != INF && dis[b] > dis[a] + w){
			dfs(b);
			if (vis[n])
				negative_cycle_to_n = true;
			dis[b] = dis[a] + w;
		}
	}
	return negative_cycle_to_n;
}
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;
 
	int a, b, c;
	for (int i=0; i<m; i++){
		cin >> a >> b >> c;
		edges.push_back({a, b, -1*c});
		G[a].push_back(b);
	}
 
  if (bellman_ford(1,n))
    cout << "inf";
    
  else 
	  cout << (-1 * dis[n]);
 
}
