#include <bits/stdc++.h>
using namespace std;

const long long p = 997;
const long long MOD = 1e9+9;

long long pot[1000006];
long long hasz[1000006];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	string text, pattern;
	cin>>text;

	cin>>pattern;

	if (pattern.size() > text.size()){
		cout<<0;
		return 0;
	}

	pot[0]=1;
    
	for (int i=1; i<=text.size(); i++){
		hasz[i] = (hasz[i-1]*p + int(text[i-1])) % MOD;
		pot[i] = (pot[i-1]*p) % MOD;
	}

	long long pattern_hash = 0;
	for (int i=1; i<=pattern.size(); i++)
		pattern_hash = (pattern_hash * p + int(pattern[i-1])) % MOD;
	
	int res=0;

	for (int i=1; i<=text.size()-pattern.size()+1; i++){
		int a = i;	
		int b = i+pattern.size()-1;
		int current_hash = ((hasz[b] - (hasz[a-1] * pot[b-a+1]) % MOD) % MOD + MOD) % MOD;
		if (current_hash == pattern_hash)
			res++;
	}
	
	cout<<res;
}
