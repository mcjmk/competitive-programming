#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin >> n;

	vector<int>x(n);
	for (int i=0; i<n; i++) cin >> x[i];
	
	stack<pair<int,int>>st;
	st.push({0, 0});
	for (int i=0; i<n; i++){
		pair<int,int>g = st.top();
		while (g.first >= x[i]){
			st.pop();
			g = st.top();
		}
		st.push({x[i], i+1});
		cout << g.second<<" ";
	}
}
