#include <bits/stdc++.h>
using namespace std;

int count_letters[30];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin>>s;
	sort(s.begin(), s.end());
	set<string>strings;
	do {
		strings.insert(s);
	}
	while (next_permutation(s.begin(), s.end()));
	cout<<strings.size()<<endl;
	for (auto g: strings)
		cout<<g<<endl;
		
}