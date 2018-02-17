#include<bits/stdc++.h>
using namespace std;
int number(int a,int b,int c){c=0;
while(a!=0){if(a%10==b)c=1;
a=a/10;}
return c;}
int main(){
int n,l,s,i,c;
cin>>n>>l;
int a[l];
s=0;
i=0;
c=0;
for(int i=0;i<l;i++){cin>>a[i];}
if(l==1){while(n!=0){s=s+1;
if(number(s,a[0],c)==1)n=n+1;
n=n-1;}
cout<<s<<endl;
}
else if(l==2){while(n!=0){s=s+1;
if((number(s,a[0],c)==1)or(number(s,a[1],c)==1))n=n+1;
n=n-1;}
cout<<s<<endl;
}
else if(l==3){while(n!=0){s=s+1;
if((number(s,a[0],c)==1)or(number(s,a[1],c)==1)or(number(s,a[2],c)==1))n=n+1;
n=n-1;}
cout<<s<<endl;
}
return 0;
}
