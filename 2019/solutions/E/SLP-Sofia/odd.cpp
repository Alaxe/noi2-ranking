#include <iostream>
using namespace std;
int main()
{
    long long a,b,x=1;
    int e=11,c=0;
    cin>>a>>b;
    while(a<=b)
    {
        while(x<=a)
        {
            if(a%x==0)
            {
                c++;
            }
            x++;

        }

        if(c%2==1)
        {
            e++;
        }
        c=0;
        x=1;
        a++;
    }

    cout<<e<<endl;
}
