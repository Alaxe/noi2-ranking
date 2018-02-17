#include<iostream>
using namespace std;
int main()
{
    long long n,a,b,c,d,br,ans;
    cin>>n;
    br=0;
    for(int i=4; i<=n*2; i++)
    {
        cin>>a>>b;
        cin>>c>>d;
         if(a==c)
         {
             br++;
         }
         else
         {
             if(a==d)
             {
                br++;
             }
             else
             {
                 if(b==c)
                 {
                     br++;
                 }
                 else
                 {
                     if(b==d)
                     {
                         br++;
                     }
                 }

             }
         }
     a=c;
     b=d;
     ans=br;
    }
    cout<<ans<<endl;
    return 0;
}
