#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007LL;
 
long long modpow(long long x, long long n){
	if (n==0) return 1;  
	long long u = modpow(x, n/2) % MOD; 
    u = (u * u) % MOD;
    if (n % 2) u = (u * x) % MOD;
	return u;
}
 
int main() {
    cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n;
	cin>>n; 
	
	long long a,b;
	while(n--){
		cin>>a>>b;
	    cout<<modpow(a,b)<<"\n";
	}
}
