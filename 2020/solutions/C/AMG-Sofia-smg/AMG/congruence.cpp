#include<bits/stdc++.h>
using namespace std;
string s;
bool br[27];
int rep[27];
int rep2[27];
int p[27],k;
int main(){
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>s;
for(int i=0;i<s.size();i++){
    br[s[i]-'A']=true;
}
for(int i=0;i<26;i++){
    if(br[i]){
       p[k]=i;
       k++;
    }
}
for(int i=0;i<k;i++){
    rep[p[i]]=i+'A';
    rep2[p[i]]='Z'-(k-i-1);
}
for(int i=0;i<s.size();i++){
   cout<<char(rep[s[i]-'A']);
}
cout<<"\n";
for(int i=0;i<s.size();i++){
   cout<<char(rep2[s[i]-'A']);
}
cout<<"\n";
return 0;
}
// CHECKED //

