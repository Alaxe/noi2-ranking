#include<iostream>
#include<algorithm>

using namespace std;

int counter [126000];

int main ()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int NUMBEROFTEST = 0 ; NUMBEROFTEST < T ; NUMBEROFTEST ++)
    {
        int n;
        cin >> n;
        for (int i = 0 ; i < n ; i ++)
        {
            int tmp;
            cin >> tmp;
            tmp --;
            if (tmp != i)
            {
                counter [tmp] ++;
                counter [i] ++;
            }
            else
            {
                counter [i] ++;
            }
        }
        cout << *max_element (counter + 0, counter + n) << "\n";
        for (int i = 0 ; i < n ; i ++)
        {
            counter [i] = 0;
        }
    }
}
