#include<iostream>
using namespace std;
string a;
int otg;
int main()
{
    cin>>a;

    int n=a.size();
    otg+=n;
    cout<<otg<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(a[i]==a[j])
            {
                otg=otg+(j-i-1);
            }
        }
    }
    cout<<otg%(1000000000+7)<<endl;
    return 0;
}
