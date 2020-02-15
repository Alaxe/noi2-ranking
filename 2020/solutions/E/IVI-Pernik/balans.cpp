#include <iostream>
using namespace std;
int main()
{
    int n,ab=0,cd=0,mx=0;
    char b;
    cin>>n;
    for(int i=1;i <= n;i++)
    {
        cin>>b;
        if(b == 'a' || b == 'b')ab++;
        else cd++;
        if(ab == cd)mx=ab+cd;
    }
    cout<<mx<<endl;
    return 0;
}
