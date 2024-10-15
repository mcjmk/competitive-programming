#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int pref[N][N];

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, q; 
	cin>>n>>q;

    char czar;
    for (int y=1; y<=n; y++){
        for (int x=1; x<=n; x++){
           cin>>czar; 
           pref[y][x] = pref[y-1][x] + pref[y][x-1] - pref[y-1][x-1] + (czar=='*');
        }
    }

    int x1, x2, y1, y2;
    while (q--){
        cin>>y1>>x1>>y2>>x2;

        int res = pref[y2][x2] - pref[y1-1][x2] - pref[y2][x1-1] + pref[y1-1][x1-1];
        cout<<res<<"\n";

    }
}
