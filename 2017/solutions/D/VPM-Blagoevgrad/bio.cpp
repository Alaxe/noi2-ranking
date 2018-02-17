 #include<bits/stdc++.h>
 using namespace std ;

 int main(){
     ios_base::sync_with_stdio(0);
int a,b,b1,c,c1,s,s1;
unsigned long long a1;
char k,k1,k2,k3;
cin>>a>>k>>a1>>b>>k1>>b1>>c>>k2>>c1>>s>>k3>>s1;
int d[13]={0,31,59,90,120,151,181,212,243,273,304,334,365};
a1=d[a1-1]+a;
b1=d[b1-1]+b;
c1=d[c1-1]+c;
s1=d[s1-1]+s;
//cout<<a1<<" "<<b1<<" "<<c1<<" "<<s1;
while(1>0)
{
   a1+=23;
   if((a1-b1)%28==0 and (a1-c1)%33==0)
   {
       break;
   }
}
cout<<a1-s1<<endl;
     return 0;
 }
/*
1/1 1/1 1/1 1/1
*/
/*
23/7 29/10 23/7 10/2
*/
