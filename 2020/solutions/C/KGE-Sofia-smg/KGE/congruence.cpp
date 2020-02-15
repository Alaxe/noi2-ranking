#include<iostream>
using namespace std;
long long mas[15000000];
long long broi[26];
int main(){
string a;
cin>>a;
for(long long i=0;i<a.size();i++){
    broi[a[i]-'A']++;
}
long long cbor=0,obshto=0;
for(long long i=0;i<26;i++){
    obshto+=broi[i];
}
long long nai=0;
for(long long i=0;i<26;i++){
    if(broi[i]!=0){
        cbor++;
        broi[i]=cbor-1;
        if(broi[i]>nai){
            nai=broi[i];
        }
    }
}
string malko,golqmo;
for(long long i=0;i<a.size();i++){
    malko+=(broi[a[i]-'A']+'A');
}for(long long i=0;i<a.size();i++){
    golqmo+=('Z'-(nai-broi[a[i]-'A']));
}
cout<<malko<<endl;
cout<<golqmo<<endl;
return 0;
}
