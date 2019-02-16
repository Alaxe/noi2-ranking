#include <iostream>
using namespace std;
int main ()
{
    unsigned long long n;
    cin >>n;
    unsigned long long otg=(n/30+1)*30-4;
    if (otg<n) otg+=30;
    cout <<otg<<endl;
}
