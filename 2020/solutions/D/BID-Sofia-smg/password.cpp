#include<bits/stdc++.h>
using namespace std;
int n, b[5000],br=1,brsresh[26];
string a;
void zamenqne(int index,char bukva){
    int nmbukv=5001;
    char nomer;
    for(int i = 0; i < 26 ; ++ i){
        if(i==bukva-'a')break;
        if(nmbukv>brsresh[i]){
             nomer='a'+i;
             nmbukv=brsresh[i];
        }
    }
    a[index]=nomer;
    brsresh[nomer-'a']++;
    return ;
}
int main(){
    cin>>a;
    n=a.size()-1;
    for(int i  = 0  ; i < n ; ++ i ){
        brsresh[a[i]-'a']++;
    }
    for(int i  =  n-1 ;  i > -1 ; -- i){
        if(a[i]==a[i+1])br++;
        else br=1;
        if(br%3==0)zamenqne(i,a[i]);
    }
    cout<<a<<endl;
    return 0;
}

