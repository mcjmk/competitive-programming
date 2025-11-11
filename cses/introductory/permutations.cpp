#include <bits/stdc++.h>
using namespace std;
 
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int n;
	cin>>n;
 
	if (n==1){
		cout<<1;
		return 0;
	}
 
	else if (n <= 3){
		cout<<"NO SOLUTION";
		return 0;
	}
 
	else {
		vector<int>solution(n);
		int pos=0;
		for (int i=2; i<= n; i+=2){
			solution[pos] = i;
			pos++;
		}
		for (int i=1; i<= n; i+=2){
			solution[pos] = i;
			pos++;
		}
		for (int i=0; i<n; i++){
			cout<<solution[i]<<" ";
		}
	}
	return 0;
}