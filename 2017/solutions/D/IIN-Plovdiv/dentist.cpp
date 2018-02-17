#include<bits/stdc++.h>
#include<string>
#include<cmath>
using namespace std;
int main()
{
    long long a[100000],b[100000],c[10000],i=0,Last_Ar=0,Last_W,k,br=1;
    while(cin>>a[i]>>b[i])
    {
        if(Last_Ar<a[i]) {Last_Ar=a[i];Last_W=b[i];}
        if(Last_W==30) break;
        cin>>a[i]>>b[i];
        if(Last_Ar<a[i]) {Last_Ar=a[i];Last_W=b[i];}
        if(Last_W==30) break;
        i++;
        br++;
    }

   cout<<Last_W<<endl;
   return 0;


}
