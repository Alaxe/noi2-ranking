#include<bits/stdc++.h>
#define nl '\n'
using namespace std;

string s;

bool used[26];
int minV[26];
int ul=0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        char c=s[i];
        int ci=c-'A';
        if(!used[ci]){
            ul++;
            used[ci]=true;
        }
    }
    int cv=1;
    for(int i=0;i<26;i++){
        if(used[i]){minV[i]=cv++;}
        else{minV[i]=-1;}
        //cout<<char(i+'A')<<' '<<minV[i]<<nl;
    }
    for(int i=0;i<s.size();i++){
        //cout<<s[i]<<' ';
        cout<<char(minV[s[i]-'A']+'A'-1);
    }
    cout<<nl;
    for(int i=0;i<s.size();i++){
        cout<<char(minV[s[i]-'A']+('Z'-ul));
    }
    cout<<nl;
}
