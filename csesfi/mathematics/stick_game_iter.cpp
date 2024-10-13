#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6+3;
bool win[N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k; 
	cin>>n>>k;
	
	vector<int>p(k);
	for (int i=0; i<k; i++) cin>>p[i];
	
	win[0] = false;
	for (int i=0; i<=n; i++){
		for (auto g: p){
			if (i + g <=n)
				win[i+g] = win[i+g] || !win[i];
		}
	}
	
	for (int i=1; i<=n; i++)
		cout<<(win[i] ? 'W' : 'L');
}
