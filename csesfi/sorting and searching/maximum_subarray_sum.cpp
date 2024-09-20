#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n;
    cin>>n;
    ll x;
    cin>>x;
    ll res=x, max_sum=x;
    
    for (int i=0; i<n-1; i++){
        cin>>x;
        max_sum=max(max_sum+x, x);
        res= max(max_sum, res); 
    }
    cout<<res;
}