#include <iostream>
#include <set>

using namespace std;

int arr [100000];
int n;
set < int > unique_values;

int* dp [100000]; /// [index_to][finishing_with]

int main ()
{
    cin >> n;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> arr [i];
        unique_values.insert (arr [i]);
    }
    for (int i = 0 ; i < n ; i ++)
    {
        dp [i] = new int [unique_values.size ()];
        for (int j = 0 ; j < unique_values.size () ; j ++)
            dp [i][j] = 0;
    }
    for (int index_to = 1 ; index_to < n ; index_to ++)
    {
        int index = 0;
        for (auto& finishing_with : unique_values)
        {
            //cout << "Calcing to " << index_to << ", finishing w/ " << finishing_with << endl;
            dp [index_to][index] = 1e9;
            for (int i = 0; i <= index ; i ++)
            {
                //cout << "\ntrying w/ " << dp [index_to - 1][i] << "+" << abs (arr [index_to] - finishing_with) << endl;
                dp [index_to][index] = min (dp [index_to][index],
                                            dp [index_to - 1][i] + abs (arr [index_to] - finishing_with)
                                            );
            }
            //cout << "Calculated as " << dp [index_to][index] << endl;
            index ++;
        }
    }
    int answer = 1e9;
    for (int i = 0 ; i < unique_values.size () ; i ++)
        answer = min (answer, dp [n - 1][i]);
    cout << answer << endl;
    return 0;
}

/**
10 2 6 4 2 3 2 6 4 2 3
5 2 6 4 2 3
5 2 6 4 3 2
*/

