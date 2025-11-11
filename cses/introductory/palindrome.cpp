#include <bits/stdc++.h>
using namespace std;
 
 
int count_letters[30];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin>>s;
 
    for (int i=0; i<s.size(); i++)
        count_letters[s[i]-'A']++;
    
 
    int how_many_odd = 0;
 
    for (int i=0; i<28; i++){
        if (count_letters[i] % 2 == 1)
            how_many_odd++;
    }
 
    if (how_many_odd > 1){
        cout<<"NO SOLUTION";
        return 0;
    }
 
    vector<char>palindrome(s.size());
    int j =0;
    for (int i=0; i<28; i++){
        while (count_letters[i] > 1){
            palindrome[j] =(char)('A'+i);
            palindrome[s.size()-1-j] = (char)('A'+i);
            count_letters[i] -=2;
            j++;
        }
        if (count_letters[i] == 1){
            palindrome[s.size()/2] = (char)('A' + i);
            count_letters[i] --;
        }
    }

    for (auto g: palindrome)
        cout<<g;
}