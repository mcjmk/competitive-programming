#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+3;
const int INF = 1e9;

vector<int>G[3 * N];
int dis[3 * N];
bool processed[3 * N];

void dijkstra(int x, int n){
    for (int i=1; i<=n; i++) dis[i] = INF;
    priority_queue<pair<int, int>>q;
    dis[x] = 0;
    q.push({0, x});
    while (!q.empty()){
        int a = q.top().second; q.pop();
        if (processed[a]) continue;
        processed[a] = true;
        for (auto g : G[a]){
            int b = g, w = 1;
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
    for (int i=0; i<m; i++){
        cin >> a >> b;
        G[a].push_back(b + n * 1);
        G[a + n * 1].push_back(b + n * 2);
        G[a + n * 2].push_back(b);
        }
    
    int S, T;
    cin >> S >> T;

    dijkstra(S, 3 * n + 3); 
    cout << (dis[T] == INF ? -1 : dis[T] / 3);
}
