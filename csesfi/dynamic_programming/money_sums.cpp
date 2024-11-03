#include <bits/stdc++.h>
using namespace std;
 
set<int>sums;

int main(){
	cin.tie(0); 
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int>x(n);
	for (int i=0; i<n; i++) 
		cin >> x[i];


	for (auto g: x){
		stack<int>to_add;
		for (auto s: sums)
			to_add.push(s + g);
		sums.insert(g);
		while (!to_add.empty()){
			int t = to_add.top();
			to_add.pop();
			sums.insert(t);
		}
	}

	cout << sums.size() << "\n";
	for (auto s: sums)
		cout << s << " ";

}
