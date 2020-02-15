#include <bits/stdc++.h>
using namespace std;
string s;
vector<pair <int,int> > v;
int main(){
    getline(cin,s);
    int t;
    for(int i=0;i<s.size();i++){
        t=s[i]-'A';
        v[i]=make_pair(t,i);
    }
    /**
    for(int i=0;i<v.size();i++){
        cout<<v[i].first;
    }
    */
    sort(v.begin(),v.end());
    int ii=0;
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1].first==v[i].first){
            //v[i+1].first-=((v[i+1].first-v[i].first)+1);
            v[i].first=ii;
        }else{
            v[i].first=ii;
            ii++;
        }
    }
    v[v.size()-1].first=ii;
    for(int i=0;i<v.size();i++){
        swap(v[i].first,v[i].second);
    }
    sort(v.begin(),v.end());
    char ch;
    for(int i=0;i<v.size();i++){
        ch=v[i].second+'A';
        cout<<ch;
    }
    cout<<"\n";
    return 0;
}
