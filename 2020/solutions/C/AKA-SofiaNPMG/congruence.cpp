#include<bits/stdc++.h>
using namespace std;
char v[15000000],v1[15000000],w[15000000],W[15000000];
int main(){
    int n;
    int bukvi=0,bukvaPoGolemina[26];
    bool bukva[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    for(n=-1;v[n]!='\n';){
        n++;
        cin.get(v[n]);
        if(bukva[v[n]-'A']==0){bukvi++;bukva[v[n]-'A']=1;}
    }
    for(int m=0,n1=1;m<26;m++){
        if(bukva[m]==1){bukvaPoGolemina[m]=n1;n1++;}
    }
    for(int m=0;m<n;m++){
        W[m]='Z'-(bukvi-bukvaPoGolemina[v[m]-'A']);
    }
    for(int m=0;m<n;m++){
        w[m]='A'+bukvaPoGolemina[v[m]-'A']-1;
    }
    cout<<w<<'\n'<<W;
    return 0;
}
