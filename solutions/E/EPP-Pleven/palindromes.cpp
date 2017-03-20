#include<iostream>
using namespace std;
int main()
{
    long long n,ans,ans1,ans2,ed,des,sto,hil,deshil,stohil,br;
    cin>>n;
    for(int i=n-1; i>0; i--)
    {
        for(int x=i-1; x>0; x--)
             ans1=i*x;
             ans2=ans1;
             ed=ans2%10;
             des=(ans2/10)%10;
             sto=(ans2/100)%10;
             hil=(ans2/1000)%10;
             deshil=(ans2/10000)%10;
             stohil=(ans2/100000)%10;
             if(stohil and deshil and hil and sto and des==0)
             {
                 br++;
             }
             if(stohil and deshil and hil and sto==0)
             {
                 if(ed==des)
                 {
                     br++;
                 }
             }
             if(stohil and deshil and hil==0)
                {
                    if(ed==sto)
                    {
                        br++;
                    }
                }
                if(stohil and deshil==0)
                {
                    if(ed==hil and des==sto)
                    {
                        br++;
                    }
                }
                if(stohil==0)
                {
                    if(deshil==ed and hil==des)
                    {
                        br++;
                    }
                }
                if(stohil==ed and deshil==des and hil==sto)
                {
                    br++;
                }
                    if(stohil>0)
                    {  if(stohil>0)
                    ans1=stohil==ed and deshil==des and hil==sto;
                    }
                    if(ans1%2==0)
                    {
                        ans=ans1/2;
                        cout<<2<<" "<<ans<<endl;
                        cout<<ans1<<endl;
                        return 0;
                    }
                    else
                    {
                        ans=ans1/3;
                        cout<<3<<" "<<ans<<endl;
                        cout<<ans1;
                    }

                }
}
