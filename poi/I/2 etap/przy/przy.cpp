#include <bits/stdc++.h>
using namespace std;


vector<int>G[100005];
vector<int>ODWR[100005];
int koszt[100005];
int ile_poprzednikow[100005];
int ile_nastepnikow[100005];
int najwczesniej[100005];
int najpozniej[100005];
short vis[100005];

bool czy_cykl=0;
vector<int>odwrotny_topo_porz;
vector<int>do_startu, do_konca;


void dfs_topo (int v){
    vis[v]=1;
    for (int i=0; i<G[v].size(); i++){
        if (vis[G[v][i]] == 1){
            czy_cykl=1;
            break;
        }
        if (vis[G[v][i]]==0)
            dfs_topo(G[v][i]);
    }
    vis[v]=2;
    odwrotny_topo_porz.push_back(v);
}

vector<pair<int,int>>zapytania;

int main(){

    int n;
    //cin.tie(0);
   // cout.tie(0);
   // ios_base::sync_with_stdio(0);



    cin>>n;
    for (int i=1; i<=n; i++){
        int t,k;
        cin>>t>>k;
        koszt[i]=t;
        for (int j=0; j<k; j++){
            int x;
            cin>>x;
            G[x].push_back(i);
            ODWR[i].push_back(x);
            ile_poprzednikow[i]++;
            ile_nastepnikow[x]++;
        }
    }
     int m;
     cin>>m;
     for (int j=0; j<m; j++){
        int v, zwiekszenie;
        cin>>v>>zwiekszenie;
        pair<int,int>dane = {v, zwiekszenie};
        zapytania.push_back(dane);}


    for (int i=1; i<=n; i++){
        if (ile_nastepnikow[i] == 0)
            do_konca.push_back(i);
        if (ile_poprzednikow[i] == 0)
            do_startu.push_back(i);
    }

    for (int i=0; i<do_startu.size(); i++){
        G[0].push_back(do_startu[i]);
        ODWR[do_startu[i]].push_back(0);
    }

    for (int i=0; i<do_konca.size(); i++){
        G[do_konca[i]].push_back(100001);
        ODWR[100001].push_back(do_konca[i]);
    }

    odwrotny_topo_porz.push_back(100001);
    for (int i=1; i<=n; i++){
        if (vis[i] == 0)
            dfs_topo(i);
    }

    odwrotny_topo_porz.push_back(0);

    dfs_topo(0);
    if (czy_cykl){
        cout<<"CYKL";
        return 0;
    }


   // cout<<"TOPO PORZADEK!!: "<<endl;
   // for (int i=0; i<odwrotny_topo_porz.size(); i++){
     //   cout<<odwrotny_topo_porz[i]<<"  ";
  //  }
   // cout<<endl;
    //100001 - koniec, 0 - start


    for (int i=odwrotny_topo_porz.size()-1; i>=0; i--){
       // cout<<"rozpatruje : "<<odwrotny_topo_porz[i]<<endl<<" jego sasiedzi i ich koszty: ";
        for (int j=0; j<ODWR[odwrotny_topo_porz[i]].size(); j++){
           // cout<<ODWR[odwrotny_topo_porz[i]][j]<<" : "<<koszt[ODWR[odwrotny_topo_porz[i]][j]]<<" ";
           // cout<<" jego obliczony wynik " <<najwczesniej[ODWR[odwrotny_topo_porz[i]][j]]<<",  ";
            najwczesniej[odwrotny_topo_porz[i]] = max(najwczesniej[odwrotny_topo_porz[i]], najwczesniej[ODWR[odwrotny_topo_porz[i]][j]]+koszt[odwrotny_topo_porz[i]]);
        }
    }


    cout<<najwczesniej[100001]<<endl;

    for (int i=0; i<=n; i++){
        najpozniej[i] = INT_MAX - 1000;
    }

    najpozniej[100001] = najwczesniej[100001];

    for (int i=0; i<odwrotny_topo_porz.size(); i++){
        for (int j=0; j<G[odwrotny_topo_porz[i]].size(); j++)
            najpozniej[odwrotny_topo_porz[i]] = min(najpozniej[odwrotny_topo_porz[i]], najpozniej[G[odwrotny_topo_porz[i]][j]] - koszt[G[odwrotny_topo_porz[i]][j]]);
    }
    for (int i=0; i<zapytania.size(); i++){
        int luz = najpozniej[zapytania[i].first] - najwczesniej[zapytania[i].first];
        if (luz >= zapytania[i].second)
            cout<<"NIE\n";
        else
            cout<<"TAK\n";
    }

}
