//Task: balans
//Author: Emil Kelevedjiev
#include<iostream>
using namespace std;

string s;

int main()
{
    int n;
    cin >> n;
    cin >> s;


    int k=0;

    for(int i=0;i<n;i++)
    {
        int sa=0;
        int sb=0;
        int sc=0;
        int sd=0;
        for(int j=0;j<=i;j++)
                if(s[j]=='a') sa++;
                else if(s[j]=='b') sb++;
                     else if(s[j]=='c') sc++;
                          else if(s[j]=='d') sd++;

        if(sa+sb==sc+sd) k=i+1;

    }

    cout << k << endl;
}
