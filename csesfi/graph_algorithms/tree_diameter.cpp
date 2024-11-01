#include <bits/stdc++.h>
using namespace std;

#define PB push_back

const int N = 2e5+10;
int dis[N];
bool vis[N];
vector<int>G[N];

void dfs(int v){
	if (vis[v]) return;
	vis[v] = true;
	
	for (auto x : G[v]) {
		if (vis[x]) continue;
		dis[x] = dis[v] + 1;
		dfs(x);
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;

    int a, b;
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }

    dfs(1);
	int max_dis = 0, v=1;
	for (int i=1; i<=n; i++){
		if (dis[i] > max_dis){
			max_dis = dis[i];
			v = i;
		}
	}
	
	for (int i=1; i<=n; i++){
		dis[i] = 0;
		vis[i] = false;
	}
	
	dfs(v); 
	int res = 0;
	for (int i=1; i<=n; i++){
		if (dis[i] > res){
			res = dis[i]; 
		}
	}
	
	cout << res << "\n";
}
