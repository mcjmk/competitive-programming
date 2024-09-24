
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1001;

bool grid[N][N];
long long sum[N][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; 
	cin>>n;

	char czar;
	for (int y=1; y<=n; y++){
		for (int x=1; x<=n; x++){
			cin>>czar;
			grid[y][x] = (czar == '.' ? true : false);
		}
	}
	

	for (int y=1; y<=n; y++){
		for (int x=1; x<=n; x++){
			if (grid[y][x]){
				if (x==1 && y==1)
					sum[y][x] = 1;
				else 
					sum[y][x] = (sum[y-1][x] + sum[y][x-1]) % MOD;
			}
		}
	}
	cout<<sum[n][n];
}
