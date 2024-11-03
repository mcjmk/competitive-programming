#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
int parent[N][25];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, q;
	cin >> n >> q;
	for (int i=2; i<=n; i++)
		cin >> parent[i][0];	 

	for (int i=1; i<=24; i++){
		for (int j=2; j<=n; j++)
			parent[j][i] = parent[parent[j][i-1]][i-1];
	}
  
	int x, k;
	while (q--){
		cin >> x >> k; 
		for (int i=24; i >= 0; i--){
			if (k >= (1<<i)){
				k -= (1<<i); 
				x = parent[x][i];
			}
		}
		cout << (x == 0 ? -1 : x) << "\n";
	} 
} 