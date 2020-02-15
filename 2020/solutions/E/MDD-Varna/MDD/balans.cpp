#include<iostream>
using namespace std;
int main()
{
    long long n,brab=0,brcd=0,ngbo=0;
    char c;
    cin >> n;
    for(long long a=1; a<=n; a++)
    {
        cin >> c;
        if(c=='a'||c=='b')brab++;
        else brcd++;
        if(brab==brcd)ngbo=brab*2;
    }
    cout << ngbo << endl;
}
