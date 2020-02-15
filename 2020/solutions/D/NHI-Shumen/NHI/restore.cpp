#include<iostream>
using namespace std;
int a[100005];
bool brm[100005];
int main()
{int n,b[100005]; cin>>n;
int zero=0,idk=0;
for(int i=0;i<n;i++)
{
    cin>>b[i];
    if(b[i]==0)zero++;
    if(b[i]==(n-i-1))idk++;
}
if(zero==n)
{
    for(int i=n;i>0;i--)cout<<i<<" ";
    cout<<endl;
    return 0;
}
if(idk==n)
{
    for(int i=1;i<=n;i++)cout<<i<<" ";
    cout<<endl;
    return 0;
}
a[0]=n-b[0];
brm[a[0]]=true;
for(int i=1;i<n;i++)
{
    int maxa=n-b[i];
    bool idk=false;
    if(b[i]==n-i+1)
    {
        a[i]=i;
        brm[i]=true;
    }
    else
    {
        while(maxa>0&&idk==false)
        {
            int br=0;
            for(int j=0;j<maxa;j++)
        {
            if(maxa<a[j])br++;
        }
        if(maxa+br+b[i]==n&&brm[maxa]==false)
        {
            a[i]=maxa;
            brm[maxa]=true;
            idk=true;
        }
        else maxa--;
        }
    }

}
for(int i=0;i<n;i++)cout<<a[i]<<" ";

/*
6
2 3 0 0 1 0
*/
return 0;
}
