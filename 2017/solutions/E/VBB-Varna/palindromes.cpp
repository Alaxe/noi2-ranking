#include<iostream>
using namespace std;
bool is_pal(int a)
{
int pal=0,ch,s=ch;
while (ch)
{
    pal=pal*10+ch%10;
    ch/=10;
}
if (s==pal) return 1;
return 0;
}

int main()
{
    int n,a,b,max=-1;
    cin>>n;
    for (int i=0;i<n;i++){
    for (int j=i+1;j<n;j++)
    {
        if (is_pal(i*j)&&i*j>max)
        a=i;
        b=j;
    }
    }
    cout<<a<<" "<<b<<endl;
    cout<<a*b;
}
