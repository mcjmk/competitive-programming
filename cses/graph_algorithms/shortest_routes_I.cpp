#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pii pair<int,int> 
#define PB push_back

const int N = 1e5 + 5;
const ll INF = 1e14+5;

bool processed[N];
ll dis[N];
vector<pair<int, int>>G[N];

int n, m;
void dijkstra(int src){
	for (int i = 1; i <= n; i++){
		dis[i] = INF;
		processed[i] = false;
	}
	
	dis[src] = 0;
	priority_queue<pair<ll, int>>pq;
	pq.push({0, src});
	
	while (pq.size()){
		auto [d, u ] = pq.top(); pq.pop();
		if (processed[u])
			continue;
			
		processed[u] = true;
		for (auto [v, w] : G[u]){
			if (dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push({-dis[v], v});
			}
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	
	int a, b, c;
	for (int i = 0; i < m; i++){
		cin >> a >> b >> c;
		G[a].PB({b, c});
	}
	
	dijkstra(1);
	for (int i = 1; i <= n; i++)
		cout << dis[i] << " ";
	
	return 0;
}