#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; 
const int N = 1e7+2;

vector<int>coins;
bool ready[N]; 
int value[N];

int solve(int x){
	if (x < 0) return INF;
	if (x == 0) return 0;
	if (ready[x]) return value[x];

	int best=INF;
	for (auto c : coins)
		best = min(best, solve(x-c)+1);
	ready[x] = true;
	value[x] = best;
	return best;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, x;
	cin>>n>>x;

	coins.resize(n);
	for (int i=0; i<n; i++) cin>>coins[i];

	int ans = solve(x);
	cout << (ans != INF ? ans : -1);
}
