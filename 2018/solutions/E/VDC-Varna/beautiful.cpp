#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a,b=0,br=0;
    a=1;
    for(int i=0;i<n;i++)
    {
        b=b*10+a;
        a++;
    }
    int min=10000001;
    for(int i=a;i<=b;i++)
    {
        if(b%k==0&&b<min)
        {
            min=b;
            br++;
        }
    }
    if(br==0)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    if(b%k==0&&b<min)min=b;
    cout<<min<<endl;

    return 0;
}
