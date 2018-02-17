#include<iostream>
using namespace std;
int n,k,x,numb[100001],ways[100001],marks[100001],ans,mx;
int checkloop (int start)
{
    int bck=start,times=0;
    do
    {
        marks[start]=1;
        start=ways[start];
        times++;
    }while (bck!=start);
    return times;
}
int main ()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>k;
        for (int j=1;j<=k;j++) numb[j]=1;
        ans=0;
        mx=0;
        for (int j=1;j<=k;j++)
        {
            cin>>x;
            ways[j]=x;
            numb[x]++;
            mx=max(mx,numb[x]);
        }
        if (mx>=3) cout<<mx<<endl;
        else if (k%2==1) cout<<max(mx,3)<<endl;
        else
        {
            int r=0;
            for (int j=1;j<=k;j++) marks[j]=0;
            for (int j=1;j<=k;j++)
            {
                if (marks[j]==0) r=checkloop(j);
                if (r%2==1) {cout<<3<<endl; break;}
                if (j==k) cout<<2<<endl;
            }
        }
    }
    return 0;
}
/**
2
4
4 1 2 3
5
4 1 2 3 4
*/
