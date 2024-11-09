#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
    
    int q, k;
    cin >> q >> k;
    
    vector<int>dp(k+1);
    dp[0] = 1;
    char czar;
    int x;
    while (q--){
        cin >> czar >> x;
        if (czar == '+'){
            for (int i=k; i>=x; i--){
                dp[i] = (dp[i] + dp[i-x]) % MOD;
            }
        }
        else {
            for (int i=x; i<=k; i++){
                dp[i] = ((dp[i]-dp[i-x]) % MOD + MOD) % MOD;
            }
        }
        cout << dp[k] << "\n";
    }
}
