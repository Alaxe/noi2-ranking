#include<iostream>
#include<string>
using namespace std;
int main()
{
 int k,m,s=0,i,a,r,minr=999999,j=0;
 cin>>k>>m;
 for(i=1;i<=200;i++)
 {
 cin>>a;
 if(a>k)r=a-k;
 else r=k-a;
 if(r<=minr){minr=r;j=i;}
 if(a%2==0)s+=a;
 if(i==200){cout<<j<<" "<<s<<endl;break;}
 if(s>=m){cout<<j<<" "<<s<<endl;break;}

 }


return 0;
}
