#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    long long n, x;
    cin >> n >> x;
    
    vector<long long>a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
 
    map<long long, long long>counts;
    long long ans = 0, pref = 0;
 
    counts[0] = 1;
 
    for (int i = 0; i < n; i++){
        pref += a[i];
        ans += counts[pref - x];
        counts[pref]++;
    }
 
    cout << ans;
}
