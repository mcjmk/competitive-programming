#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int t;
    cin>>t;
 
    long long x,y;
    while(t--){
        cin>>y>>x;
        long long a = max(x-1,y-1);
        long long res = a*a;
 
        if (a % 2 == 1){  // increasing from right-up
            res += (a+1-x) + (y-1) + 1;
        }
        else {     // increasing from left-down
            res += (x - 1) + (a+1-y) + 1;
        }
        cout<<res<<endl;
    }
 
	return 0;
}