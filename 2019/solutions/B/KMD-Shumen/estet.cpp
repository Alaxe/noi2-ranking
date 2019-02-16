#include<iostream>
using namespace std;
int a[1024],n,br1=0,br2=0,br3=0;
int b[1024];
void read()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
}

void work()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i+1])
        {
            br1++;

        }

        if(a[i]<a[i+2]&&a[i]>a[i+1])
        {
            br1++;
            i+2;
        }




 }

}
void work2()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i+1])
        {
            br2++;

        }
        if(a[i]>a[i+2]&&a[i]<a[i+1])
        {
            br2++;
            i+2;
        }





 }
 if(br1<br2)br1=br2;
}
void work3()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]<a[i+1])
        {
            b[i]=1;
        }
        else b[i]=-1;

    }
    for(int j=3;j<=n;j+2)
    {
        if(b[1]==b[2])br3+2;

        if(b[j-1]==b[j]&&b[j]==b[j+1])br3+2;

        if(b[j-1]==b[j]&&b[j]!=b[j+1])br3+1;

        if(b[j-1]!=b[j]&&b[j]==b[j+1])br3+1;


    }
    if(br1<br3)br1=br3;
    cout<<br2;
}
int main()
{
    read();
    work();
    work2();
    work3();



    return 0;
}
