#include<bits/stdc++.h>
using namespace std;

bool solve(){
    string s;
    cin>>s;
    bool char_set[128]={1};
    if(s.length()>128)
    return false;
    for(auto it:s)
    {
        //cout<<it<<" ";
        if(char_set[it])
        return false;
        char_set[it]=true;
    }
    return true;
}



int main(){
    int t;
    cin>>t;
    while(t--){
       cout<< solve()<<"\n";
    }
    return 0;
}