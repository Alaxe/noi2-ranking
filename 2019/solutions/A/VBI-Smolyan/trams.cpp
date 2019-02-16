#include <iostream>
using namespace std;

int main()
{
    bool line[256][256], secondLineSet[256][256], stopLine[256], flag = false;
    int N, M, K = 0, x, y, amountStop = 0, p;
    cin >> N >> M;

    for(int i = 0; i < 256; i++)
    {
        for(int j = 0; j < 256; j++)
        {
            line[i][j] = false;
            secondLineSet[i][j] = false;
        }
    }
    for(int q = 1; q < M + 1; q++)
    {
        cin >> x >> y;
        line[x][y] = true;
        secondLineSet[x][y] = true;
    }
    for(int k = 1; k < M + 1; k++)
    {
        p = k;
        for(int i = 1; i < M + 1; i++)
        {
            if(p != i)
            {
                if(line[p][i] == true)
                {
                    line[p][i] = false;
                    p = i;
                    flag = true;
                }
            }
        }
        if(flag == true)
        {
            K++;
            flag = false;
        }
    }
    cout << K;
    for(int k = 1; k < M + 1; k++)
    {
        p = k;
        for(int i = 1; i < M + 1; i++)
        {
            if(p != i)
            {
                if(secondLineSet[p][i] == true)
                {
                    secondLineSet[p][i] = false;
                    stopLine[p] = true;
                    p = i;
                    amountStop++;
                }
            }
        }
        cout << endl << amountStop;
        for(int j = 1; j < M + 1; j++)
        {
            if(stopLine[j] == true)
            {
                cout << " " << j;
                stopLine[j] = false;
            }
        }
        amountStop = 0;
    }
}
