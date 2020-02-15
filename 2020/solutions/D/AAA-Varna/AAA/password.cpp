#include <iostream>
#include <string>
using namespace std;
string pw;
bool fun(int i)
{
    if(pw[i] == pw[i-1] && pw[i] == pw[i-2])return 1;
    if(pw[i] == pw[i+1] && pw[i] == pw[i+2])return 1;
    return 0;
}
int main()
{
    cin >> pw;
    int l = pw.size();
    int b = 0;
    for(int i = 3; i < l; i++)
    {
        while(fun(i) == 1)
        {
            pw[i] = 'a'+b;
            b++;
        }
        b = 0;
    }
    cout << pw << endl;
}

