#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    string s,s1; bool yes = false;
    cin>>s;
    s1 = s;
    int first = int('A');
    int last = int('Z');

    for(char j = 'A'; j <= 'Z'; j++)
    {
         for(int i = 0; i < s.size(); i++)
        {
            if(s[i]== j){ s[i] = char(first); yes = true;}

        }
        if(yes){ first++; yes = false;}
    }



    for(char j = 'Z'; j >= 'A'; j--)
    {
       for(int i = 0; i < s.size(); i++)
        {
            if(s1[i]== j){ s1[i] = char(last); yes = true;}

        }
        if(yes){ last--; yes = false;}
    }


    cout<<s<<endl;
    cout<<s1<<endl;

}
