//zad 2
#include<iostream>
using namespace std;


int brc(int a)
{
    int br;
    while(a)
    {
        a /= 10;
        br++;
    }
    return br;
}


int pow(int b, int p)
{
    int o = b;
    for(int i = 1; i < p;i++)
    {
        o *= b;
    }
    if(p == 0) o = 1;
    return o;
}



int main()
{
    int n,l,o,br;
    int s[3] = {10,10,10};
    br = 0;
    cin >> n >> l;
    for(int y = 0;y < l; y++)cin >> s[y];
    for(int i = 1;br < n; i++)
    {
        bool f = 0;
        for(int j  = 0;j < brc(i);j++)
        {
            int curr = i / pow(10,j) % 10;
            if(curr == s[0] || curr == s[1] || curr == s[2]){ f = 1;break;}
        }
        if(f == 0)
        {
            cout << i << endl;
            br++;
        }
    }
    return 0;
}
