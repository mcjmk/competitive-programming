#include <bits/stdc++.h>
using namespace std;
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0); 
    int n;
    cin>>n;
	
	long long count2=0, count5=0;
	for (int i=n; i>0; i=i/2)
		count2 += i/2;
 
	for (int i=n; i>0; i=i/5)
		count5 += i/5;
 
	cout<<min(count2,count5);
}