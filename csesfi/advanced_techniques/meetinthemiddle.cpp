#include <bits/stdc++.h>
using namespace std;
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int n, x; 
	cin>>n>>x;
 	vector<int>v(n);
	
	for(int i=0; i<n; i++) cin>>v[i];    
 
    vector<long long>sums;
    for (int b=0 ; b<(1<<(n/2)); b++){
        long long sum = 0;
        for (int i=0; i<(n/2); i++)
            if (b & (1<<i)) sum += v[i]; 
        sums.push_back(sum);
    }
    sort(sums.begin(), sums.end());
    
	long long ans = 0;
    for (int b=0; b<(1<<(n-(n/2))); b++){
        long long sum = 0; 
        for (int i=0; i<n-(n/2); i++)
            if (b & (1<<i)) sum += v[i+(n/2)];
      
        auto g = lower_bound(sums.begin(), sums.end(), x-sum);
        auto h = upper_bound(sums.begin(), sums.end(), x-sum);
        ans += h-g;
    }
    cout<<ans;
}
