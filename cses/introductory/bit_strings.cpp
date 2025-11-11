#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n;
    int modulo = 1e9+7;
 
    cin>>n;
    int res = 1;
 
    for (int i=0; i<n; i++){
        res = (res*2) % modulo;
    }
    cout<<res;
 
 
    return 0;
}