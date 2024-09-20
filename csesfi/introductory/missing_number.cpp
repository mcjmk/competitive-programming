#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    int xorr = 0;
    int x;
 
    for (int i=1; i<= n-1; i++){
        cin>>x;
        xorr = xorr^x^i;
    }
 
    xorr = xorr ^ n;
    cout<<xorr;
}