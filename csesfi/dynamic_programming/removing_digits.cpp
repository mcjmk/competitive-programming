#include <bits/stdc++.h>
using namespace std;

int solve(int x){
	if (x==0) return 0;
	if (x <= 9) return 1;
	
	int max_digit = x % 10;
	int k = x;
	while (k){
		max_digit = max(max_digit, k % 10);
		k = k / 10;
	}
	return 1 + solve(x-max_digit);
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; 
	cin>>n;

	cout<<solve(n);
}
