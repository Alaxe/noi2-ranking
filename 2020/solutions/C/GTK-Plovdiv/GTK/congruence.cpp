#include<bits/stdc++.h>
using namespace std;
char arr[15000000+1000];
int pos[150];
int main()
{
    string str;
    cin>>str;

    for(int i=0;i<str.size();i++)
    {
        arr[i] = str[i];
    }

    sort(arr, arr + str.size());

    int br=1;
    char prevLetter;

    for(int i=0;i<str.size();i++)
    {
        if(i != 0 && prevLetter == arr[i])
        {
            br--;
        }
        pos[(int)arr[i]] = br;
        prevLetter = arr[i];
        br++;
    }

    string small="", big="";

    for(int i=0;i<str.size();i++)
    {
        int current = pos[(int)str[i]];
        small += (char)(64 + current);
        current = abs((br-1) - pos[(int)str[i]]);
        big += (char)(90 - current);
    }

    cout<<small<<"\n"<<big<<"\n";

    return 0;
}
