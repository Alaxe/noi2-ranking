#include<iostream>
using namespace std;
unsigned long long  w,h,n;
long long a[100001][2];
unsigned long long s=0;
void output()
{
    cout<<s<<endl;
}
void path()
{
    int i=0;bool flag=0;
    unsigned long long p=0;
    for(int i=1;i<n;i++)
    {
        if(flag==1)
        {
            if(a[i][1]>=p)
            {
                flag=0;
                s=s+(unsigned long long)((a[i][1]-p)*(w-a[i][0]));
            }
        }
        else if(a[i][1]>a[i-1][1]&&a[i][0]==a[i-1][0])s=s+(unsigned long long)((w-a[i][0])*(a[i][1]-a[i-1][1]));
        else if(a[i][1]<a[i-1][1]){p=a[i-1][1];flag=1;}
    }


}
void input()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>w>>h;
    cin>>n;
    //int a,b;
    for(int i=0;i<n;i++)
    {
        //cin>>a>>b;
        cin>>a[i][0]>>a[i][1];
    }


}
int main()
{
    input();
    path();
    output();
    return 0;
}
