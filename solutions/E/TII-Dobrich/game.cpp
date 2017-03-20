#include<iostream>
using namespace std;
int main()
{
    int m,k,br=1,s=0,a[201],p1=1,x;
    cin>>m>>k;
    while(s<k && br!=200)
    {
        cin>>x;
        if(x%2==0)
        {
            s=s+x;
        }
        if(x<m)
        {
            a[br]=m-x;
        }
        else
        {
            if(x==m)
            {
                a[br]=0;
            }
            else
            {
                a[br]=x-m;
            }
        }
        br++;
    }
    int minx=a[1];
    for(int i=2; i<br; i++)
    {
        if(minx>a[i])
        {
            minx=a[i];
            p1=i;
        }
        else
        {
            if(a[i]==minx)
            {
                p1=i;
            }
        }
    }
    if(br==2)
    {
        cout<<p1<<endl;
    }
    else
    {
        cout<<p1<<" "<<s<<endl;
    }
}
