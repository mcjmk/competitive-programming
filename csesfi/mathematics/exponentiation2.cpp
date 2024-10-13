#include <bits/stdc++.h>
using namespace std;
 
const int P = 1e9+7;
 
long long modpow(long long x, long long n, int mod){
	if (n==0) return 1;
	long long u = modpow(x, n/2, mod);
	u=(u*u) % mod;
	if (n%2)
		u = (u*x) % mod;
	return u;
}
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int t;
	cin>>t;
 
	int a,b,c; 
	while (t--){
		cin>>a>>b>>c;
		int r = modpow(b, c, P-1);
		int res = modpow(a,r,P);
		cout<<res<<"\n";
	}
}
