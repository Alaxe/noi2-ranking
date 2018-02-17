#include<bits/stdc++.h>
using namespace std;

int matrix[100][100], n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
        {
            string a;
            cin >> a;
            if(a[0] == 'A') matrix[i][j] = 1;
            else if(a[0] == 'T') matrix[i][j] = 10;
            else if(a[0] == 'J') matrix[i][j] = 11;
            else if(a[0] == 'Q') matrix[i][j] = 12;
            else if(a[0] == 'K') matrix[i][j] = 13;
            else matrix[i][j] = a[0] - '0';
        }
    }
    for(int i = n - 1; i >= 0; i --)
        matrix[i][0] += matrix[i + 1][0];
    for(int i = 0; i < n; i ++)
        matrix[n - 1][i] += matrix[n - 1][i - 1];
    for(int j = 1; j < n; j ++)
    {
        for(int i = n - 2; i >= 0; i --)
        {
            matrix[i][j] += max(matrix[i + 1][j], matrix[i][j - 1]);
        }
    }
    cout << matrix[0][n - 1] << endl;
}
/**
4
8S AD 3C AC
8C 4H QD QS
5D 9H KC 7H
TC QC AS 2D
*/
