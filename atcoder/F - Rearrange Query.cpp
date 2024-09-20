#include <bits/stdc++.h>
using namespace std;

const long long p = 1e5 + 7, mod = 1e9 + 9; 

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n,q; 
	cin >> n >> q;
	
	vector<int>a(n), b(n);
	unordered_map<int, long long>m;
	vector<long long> pref_a(n+1), pref_b(n+1);

	long long last_prime=p;

	for (int i=0; i<n; i++){
		cin >> a[i];
		if (!m.count(a[i])){
			last_prime = (last_prime * p) % mod;
			m[a[i]] = last_prime;
		}
	}	

	for (int i=0; i<n; i++){
		cin >> b[i];
		if (!m.count(b[i])){
			last_prime = (last_prime * p) % mod;
			m[b[i]] = last_prime;
		}
	}

	for (int i=0; i<n; i++){
		pref_a[i+1] = (pref_a[i] + m[a[i]]) % mod;
		pref_b[i+1] = (pref_b[i] + m[b[i]]) % mod;
	}

	int l, r, L, R;
	for (int i=0; i<q; i++){
		cin>>l>>r>>L>>R;
		long long pref1 = ((pref_a[r] - pref_a[l-1]) + mod) % mod;
		long long pref2 = ((pref_b[R] - pref_b[L-1]) + mod) % mod;
		cout<< (pref1 == pref2 ? "Yes" : "No") << "\n";
	}
}
