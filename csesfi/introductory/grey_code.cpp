#include <bits/stdc++.h>
using namespace std;

bitset<65540>vis;

void search(int k, int n){
	vis[k] = 1; 
	for (int i=n-1; i>=0; i--)
		cout<<bool(k & (1<<i));
	cout<<"\n";

	for (int i=0; i<n; i++){
		if (!vis[k ^ (1<<i)]){ 
			search(k ^ (1<<i), n);
			break;	
		}
	} 
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
 
	int n;
	cin>>n;
	search(0, n);

}
