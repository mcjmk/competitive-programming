#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, x; 
	cin >> n >> x;
	
	if (n == 1 && x == 1)
		cout << "Yes\n" << 1;
	
	else if (x == 1 || x == 2*n-1)
		cout<<"No\n";

	else {
		vector<int>v(2*n-1);
		v[n-1] = x;
		v[n] = x-1;
		v[n-2] = 2*n-1;
		
		int counter = 1;
		
		for (int i=0; i<2*n-1; i++){
			while (counter == v[n-1] || counter == v[n] || counter == v[n-2])
				counter++;
			if (i == n-2 || i == n-1 || i == n)
				continue;
			v[i] = counter;
			counter++;
		}
		
		cout<<"Yes\n";
		for (auto x : v)
			cout<<x<<"\n";
	}
}
