#include<iostream>

using namespace std;
d (int a)
{
    int hil = a/1000%10;
    int stot = a/100%10;
    int des = a/10%10;
    int ed = a/1%10;
    return a+des+ed;
}

int main()
{
int n, m, br=0;
cin>>n>>m;
while (d(n)<m)
{
    if (br<d(n))
    {
        br++;
        cout << br << endl;
    }
}
return 0;
}
