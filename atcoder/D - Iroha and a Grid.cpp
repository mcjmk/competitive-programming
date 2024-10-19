#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9+7;
const int N = 200000;

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
   return (f[n] * ((inv(f[k]) * inv(f[n-k])) % MOD)) % MOD;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int h, w, a, b; 
	cin>>h>>w>>a>>b;

    f[0] = 1;
    for (long long i=1; i<=N; i++)
        f[i] = (f[i-1]*i) % MOD;

    long long res = 0;
    long long x = b;
    long long y = h-a-1;
    
    while (x <= w-1 && y >= 0){
        long long c = bin_coef(x+y, x);
        long long d = bin_coef(w-1-x+h-1-y, w-1-x);
        res += (c * d) % MOD;
        res %= MOD;
        x++;
        y--;
    }
    cout << res;
}
