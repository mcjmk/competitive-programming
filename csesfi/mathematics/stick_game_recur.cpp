#include <bits/stdc++.h>
using namespace std;
 
constexpr int N = 1e6+3;
bool answered[N];
bool win[N];
 
vector<int>p;
 
bool check(int n){
	if (answered[n]) return win[n];
	if (n==0) return false;
	
	bool is_win=false;
	for (int i=0; i<p.size(); i++){
		if (n-p[i] >= 0)
			is_win = is_win || !check(n-p[i]);
	}
	answered[n] = true;
	win[n] = is_win;
	return is_win;
}
 
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int n, k; 
	cin>>n>>k;
	
	p.resize(k);
	for (int i=0; i<k; i++) cin>>p[i];
	
 
	for (int i=1; i<=n; i++){
		cout<<(check(i) ? 'W' : 'L');
	}
}
