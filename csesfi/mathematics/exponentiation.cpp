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
	int n;
	cin>>n; 
	
	long long a,b;
	for (int i=0; i<n; i++){
		cin>>a>>b;
	    cout<<modpow(a,b)<<"\n";
	}
}
