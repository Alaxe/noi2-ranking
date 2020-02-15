#include<iostream>
using namespace std;

int main ()
{
    long long N, br_a = 0, br_b = 0,br_c = 0,br_d = 0, AB, CD;
    cin >> N;
    char bukvi[100000];
    for (long long i = 0; i < N; i++)
    {
        cin >> bukvi[i];
        if (bukvi[i] == 'a')
        {
            br_a++;
        }
        else if (bukvi[i] == 'b')
        {
            br_b++;
        }
        else if (bukvi[i] == 'c')
        {
            br_c++;
        }
        else
        {
            br_d++;
        }
    }
    AB = br_a + br_b;
    CD = br_c + br_d;
    if (br_a == 0 or br_b == 0 or br_c == 0 or br_d == 0)
    {
        cout << 0 << endl;
    }
    else if (AB == CD)
    {
        cout << AB + CD;
    }
    else if (AB != CD)
    {
        if (AB > CD)
        {
            cout << AB << endl;
        }
        else
        {
            cout << CD << endl;
        }
    }
    return 0;
}
