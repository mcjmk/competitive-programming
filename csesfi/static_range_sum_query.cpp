#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, q; 
	cin >> n >> q;
    
    int x;
    vector<int>pref(n+1);
    for (int i=1; i<=n; i++){
        cin >> x;
        pref[i] = pref[i-1] + x;
    }

    int a,b;
    while (q--){
        cin >> a >> b;
        cout<< pref[b] - pref[a-1] << "\n";
    }
}
