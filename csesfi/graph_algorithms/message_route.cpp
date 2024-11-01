#include <bits/stdc++.h>
using namespace std;

#define PB push_back

const int N = 2e5+3;
const int INF = 1e7;
vector<int>G[N];
int dis[N], pre[N];
bool vis[N];

void bfs(){
	vis[1] = true;
	dis[1] = 0;
	pre[1] = 1;
	queue<int>q;
	q.push(1);
	
	while (!q.empty()){
		int v = q.front();
		q.pop(); 
		for (auto x: G[v]){
			if (vis[x])
				continue;
			q.push(x);
			vis[x] = true;
			dis[x] = dis[v]+1;
			pre[x] = v;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i=0; i < m; i++){
		cin >> a >> b;
		G[a].PB(b);
		G[b].PB(a);
	}
	bfs();
	
	if (!vis[n])
		cout << "IMPOSSIBLE";
	
	else {
		vector<int>v;
		int i = n;
		do {
			v.PB(i);
			i = pre[i];
		} while (pre[i] != i);
		v.PB(1);
		reverse(v.begin(), v.end());
	
		cout << v.size() << "\n";
		for (auto g: v)
			cout << g << " ";
	}

}
