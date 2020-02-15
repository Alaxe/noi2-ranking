#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a;
    int s1=0;
    int s2=0;
    int max=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a=='a'||a=='b')
        {
            s1++;
        }
        if(a=='c'||a=='d')
        {
            s2++;
        }
        if(s1==s2)
        {
             if(s1+s2>max)
             {
                 max=s1+s2;
             }
        }
    }
    cout<<max<<endl;
    return 0;
}
