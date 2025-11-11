#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+3;
const long long INF = 1'000'000'000'000'000;

vector<pair<int,long long>>G[N];
long long dis[N];
bool processed[N];

void dijkstra(int x, int n){
    for (int i=0; i<=2*n; i++) dis[i] = INF;
    priority_queue<pair<long long, int>>q;
    
    dis[x] = 0;
    q.push({0, x});
    
    while (!q.empty()){
    	auto t = q.top(); 
        int a = t.second; 
        q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto g : G[a]){
            int b = g.first;
            long long w = g.second;
            if (dis[a] + w < dis[b]){ 
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}
int main(){
    cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    int a, b;
    long long x;
    
    for (int i=0; i<m; i++){
        cin >> a >> b >> x;
		G[a].push_back({b, x});
		G[a].push_back({b+n, x/2});
		G[a+n].push_back({b+n, x});
          
    }
     
    dijkstra(1, n);
    cout << dis[2*n]; 
    
}
