
#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, x; 
	cin>>n>>x;
    
    vector<int>a(n);
    for (int i=0; i<n; i++) 
        cin>>a[i];

    int l=0, r=0, count=0;

    long long sum=0;

    while (l < n){
        while (r < n && sum < x){
            sum += a[r];
            r++;
        }
        
        if (sum == x)
            count++;
        
        sum -= a[l];
        l++;
        
    }
    
    cout << count;
}
