#include<bits/stdc++.h>
using namespace std;

struct data
{
    long long a, n;
};

long long countP, R;
data patients[720];

bool cmp(data x, data y)
{
    return x.a < y.a;
}

int main()
{
    while(1)
    {
        if(cin.eof())break;
        cin >> patients[countP].a >> patients[countP].n;
        countP ++;
    }
    sort(patients, patients + countP, cmp);
    /**for(int i = 0; i < countP; i ++)
    {
        cout << patients[i].a << " " << patients[i].n << endl;
    }*/
    for(int i = 0; i < countP; i ++)
    {
        if(patients[i].a > R)R = patients[i].a + patients[i].n;
        else R = R + patients[i].n;
    }
    cout << R - patients[countP - 1].a << endl;
}
/**
0 30
720 10
715 20
714 25
*/
