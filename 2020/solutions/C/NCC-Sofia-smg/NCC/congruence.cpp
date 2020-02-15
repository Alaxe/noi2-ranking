#include <iostream>
#include <string>

using namespace std;

#define MAX_N 1000000
int pog[MAX_N];
int pom[MAX_N];
bool used[26];

int main()
{
    string a;
    cin >> a;

    int x=a.size();
    char c='A';
    char d='Z';

    for(int i=0; i<x; i++)
    {
        for(int j=0; j<26; j++)
        {
            used[j]=false;
        }

        for(int j=0; j<x; j++)
        {
            if(a[i]>a[j] && !used[a[j]-c] )
            {
                used[a[j]-c]=true;
                pog[i]++;
            }
            else if(a[j]>a[i] && !used[a[j]-c])
            {
                used[a[j]-c]=true;
                pom[i]++;
            }
        }
    }

    string naig;
    string naim;
    char k;



    for(int i=0; i<x; i++)
    {
        k=char(d-pom[i]);
        naig[i]=k;
    }
    for(int i=0; i<x; i++)
    {
        k=char(c+pog[i]);
        naim[i]=k;
    }



    for(int i=0; i<x; i++)
    {
        cout << naim[i];
    }
    cout << endl;
    for(int i=0; i<x; i++)
    {
        cout << naig[i];
    }


    return 0;
}

