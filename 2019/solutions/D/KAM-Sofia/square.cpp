#include <bits/stdc++.h>
using namespace std;
int NOK(int a, int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;
    if(a > b)
        return NOK(a % b, b);
    else
        return NOK(b % a, a);
    if(a == 1 || b == 1)
        return 1;

}
int NOD(int a, int b)
{
    return (a * b) / NOK(a, b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    set<int>diff(arr, arr + n);
    int num[diff.size()];
    int i = 0;
    for(set<int>::iterator it = diff.begin(); it != diff.end(); it++, i++)
        num[i] = *it;
    int nok = num[0];
    for(int j = 0; j < i; j++)
    {
        nok = NOD(nok, num[j]);
    }
    while(sqrt(nok) == sqrt(nok) / 1)
    {
        nok = sqrt(nok);
    }
    for(int i = nok / 2; true; i /= 2)
    {
        if((i * i) % nok != 0)
            break;
        nok /= 2;
    }
    cout << nok << endl;





}
