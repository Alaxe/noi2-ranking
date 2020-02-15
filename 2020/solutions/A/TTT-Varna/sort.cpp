#include <iostream>
using namespace std;
int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, aprev;
    cin >>n;
    cin >>a;
    aprev=a;
    for (int i=1; i<n; i++)
    {
        cin >>a;
        if (a-aprev<0)
        {
            cout <<aprev-a<<endl;
            return 0;
        }
        aprev=a;
    }
    cout <<0<<endl;
}
