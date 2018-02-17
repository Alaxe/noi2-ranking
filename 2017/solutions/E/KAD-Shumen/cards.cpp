#include <iostream>
using namespace std;
int main()
{
    int a[12],c,br=0;
    cin>>c;
    for(int i=0;i<12;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<12;i++)
    {
        if(a[i]<a[1])br++;
    }
    cout<<br/2<<endl;
        return 0;
}
