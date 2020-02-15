#include<bits/stdc++.h>
using namespace std;

int numbersAmount[100001];
long n, m;

int main()
{
    cin >> n;
    memset(numbersAmount, 0, n+1);
    int num;
    for(int k = 0; k < n; k++)
    {
        cin >> num;
        numbersAmount[num]++;
    }

    for(int i = 1; i < 100001; i++)
        numbersAmount[i] += numbersAmount[i-1];

    vector<int> answ;
    cin >> m;
    int a, b;
    for(int j = 0; j < m; j++)
    {
        cin >> a >> b;
        answ.push_back(numbersAmount[b]-numbersAmount[a-1]);
    }
    for(int i = 0; i < m; i++)
        cout << answ.at(i) << endl;
    return 0;
}
