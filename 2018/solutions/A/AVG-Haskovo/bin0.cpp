#include<iostream>
#include<vector>
using namespace std;
long long int s,t,z;

long long int f1(long long int x)
{
    long long int ans=0;
    long long int q=x,e;
    vector<long long int>v;
    while(q>=1)
    {
        v.push_back(q%2);
        q/=2;
    }
    int sz=v.size();
    for(long long int i=z;i<sz-1;i++)
    {
        e=1;
        q=1;
        for(long long int j=2;j<=z;j++)e*=j;
        for(long long int j=i;j>=i-z+1;j--)q*=j;
        ans+=q/e;
    }
   // cout<<ans<<endl;
    long long int p=z,l=0;
    for(long long int i=sz-2;i>=0;i--)
    {
        if(v[i]==0)p--;
        if(p<0)break;
        if(v[i]==1)
        {
            if(p==0)continue;
            l=1;
            // C p-1 i

            e=1;
            q=1;
            for(long long int j=2;j<=p-1;j++)e*=j;
            for(long long int j=i;j>=i-(p-1)+1;j--)q*=j;
            ans+=q/e;
            //cout<<q<<" "<<e<<endl;
        }
    }//cout<<ans<<endl;
    if(l==0&&p==0)ans++;
    return ans;
}
void f2()
{
    long long int e,q,ans=0;
    for(long long int i=s;i<=t;i++)
    {
        q=i;
        e=0;
        while(q>1)
        {
            if(q%2==0)e++;
            q/=2;
        }
        if(e==z)ans++;
    }
    cout<<ans<<'\n';
}
long long int f3(long long int x)
{
    long long int a[1024],bra=0;
    long long int b[1024],brb=0;
    long long int ans=0;
    long long int q=x,e=0;
    vector<long long int>v;
    while(q>=1)
    {
        v.push_back(q%2);
        q/=2;
    }
    int sz=v.size();
    for(long long int i=z;i<sz-1;i++)
    {
        /*e=1;
        q=1;
        for(long long int j=2;j<=z;j++)e*=j;
        for(long long int j=i;j>=i-z+1;j--)q*=j;
        ans+=q/e;*/
        long long int y=z,f=i;
        brb=0;
        bra=0;
        q=1;
        for(long long int j=2;j<=y;j++)
        {
            brb++;
            b[brb]=j;
        }
        for(long long int j=f;j>=f-y+1;j--)
        {
            bra++;
            a[bra]=j;
        }
        for(int ii=1;ii<=brb;ii++)
        {
            for(int k=2;k<=b[ii];k++)
            {
                while(b[ii]%k==0)
                {
                    b[ii]/=k;
                    for(int j=1;j<=bra;j++)
                    {
                        if(a[j]%k==0){a[j]/=k;break;}
                    }
                }
            }
        }
        for(int j=1;j<=bra;j++)q*=a[j];

        ans+=q;
    }//cout<<ans<<endl;
   // cout<<ans<<endl;
    long long int p=z,l=0;
    for(long long int i=sz-2;i>=0;i--)
    {
        if(v[i]==0)p--;
        if(p<0)break;
        if(v[i]==1)
        {
            if(p==0)continue;
            l=1;
            // C p-1 i


            long long int y=p-1,f=i;
            brb=0;
            bra=0;
            q=1;
            for(long long int j=2;j<=y;j++)
            {
                brb++;
                b[brb]=j;
            }
            for(long long int j=f;j>=f-y+1;j--)
            {
                bra++;
                a[bra]=j;
            }
            for(int ii=1;ii<=brb;ii++)
            {
                for(int k=2;k<=b[ii];k++)
                {
                    while(b[ii]%k==0)
                    {
                        b[ii]/=k;
                        for(int j=1;j<=bra;j++)
                        {
                            if(a[j]%k==0){a[j]/=k;break;}
                        }
                    }
                }
            }
            for(int j=1;j<=bra;j++)q*=a[j];

            ans+=q;

            /*e=1;
            q=1;
            for(long long int j=2;j<=p-1;j++)e*=j;
            for(long long int j=i;j>=i-(p-1)+1;j--)q*=j;
            ans+=q/e;*/
            //cout<<q<<" "<<e<<endl;
        }
    }//cout<<ans<<endl;
    if(l==0&&p==0)ans++;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>t>>z;
    if(t-s<=10000000)f2();
    else if(z<=17) cout<<f1(t)-f1(s-1)<<'\n';
    else cout<<f3(t)-f3(s-1)<<'\n';
    return 0;
}

/*

9526 532757 5

75 523 3
*/
