#include <bits/stdc++.h> 
using namespace std;

const long long MOD = 1'000'000'007LL;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k; 
	cin>>n>>k;

	 
	vector<long long>v(n);
	for (int i=0; i<n; i++)
		cin>>v[i];
 
 	if (n == k){
		long long res = 1;
		for (auto g: v){
			res *= g;
			res %= MOD;
		}
		cout<<(res + MOD) % MOD;
		return 0;
	}

	vector<long long>pos, neg;
	for (auto g: v){
		if (g>0)
			pos.push_back(g);
		else
			neg.push_back(g);
	}
	
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());  
	long long res=1; 
	int i=0, j=0; 

	bool maximizing=0;

	if (k%2){
		if (pos.size())
			maximizing = ((pos.size()-1)/2 + (neg.size()/2)) >= (k-1) /2 ;
	}
	
	else 
		maximizing = ((pos.size()) /2 + (neg.size()/2)) >= k /2 ;


	if (maximizing) { // maximazing abs(product) 
		if (k % 2){
			res = pos[0];
			i++;
			k--;
		}
		while (k > 0){
			if (i+1 < pos.size()  && j+1 < neg.size()){
				if (pos[i] * pos[i+1] >= neg[j] * neg[j+1]){
					res *= (pos[i]*pos[i+1]) % MOD;
					res = (res + MOD) % MOD;
					i+=2; 
				}
				else  {
					res *= (neg[j] * neg[j+1]) % MOD; 
					res = (res + MOD) % MOD;
					j+=2; 
				}
			}
			else if (i+1 < pos.size()) {
				res *= (pos[i]*pos[i+1]) % MOD;
				res = (res + MOD) % MOD;
				i += 2;
			}
			else if (j+1 < neg.size()) {
				res *= (neg[j]*neg[j+1]) % MOD;
				res = (res + MOD) % MOD;
				j += 2; 
			}
			k-=2;   
		}
	} 
	
	else { // minimazing abs(product) 
		vector<pair<long long, long long>>v;
		
		j=neg.size()-1;  
		while (j >= 0 && neg.size()-(j+1) <= k){
			v.push_back({abs(neg[j]), neg[j]});
			j--;
		}
		
		if (pos.size()) {
			i=pos.size()-1;   
			while (i >= 0 && pos.size()-(i+1) <= k){
				v.push_back({abs(pos[i]), pos[i]});
				i--;
			} 
		}
		
		sort(v.begin(), v.end()); 
		for (int l=0; l<k; l++)
			res = ( (res * v[l].second) + MOD) % MOD;  
		
	}
	
	cout<<res;
}
