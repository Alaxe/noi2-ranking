
#include<bits/stdc++.h>
using namespace std;
vector <int> indeksi[30];
long long i,j;
bool imaLi;
string s,a,l="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int main ()

{
cin>>s;
a=s;
for(i=0;i<s.size();i++){
indeksi[s[i]-'A'].push_back(i);
}
char g=0;
for(i=0;i<26;i++){
    for(j=0;j<indeksi[i].size();j++){
    a[indeksi[i][j]]=l[g];
    imaLi=true;
    }
    if(imaLi){
     g++;
    }
    imaLi=false;
}
g=25;
for(i=25;i>=0;i--){

    for(j=0;j<indeksi[i].size();j++){
    s[indeksi[i][j]]=l[g];
    imaLi=true;
    }
    if(imaLi){
     g--;
    }
    imaLi=false;
}
cout<<a<<"\n"<<s<<"\n";
    return 0;
}
