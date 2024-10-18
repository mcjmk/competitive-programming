#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t, n; 
    cin>>t;
    while (t--){
	    cin>>n;
        int res=0;
        int x;
        for (int i=0; i<n; i++){
            cin>>x;
            res ^= x;
        }
        cout<<(res ? "first" : "second")<<"\n";
    }
}
