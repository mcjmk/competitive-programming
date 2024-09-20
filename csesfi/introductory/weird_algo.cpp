#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
	long long n;
	cin>>n;
 
    while (n!= 1){
        cout<<n<<" ";
		if (n%2)
			n = 3*n +1;
		else
			n = n/2;
	}
    cout<<1;
}
