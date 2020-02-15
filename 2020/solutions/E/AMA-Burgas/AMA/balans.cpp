#include <iostream>
using namespace std;
int main()
{
    int n,ab=0,cd=0;
    cin>>n;
    char red[n];
    for(int i=0;i<n;i++)
    {
        cin>>red[i];
        if (red[i]=='a'||red[i]=='b') ab++;
        else cd++;
    }
    if (ab!=cd)
    {
        while (ab!=cd)
        {
            if (ab>cd) ab=ab-1;
            if (ab<cd) cd=cd-1;

        }
    }
    cout<<ab+cd;
    return 0;
}
