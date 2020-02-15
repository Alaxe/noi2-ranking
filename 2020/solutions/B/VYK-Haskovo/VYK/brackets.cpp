#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int a,limit,x,removeBr;
string s;
char operations[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    limit = s.size();
    for(int i=0;i<limit;i++)
    {
        if(s[i] == ')' && removeBr !=0) {s[i] = ' '; removeBr--;}
        if(s[i] == '*' || s[i] == '+') {operations[x] = s[i];x++;}
        if(s[i] == '(' && s[i-1] == '(')
        {
            s[i-1] = ' ';
            while(s[i]=='(')
            {
                s[i] = ' ';
                i++;
                removeBr++;
            }
            removeBr++;
        }
    }

    for(int i=0;i<limit;i++)
    {
        if(s[i]==' ') continue;
        cout << s[i];
    }
    cout << '\n';
    return 0;
}
