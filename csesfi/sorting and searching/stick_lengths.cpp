#include <bits/stdc++.h>
using namespace std;
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n;
    cin>>n;
    
    vector<int>p;
    int x;
    
    for (int i=0; i<n; i++){
        cin>>x;
        p.push_back(x);
    }
    
    sort(p.begin(), p.end());
    int med = p[n/2];
    long long res=0;
 
    for (int i=0; i<n; i++)
    	res += abs(med-p[i]);
    
    cout<<res;
}