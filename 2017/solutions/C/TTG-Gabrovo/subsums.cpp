#include<iostream>
using namespace std;
int n;
int a[1000];
int dif[10000000],k = -1;

void isNew(int x)
{
    for(int i=0;i<k;i++)
        if(dif[i]==x)return;
    dif[k++] = x;
}

int Sum ()
{
    int work = 0;
    for(int i=0;i<n;i++)
    {
        work = 0;
        for(int j=i;j<n;j++)
        {
            work = work + a[j];
            isNew(work);
        }
        work = 0;
        for(int j=i;j>=0;j=j-1)
        {
             work = work + a[j];
             isNew(work);
        }
        for(int j=n-1;j>i;j=j-1)
        {
            work = work + a[j];
            isNew(work);
        }

    }
    cout<<k<<endl;
    return 0;
}


int main ()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    Sum();
    return 0;
}
