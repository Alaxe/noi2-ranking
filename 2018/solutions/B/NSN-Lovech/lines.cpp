#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int coords[n][2];
    int maxDots = 0;
    int checkMaxDots;

    for(int i = 0; i < n; i++)
    {
        cin>>coords[i][0]>>coords[i][1];
    }
    for(int i = 0; i < n;   i++)
    {
        checkMaxDots = 0;
        int a = i;
        int b = i + 1;
        if(b < n)
        {
            for(int j = b + 1; j < n; j++)
            {
                float leftSide = ( coords[j][0] - coords[a][0] ) * ( coords[b][1] - coords[a][1] );
                float rightSide = ( coords[j][1] - coords[a][1] ) * ( coords[b][0] - coords[a][0] );
                if(leftSide == rightSide)
                {
                    checkMaxDots++;
                }
            }
            if(checkMaxDots > maxDots)
            {
                maxDots = checkMaxDots;
            }
        }
        else
        {
            break;
        }
    }
    cout<<maxDots + 2<<endl;

    return 0;
}
