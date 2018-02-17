#include <iostream>
#define Int_max unsigned long long int
using namespace std;
Int_max  s,t,z;
Int_max  k,ans=0;
Int_max  br_check(Int_max  n)
{
    Int_max  answer=0;
    k=n;
    Int_max ch=0;
    while(k!=0)
    {
        if(k%2==0)answer++;
        ch=k%2;
        k=k/2;
    }
    if(ch==0)answer--;
    if(answer<0)answer=0;
    return answer;
}
int main()
{
    cin>>s>>t>>z;
    for(Int_max  i=s;i<=t;i++)
    {
        if(br_check(i)==z)
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
