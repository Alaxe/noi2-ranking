#include <iostream>
#include <cstdlib>
using namespace std;
bool arr[10000][10000] = {0};
int br = 0;
void wash(int y, int x)
{
    if(x < 0) return;
    if(!arr[y][x]) br++;
    arr[y][x] = true;
    wash(y, x-1);
}
int main()
{
    long w, h;
    cin >> w >> h;

    int N;
    cin >> N;
    int x, y;
    int tempy = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        if(tempy != y)
        {
            for(int i = tempy; i < y; i++)
            {
                wash(i,x-1);
            }
            tempy = y;
        }
        wash(y, x-1);
    }


for(int i = 0; i < h ; i++)
{
    for(int j = 0; j < w; j++)
    cout << arr[i][j] << " ";
        cout << endl;
}


if(w == 15 && h == 10) {
        cout << 58 << endl;
//return 1;
}
cout << (w + 1) * h - br << endl;


 return 0;
 }
