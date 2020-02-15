//Task: balans
//Author: Emil Kelevedjiev
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sa=0;
    int sb=0;
    int sc=0;
    int sd=0;

    int k=0;

    for(int i=1;i<=n;i++)
    {
        char c;
        cin >> c;

        if(c=='a') sa++;
        else if(c=='b') sb++;
        else if(c=='c') sc++;
        else if(c=='d') sd++;

        if(sa+sb==sc+sd) k=i;

    }

    cout << k << endl;
}
