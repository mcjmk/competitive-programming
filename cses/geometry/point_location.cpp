#include <bits/stdc++.h>
using namespace std;

typedef long long C;
typedef complex<C> P;
#define X real()
#define Y imag() 

long long cross_product(P a, P b){
	return (conj(a)*b).Y;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t;
	cin>>t;
	
	long long x[3], y[3];
	
	while(t--){
		cin>>x[0]>>y[0]>>x[1]>>y[1]>>x[2]>>y[2];
		long long val = cross_product({x[1]-x[0], y[1]-y[0]}, {x[2]-x[1], y[2]-y[1]});
		if (val < 0)
			cout<<"RIGHT";
		else if (val > 0)
			cout<<"LEFT";
		else {
			cout<<"TOUCH";
		}
		cout<<"\n";
	}
}
