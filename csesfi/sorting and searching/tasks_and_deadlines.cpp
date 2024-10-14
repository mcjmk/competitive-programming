#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; 
	cin>>n;
    
    vector<pair<int,int>>dane;
    int a, d;
    for (int i=0; i<n; i++){
        cin>>a>>d;
        dane.push_back({a,d});
    }
    
    sort(dane.begin(), dane.end());

    long long time=0;
    long long rew=0;

    for (auto g: dane){
        time += g.first;
        rew += g.second - time;
    }
    cout<<rew;
}
