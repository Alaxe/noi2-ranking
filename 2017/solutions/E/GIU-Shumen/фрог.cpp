#include <iostream>
using namespace std;
void (int N)
int main()
{
    int a,b;
    cin>>a>>b;
    int max=0;
    int min=0;
    if(a>b&&b<a)min=b;max=a;
    {
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}
