#include<iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x;
    cin >> x;
    int num = x.size();
    while(x[x.size() - num] == '0') num --;
    cout << 2;
    for(int i = 0; i < num - 1; i ++)   cout << 0;
    cout << 6;
}
