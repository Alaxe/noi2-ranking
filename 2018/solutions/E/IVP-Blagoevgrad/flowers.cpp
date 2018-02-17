#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
int n,q,i,b;
unsigned long long s;
cin>>n;
i=0;
s=0;
b=0;
for(int i=0;i<n;i++){cin>>a[i];
if(b<a[i])b=a[i];
}
cin>>q;
for(int i=0;i<n;i++){s=s+(b-a[i])*q;}
cout<<s<<endl;
return 0;
}
