#include <bits/stdc++.h>
using namespace std;
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int n;
	cin>>n;
	
	vector<int>v(n);
 
	long long sum=0;
	for(int i=0;i<n; i++){
		cin>>v[i];
		sum += v[i];
	}
	
	long long res = sum;
 
	for (int b=0; b<(1<<n); b++) {
		long long sum1=0, sum2=0;
		for (int i=0; i<n; i++){
			if (b&(1<<i)) sum1 += v[i];
			else sum2 += v[i];
 
		}	
		res = min(res, abs(sum1-sum2));
	}
	cout<<res;
}