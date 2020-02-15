#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> iPair;
struct scope
{
    int start, end;
    /*int operation;
    int scopes;
    int value;*/
};
double ugly = 31;
double calc(vector<char>)
int main()
{
string str;
cin >>str;
int n = s.size();
vector<char> s(n);
for(int i = 0; i < n; i++)
{
    s[i] = str[i];
}
vector<scope> brackets;
vector<bool> used(n, true;)
stack<int> b;
for(int i = 0; i < n; i++)
{
    if(s[i] == '(')
    {
        b.push(i);
    }
    else if(s[i] == ')')
    {
        scope sc;
        sc.start = b.top();
        sc.end = i;
        /*operation = 0;
        scopes = 0;
        value = 0;*/
        brackets.push_back(sc);
        b.pop();
    }
}
for(int i = 0; i < n; i++)
{
    int srt = brackets[i].start;
    int end= brackets[i].end;
    if(srt - 1 > 0 && s[srt - 1] == '+' && end + 1 < n && (s[end + 1] == '+' ||  s[end + 1] == '-'))
    {
        used[srt] = false;
        used[end]= false;
    }
}
return 0;
}

