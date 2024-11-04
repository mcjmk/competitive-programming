#include <bits/stdc++.h>
using namespace std;

const int N = 1003;
int red[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int p, k;
	vector<pair<int, int>>v;
	
	for (int i=0; i<m; i++){
		cin >> p >> k;
		red[p]++;
		red[k]++;
	}
	
	long long temp=0;
	for (int i=1; i<=n; i++)
		temp += red[i] * (n-red[i]-1);
		
	long long res = (n*(n-1)*(n-2)/6) - temp/2;
	cout << res;

	return 0;
}
