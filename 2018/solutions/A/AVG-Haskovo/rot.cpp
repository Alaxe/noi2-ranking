#include<iostream>
#include<string>
using namespace std;
string s,ans,st;
int a[131072];
int b[131072];
int c[131072];
int n,k,u;
/*void prt(string kk)
{
    for(int i=0;i<n;i++)
    {
        if(kk[i]>=0&&kk[i]<=9)cout<<(char)(kk[i]+'0');
        else cout<<(char)(kk[i]-10+'A');
    }cout<<'\n';
}*/
void check()
{

    if(c[1]==0||b[1]==0)return;
    st="";
    for(int i=1;i<=n;i++)
    {
    //    cout<<b[i%n+1]<<" "<<c[i]<<'\n';
        if(b[(i)%n+1]!=c[i])return;
        if(b[(i)%n+1]==-1)return;
        if(c[i]==-1)return;
    }
    for(int i=1;i<=n;i++)
    {
        st+=b[i];
    }//prt(st);
    u=1;
    if(ans=="")ans=st;
    else
    {
        if(st<ans)ans=st;
    }
}
void f1()
{
    int l=0;
    for(int w=1;w<k;w++)
    {
        for(int i=0;i<=n+1;i++){b[i]=-1;c[i]=-1;}
        l=0;
        b[n]=w;
        c[n-1]=w;
        //cout<<a[n]<<" "<<w<<'\n';
        c[n]=a[n]+w;
        if(c[n]>=k){c[n]-=k;l=1;}
        for(int i=n-1;i>=1;i--)
        {
            b[i]=c[i]-l-a[i];
            if(b[i]<0){b[i]+=k;l=1;}
            else l=0;
            c[i-1]=b[i];
           // c[i-1]=a[i]+b[i];
           // if(c[i]>0)
           // b[i-1]=c[i];
        } //cout<<" "<<w<<'\n';
        check();
        /*for(int i=1;i<=n;i++)
        {
            cout<<b[i]<<" ";
        }cout<<'\n';
        for(int i=1;i<=n;i++)
        {
            cout<<c[i]<<" ";
        }cout<<'\n';
        cout<<'\n';*/
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    for(int asd=1;asd<=4;asd++)
    {
        u=0;
        ans="";
        cin>>s;
        n=s.size();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0'&&s[i]<='9')a[i+1]=s[i]-'0';
            else a[i+1]=s[i]-'A'+10;
        }
       // for(int i=1;i<=n;i++)cout<<a[i];cout<<'\n';
        f1();
        if(u==0)cout<<0<<'\n';
        else
        {for(int i=0;i<n;i++)
        {
            if(ans[i]>=0&&ans[i]<=9)cout<<(char)(ans[i]+'0');
            else cout<<(char)(ans[i]-10+'A');
        }cout<<'\n';}
    }

    return 0;
}
/*
10
216
1318
2349
44444


*/
