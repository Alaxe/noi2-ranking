#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int l;
    cin>>l;
    int lc=1;
    int a,max=0;
    for(int j=1;j<=(n+l)*2;j++)
    {
        if(j%10!=lc)max=j;
    }
   cout<<max<<endl;
    return 0;
}
