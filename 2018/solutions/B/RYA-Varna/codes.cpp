#include <iostream>
#include <string>
using namespace std;
long long n,k,a,b;
int digits[110],num[10010],prev[10010];
int main()
{
    cin>>n>>k>>a>>b;
    long long i,j,br,m,stepen,st[10010],u;
    long long maxdif=0;
    string s1,s2,ans;
    for(i=0;i<n;i++)
    {
        cin>>digits[i];
    }
    stepen=k;
    i=2;
    st[0]=1;
    st[1]=n;
    while(st[i-1]*n<b)
    {
        st[i]=st[i-1]*n;
        i++;
    }
    s2="";
    ans="";
    for(i=a;i<=b;i++)
    {
        s1="";
        long long tmp=i-1;
        for(j=stepen-1;j>=0;j--)
        {
            if(st[j]!=0)
            {
                num[stepen-j-1]=tmp/st[j];
                tmp=tmp%st[j];
            }
            else num[stepen-j-1]=0;
        }
        for(j=0;j<stepen;j++)prev[j]=num[j];
        for(j=0;j<stepen;j++)
        {
            if(prev[j]%2==1){
                if(n%2==1)
                {
                    for(k=j+1;k<stepen;k++)
                    {
                        num[k]=n-num[k]-1;
                    }
                }
                else num[j+1]=n-num[j+1]-1;
            }
            s1=s1+(char)(digits[num[j]]+'0');
        }
        if(s2!=""){
            int sbor1=0,sbor2=0;
            for(j=0;j<s1.size();j++)sbor1+=(int)(s1[j]-'0');
            for(j=0;j<s2.size();j++)sbor2+=(int)(s2[j]-'0');
            int dif=sbor1-sbor2;
            if(dif<0)dif=-dif;
            if(maxdif<dif)maxdif=dif;
        }
        s2=s1;
        if(ans=="")ans=s1;
        else if(ans<s1)ans=s1;

    }
    cout<<ans<<" "<<maxdif<<endl;
    return 0;
}
