#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
const int N = 1000000;

long long f[N+3];
long long binpow(long long a, long long b){
    if (b==0) return 1;
    long long u = binpow(a, b/2);
    u = (u * u) % MOD;
    if (b%2)
        u = (u * a) % MOD;
    return u % MOD;
}

long long inv(long long a){
    return binpow(a, MOD-2);
}


long long bin_coef(long long n, long long k){
   return (f[n] * inv(f[k] * f[n-k] % MOD)) % MOD;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; 
	cin>>n;

    f[0] = 1;
    for (long long i=1; i<=N; i++)
        f[i] = (f[i-1]*i) % MOD;

    long long a,b;
    while (n--){
        cin>>a>>b;
        cout<<bin_coef(a,b)<<"\n";
    }
}
