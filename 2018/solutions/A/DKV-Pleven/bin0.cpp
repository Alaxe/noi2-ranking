#include <iostream>
using namespace std;

int SumOfOnes (int baseten)
{
    int sum = 0;
    while (baseten>0)
    {
        sum+=baseten%2;
        baseten/=2;
    }
    return sum;
}

int LenOfInt (int baseten)
{
    int len = 0;
    while (baseten>0)
    {
        baseten/=2;
        len++;
    }
    return len;
}

int main ()
{
    int s,t,z,ans = 0;
    cin >> s >> t >> z;
    for(int i = s;i<=t;i++)
    {
        if(LenOfInt(i)-SumOfOnes(i)==z) ans++;
    }
    cout<<ans;
    return 0;
}
