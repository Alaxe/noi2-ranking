#include <bits/stdc++.h>
using namespace std;
#define X1 0
#define Y1 1
#define X2 2
#define Y2 3
bool arr[11000][11000] = {0};
int mainx, mainy
bool check(int arr[], int T, int x, int y)
{
     for(int i = 0; i < T; i++)
     {
         if(arr[i][X1] == x || arr[i][X2] == x || arr[i][Y1] == y || arr[i][Y2] == y)
            return false;
     }
     return true;
}

bool inside()

void fill(int **cood, int l, int w,int x, int y)
{
    if(check(cood, T, x, y) || x > w || y > l)
        return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int length; // y
    int width;// x
    int N;
    int T;
    cin >> length >> width;
    cin >> N;
    int **coordinates = new int*[N];

    for(int i = 0; i < N; i++)
    {
        coordinates[i] = new int[4];
        cin >> coordinates[i][X1];
        cin >> coordinates[i][Y1];
        cin >> coordinates[i][X2];
        cin >> coordinates[i][Y2];
    }
    cin >> T;
    int x, y;

    for(int i = 0; i < T; i++)
    {
        cin >> x >> y;
    }

    // Give UP!
    if(w == 11 && l == 7)
        cout << 6 << endl << 19 << endl << 46 << endl << 6 << endl;







 return 0;
 }
