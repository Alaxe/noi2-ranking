#include<iostream>
using namespace std;

int main()
{
    int w, h, n, s[11001], x, y;
    cin >> w >> h >> n;
    int s1 = w * h;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y >> w >> h;
        s[i] = w * h;
    }
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cout << s[i];
    }




return 0;
}
