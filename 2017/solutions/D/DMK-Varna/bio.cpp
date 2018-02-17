#include <bits/stdc++.h>
using namespace std;
int main()
{
   int j=2,i=0,a,b,c,d,a2,b2,c2,d2,e,sum1[10]={0},sum=0,br=0,pom=0;
   int mas[12]={31,28,31,30,31,30,31,31,30,31,30,31};
   char a1,b1,c1,d1;
   pom=21252;
   cin>>a>>a1>>a2>>b>>b1>>b2>>c>>c1>>c2>>d>>d1>>d2;
   if (a==b && b==c && c==d && a2==b2 && b2==c2 && c2==d2)
   {
       while (i+1!=d2)
       {
           sum+=mas[i];
           i++;
       }
       sum+=d;
       cout<<pom-sum+1<<endl;
   }
   else
   {
       while (i+1!=a2)
       {
           sum1[0]+=mas[i];
           i++;
       }
       sum1[0]+=a;
       i=0;
       while (i+1!=b2)
       {
           sum1[1]+=mas[i];
           i++;
       }
       sum1[1]+=b;
       i=0;
       while (i+1!=c2)
       {
           sum1[2]+=mas[i];
           i++;
       }
       sum1[2]+=c;
       i=0;
       while (i+1!=d2)
       {
           sum1[3]+=mas[i];
           i++;
       }
       sum1[3]+=d;

       cout<<sum1[0]<<endl;
    }

}



