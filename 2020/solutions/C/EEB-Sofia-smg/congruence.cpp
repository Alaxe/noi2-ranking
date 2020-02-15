#include <bits/stdc++.h>
using namespace std;
bool brB[26], k;
int main(){
char a[2076691], t;
cin.getline(a, 2076690);
vector<char> v;
int index=strlen(a), na, br=0;
for(int i=0; i<index; i++){
    na=a[i]-'A';
    if(brB[na]==0){
        br++;
    }
    brB[na]=1;
}
for(int j=0; j<26; j++){
    if(brB[j]==1){
        t='A'+j;
        v.push_back(t);
    }else{
        k=1;
    }
}
if(k==0){
    for(int i=0; i<index; i++){
        cout<<a[i];
    }
    cout<<endl;
    for(int i=0; i<index; i++){
        cout<<a[i];
    }
    return 0;
}
for(int i=0; i<index; i++){
    for(int j=0; j<br; j++){
        if(a[i]==v[j]){
            t='A'+j;
            cout<<t;
            j=br;
        }
    }
}
cout<<endl;
for(int i=0; i<index; i++){
    for(int j=0; j<br; j++){
        if(a[i]==v[j]){
            t='Z'-(br-j-1);
            cout<<t;
            j=br;
        }
    }
}
return 0;
}
