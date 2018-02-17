#include<iostream>
using namespace std;
int main()
{
    int n,i,a,b,a1,b1,br=0;

    cin>>n>>a>>b;

    for(i=0;i<n/2;i++)
    {
        cin>>a1>>b1;

        if((a1<=a && b1<=b)||(b1<=a && a1<=b))br++;

        a=a1;
        b=b1;
    }

    cout<<br<<endl;

    return 0;
}
