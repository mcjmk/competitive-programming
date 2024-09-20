#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
	int t, a, b;
	cin>>t;
	while (t--) {
        cin >> a >> b;
        if (2*b - a >= 0 && ((2*b - a) % 3 == 0) && (2*a - b >= 0) && ((2*a - b) % 3 == 0)) 
        	cout << "YES\n"; 
		else
			cout<<"NO\n";
	}
	return 0;
}