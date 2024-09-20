#include <bits/stdc++.h>
using namespace std;
 
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    int n, x;
    cin>>n;
    set<int> numbers;
    for (int i=0; i<n; i++){
        cin>>x;
        numbers.insert(x);
    }
    cout<<numbers.size();
}