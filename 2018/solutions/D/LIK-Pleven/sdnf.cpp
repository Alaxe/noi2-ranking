#include<iostream>
using namespace std;
int a[100];
int main()
{
   int n;
    int f=1, z,br=1,otg=0;
    cin>>n;
    for (int i=1; i<n+1; i++)
    {
        f=f*i;

    }

    z=f;
    while (z>10)
    {
        z=z/10;
        br=br+1;
    }

for(int q=0; q<n; q++)
{

}

 if(br=1)
{
    otg=f;
}
if(br=2)
{
    a[0]=f%10;
    a[1]=f/10;
    otg=a[0]+a[1];
}

if(br=3)
{
    a[0]=f%10;
    a[1]=f/10%10;
    a[2]=f/100%10;
    otg=a[0]+a[1]+a[2];
}
if(br=4)
{
    a[0]=f%10;
    a[1]=f/10%10;
    a[2]=f/100%10;
    a[3]=f/1000%10;
    otg=a[0]+a[1]+a[2]+a[3];
}



 return 0;
}
