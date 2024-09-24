#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1e6+2;

bool ready[N];
long long res[N];

long long solve(int x){
	if (x<0) return 0;
	if (x==0) return 1;
	if (ready[x]) return res[x];

	long long sum = 0;
	for (int i=1; i<=6; i++){
		sum += solve(x-i);
		sum %= MOD;
	}
	ready[x] = true;
	res[x] = sum;
	return sum;	
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; 
	cin>>n;
	
	cout<<solve(n);
}
