#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	cin>>n; 
    
    if (n % 4 == 1 || n % 4 == 2)
        cout<<"NO";

    else {
        cout<<"YES\n";

        long long sum=((long long)(n)*(long long)(n+1))/4;
        vector<int>first_set, second_set;

        for (int i=n; i>= 1; i--){
            if (sum >= i){
                sum -= i; 
                first_set.push_back(i);
            }
            else {
                second_set.push_back(i);
            }
        }

        cout<<first_set.size()<<"\n";
        for (int i=first_set.size()-1; i>=0; i--)
            cout<<first_set[i]<<" ";
        cout<<"\n"<<second_set.size()<<"\n";

        for (int i=second_set.size()-1; i>=0; i--)
            cout<<second_set[i]<<" ";
    }
}
