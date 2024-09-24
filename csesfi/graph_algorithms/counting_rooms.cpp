#include <bits/stdc++.h>
using namespace std;

const int N = 1002;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool is_floor[N][N];
bool vis[N][N];

void dfs(int y, int x){
	if (vis[y][x] == true)
		return;
	vis[y][x]=true;
	for (int i=0; i<4; i++){
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (is_floor[ny][nx])
			dfs(ny, nx);
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m; 
	cin>>n>>m;

	char czar;
	for (int y=1; y<=n; y++){
		for (int x=1; x<=m; x++) {
			cin>>czar;
			is_floor[y][x] = (czar == '.');
		}
	}

	int res = 0;
	for (int y=1; y<=n; y++){
		for (int x=1; x<=m; x++) {
			if (is_floor[y][x] && vis[y][x]==0){
				res++;
				dfs(y,x);
			}
		}
	}
	cout<<res;
}
