#include <bits/stdc++.h>
using namespace std;

const int N = 3e5+6;
const int INF = 1e9;

vector<int>G[N];
int dis[N];

void bfs(int x, int G_size){
    for (int i=1; i<=G_size; i++) dis[i] = INF;
        dis[x]=0;
        queue<int> q;
        q.push(x);
        while (!q.empty()){
            int u = q.front(); q.pop();
            for (auto v: G[u]){
                if (dis[v] != INF) continue;
                dis[v] = dis[u] + 1;
                q.push(v);
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
        G[a].push_back(n + b);
        G[n + a].push_back(2 * n + b);
        G[2* n + a].push_back(b);
    }
    
    int S, T;
    cin >> S >> T;

    bfs(S, 3*n + 3); 
    cout << (dis[T] == INF ? -1 : (dis[T] / 3));

}
