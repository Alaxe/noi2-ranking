#include<bits/stdc++.h>
using namespace std;
vector<char> v;
int mi;
char m,vecheUV[256][256],iKnow[256];
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ios_base::sync_with_stdio(false);
cout.tie(NULL);
string a;
cin>>a;
for(int i=0;i<a.size();i++){
    int br=0;
    if(iKnow[a[i]]!=0){
        v.push_back(iKnow[a[i]]);
    }else{
    for(int i1=0;i1<v.size();i1++){
        if(a[i]>a[i1]){
            br++;
            vecheUV[i][a[i1]]=1;
        }else{
            if(a[i]!=a[i1] and vecheUV[i1][a[i]]==0){
                v[i1]++;
                iKnow[a[i1]]++;
                vecheUV[i1][a[i]]=1;
            }
        }
    }
        v.push_back('A'+br);
        iKnow[a[i]]='A'+br;
    }
}
for(int i=0;i<v.size();i++){
    cout<<v[i];
    if(m<v[i]){
        m=v[i];
        mi=i;
    }
}
int M='Z'-v[mi];
for(int i=0;i<v.size();i++){
    v[i]+=M;
}
cout<<endl;
for(int i=0;i<v.size();i++){
    cout<<v[i];
}
cout<<endl;
return 0;
}
