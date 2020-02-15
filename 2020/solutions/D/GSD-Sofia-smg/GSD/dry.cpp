#include<iostream>
#include<cstring>

using namespace std;

int hight[100], index;

int maxy_num( int ind, int len )
{
    int maxy = hight[ind + 1];
    index = ind + 1;

    for( int i = (ind + 2); i < len; i++ )
    {
        if( hight[i] > maxy )
        {
            maxy = hight[i];
            index = i;

            if( maxy > hight[ind] )
            {
                break;
            }
        }
    }

    return maxy;
}

int main()
{
    int n, u, v;
    int obem = 0;
    int len, temp;

    cin >> n;
    cin >> u;
    cin >> v;

    for( int i = 0; i < n; i++ )
    {
        cin >> hight[i];
    }

    for( int i = 0; i < n; i++ )
    {
        if( i == (n - 1) )
        {
            break;
        }
        if( hight[i] < hight[i + 1] )
        {
            obem = obem + hight[i]*u*v;
        }
        else
        {
            temp = maxy_num( i, n );
           // cout << temp << " ";
            if( hight[i] > temp )
            {
                //cout << (index - i + 1)*u << " ";
                obem = obem + temp*((index - i)*u)*v;
            }
            else
            {
                obem = obem + hight[i]*((index - i)*u)*v;
            }

            i = index - 1;
        }

       // cout << obem << endl;
    }

    cout << obem << endl;

    return 0;
}
