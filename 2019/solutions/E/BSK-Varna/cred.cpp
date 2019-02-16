#include<iostream>
using namespace std;
int main()
{
    int n, m, br=0, i, a;
    cin >> n >> m;
    while(1)
    {
        a=n;
        if(n>m)break;
        else
        {
            br++;
            while(a)
            {
                n+=a%10;
                a/=10;
            }


        }
    }
    cout << br << endl;
    return 0;
}
