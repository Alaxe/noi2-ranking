#include <iostream>
using namespace std;
int main()
{
    unsigned int n;
    int a,b,tempPoints=0,maxPoints=0;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>a;
        cin>>b;
        if(a>b)
        {
            swap(a,b);
        };
        for (int j=a+1; j<b; j++)
        {
            tempPoints++;
        }
        if(tempPoints>maxPoints)
        {
            maxPoints=tempPoints;
        }
        tempPoints=0;
    }
    cout<<maxPoints;
}
