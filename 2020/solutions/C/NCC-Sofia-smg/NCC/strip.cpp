#include <iostream>
using namespace std;

int n;
int k;
int brr=0;
bool used[50];
int nl, nd;
void rec()
{
    if(nl<=0 || nd>=n-1)
    {
        brr++;
    }
    else
    {
        if(!used[nl-1])
        {
            nl--;
            used[nl]=true;
            rec();
            used[nl]=false;
            nl++;


        }
        if(!used[nd+1])
        {
            nd++;
            used[nd]=true;
            rec();
            used[nd]=false;
            nd--;

        }
    }
}

int main()
{

    cin >> n;
    cin >> k;
    if(k==1 || k==n)
    {
        cout << 1;
        return 0;
    }

    nl=k-1;
    nd=nl;
    used[nl]=true;

    rec();

    cout << brr;


    return 0;
}
