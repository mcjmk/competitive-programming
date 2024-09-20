#include <bits/stdc++.h>
using namespace std;
 
int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int n, x;
	cin>>n>>x;
 
    multiset<int>s;
 
	int p;
	for (int i=0; i<n; i++){
		cin>>p;
        s.insert(p);
	}
	
	int res=0;
    
    while (s.size()){
        auto last = s.rbegin(); 
        int max_weight = *last;
        s.erase(s.find(*last));
        res++;
        
        auto max_suitable = s.upper_bound(x-max_weight);
        if (max_suitable != s.begin()){
            max_suitable--;
            s.erase(max_suitable);
        }
    }
    cout<<res;
}