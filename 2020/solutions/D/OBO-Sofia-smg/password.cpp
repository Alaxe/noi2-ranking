#include<bits/stdc++.h>
using namespace std;
int b[26],br=1,n,bukva=-1,bpnb,lop=10;
string a;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a;
    n=a.size();
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])br=1;
        if(a[i]==a[i-1])br++;
        if(br==3){
            b[a[i]-'a']--;
            while(b[lop%26]>=n/2)lop++;
            a[i]=lop%26+'a';
            b[lop%26]++;
            br=1;
        }
    }
    for(int i=0;i<26;i++){
        if(b[i]>n/2){
            bukva=i;
            bpnb=b[i]-n/2;
        }
    }
    lop = 4;
    for(int i=0;i<n;i++){
        if(a[i]==bukva+'a' && bpnb>0){
            b[a[i]-'a']--;
            while(b[lop%26]>=n/2)lop++;
            a[i]=lop%26+'a';
            b[lop%26]++;
            bpnb--;
        }
    }
    lop=67;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])br=1;
        if(a[i]==a[i-1])br++;
        if(br==3){
            b[a[i]-'a']--;
            while(b[lop%26]>=n/2)lop++;
            a[i]=lop%26+'a';
            b[lop%26]++;
            br=1;
        }
    }
    cout<<a<<endl;
    return 0;
}
