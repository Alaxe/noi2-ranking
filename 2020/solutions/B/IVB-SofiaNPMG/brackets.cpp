#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct skoba{
    bool vytreSlabo=0;
    bool vynSilno=0;
    bool otpredSkoba=0;
    bool spec=0;
    int nachalo;
    int krai;

    skoba(int nachalo1){
        nachalo = nachalo1;
    }
};
string s,s1;
vector<skoba> v;
vector<skoba> v1;
bool za1;
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();++i){
        if(s[i]=='('){
            v1.push_back({i});
            if(v1.size()>1){
                if(v1[v1.size()-2].nachalo==i-1)
                    v1[v1.size()-1].otpredSkoba=1;
            }
        }
        if(s[i]==')'){
            v1[v1.size()-1].krai=i;
            if(v1.size()>1 and
               v1[v1.size()-1].otpredSkoba and
               i+1<s.size() and
               s[i+1]==')'){
                s[v1[v1.size()-1].nachalo] = '0';
                s[i] = '0';
                za1=1;
            }
            v1.pop_back();
        }
    }

    for(int i=0;i<s.size();++i){
        if(s[i] =='('){
            v.push_back({i});
            if(i>0){
                if(s[i-1]=='*' or s[i-1]=='-' ){
                    v[v.size()-1].vynSilno=1;
                }
                if(s[i-1]=='/') v[v.size()-1].spec=1;
            }
        }
        else if(s[i] == ')'){
            if(i+1<s.size()){
                if(s[i+1]=='*' or s[i+1]=='/')v[v.size()-1].vynSilno=1;
            }
            v[v.size()-1].krai = i;
            if((v[v.size()-1].vynSilno and
               v[v.size()-1].vytreSlabo) or
               v[v.size()-1].spec){
                    s[v[v.size()-1].nachalo]='7';
                    s[i]='8';
               }
            v.pop_back();
        }
        else if((s[i]=='+' or s[i]=='-')&& v.size()>0){
            v[v.size()-1].vytreSlabo = 1;
        }
    }
    for(int i=0;i<s.size();++i){
        if(s[i]=='0' or s[i]==')' or s[i]=='('){
            continue;
        }
        else if(s[i]=='7')cout<<'(';
        else if(s[i]=='8')cout<<')';
        else  cout<<s[i];
    }
    cout<<'\n';
    return 0;
}

