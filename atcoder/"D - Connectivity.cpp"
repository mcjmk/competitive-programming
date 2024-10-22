#include <bits/stdc++.h>
using namespace std;

constexpr int N=2e5+3;

int LINK[N][2];
int SIZE[N][2];

int FIND(int a, int which){
	if (a != LINK[a][which]) 
		a = LINK[a][which] = FIND(LINK[a][which], which);
    return a;
}

void UNION(int a, int b, int which){
    a = FIND(a, which);
    b = FIND(b, which);
    if (SIZE[a][which] < SIZE[b][which])
            swap(a,b);
    LINK[b][which] = a;
    SIZE[a][which] += SIZE[b][which];
}


int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

    int n, k, l;
    cin >> n >> k >>l;

    for (int i=1; i<=n; i++){
        LINK[i][1] = LINK[i][0] = i;
        SIZE[i][1] = SIZE[i][0] = 1;
    }

    int p,q,r,s; 
    for (int i=0; i<k; i++){
       cin>>p>>q; 
       UNION(p, q, 0);
    }

    for (int i=0; i<l; i++){
       cin>>r>>s;
       UNION(r, s, 1); 
    }

    map<pair<int, int>, int>m;
    
    for (int i=1; i<=n; i++)
        m[{FIND(i,0), FIND(i,1)}] += 1;
    
    for (int i=1; i<=n; i++)
        cout << m[{FIND(i,0), FIND(i,1)}] <<" ";
}
