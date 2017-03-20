#include<iostream>
using namespace std;
long long k[9999999],m[9999999],c,i,sum=0,br=1,br2=0;
int main()
{
    cin>>c>>k[0]>>m[0];
    for(i=1;i<c;i++)
    {
     cin>>k[i]>>m[i];
     if(k[i]<=k[i-1] && m[i]<=m[i-1]) br++;
       else if(k[i]<=m[i-1] && m[i]<=k[i-1]) br++;
       else if(br2<=br)
       {br2=br+1;
       br=0;
       }
       else br=0;
    }
cout<<br2<<endl;


}
