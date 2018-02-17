#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
int n[1301]; int s[1301];
int len,m,br=0,i=0,j=0,br2=0;
cin>>n;
while(br==0)
{
    while(n[i]!='\0')
    {if(br2==1)cout<<s[j];
     s[j]=n[i];
     i++;
     j++;
    br2=1;}
}
br=1;
}
return 0;
}
