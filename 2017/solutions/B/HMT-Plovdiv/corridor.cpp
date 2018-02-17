#include<iostream>
#include<queue>
using namespace std;

int a[100000][2];
int main()
{
    int w, h, N, x, y;
    cin >> w >> h;
    int maxx = -1, minn = w + 1;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> a[i][0] >> a[i][1];
        if(a[i][0] > maxx) maxx = a[i][0];
    }
    cout << w * h / 2;




return 0;
}
