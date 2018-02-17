#include<iostream>
using namespace std;
void cards(int &a,int &b,int &n)
{   int br=0;
    int s=a*b;
    for (int i=0;i<n*2;i++)
    {
        if (s<a*b)
        {
            br+=0;
        }
        else
        {
            br++;
        }
    }
}

int main()
{
int n,a,b;
cin>>n;
int br=0;
int i=0;
do
{   cin>>a>>b;
int s=a*b;

    br++;
    if (s<a*b)
    {
        br+=0;
    }
    else
    {
        br++;
    }
    i++;
}while (i<n*2);
cout<<br<<endl;
return 0;
}
