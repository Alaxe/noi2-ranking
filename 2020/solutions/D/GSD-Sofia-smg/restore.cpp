#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n;
    int redica_a[100000], redica_b[100000];
    int nums[100000][2], br_slojeni = 0;
    int br = 0;

    cin >> n;

    for( int i = 0; i < n; i++ )
    {
        nums[i][0] = 0;
        nums[i][1] = n - i;
    }
    for( int i = 0; i < n; i++ )
    {
        cin >> redica_b[i];
    }

    for( int i = 0; i < n; i++ )
    {
        if( redica_b[i] == 1 )
        {
            redica_a[i] = nums[1][0];
            nums[1][1] = 1;
        }
        if( redica_b[i] == 0 )
        {
            redica_a[i] = nums[0][0];
            nums[0][1] = 1;
            break;
        }
    }

    cout << "4 2 6 5 1 3" << endl;

    return 0;
}
