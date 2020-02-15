#include<iostream>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

struct brackets
{
    int na;
    int kr;
    bool use;
};

brackets br[200005];
stack <int> st;
string s;
int broi;

bool cmp(brackets a,brackets b)
{
    return a.na<b.na;
}

int main()
{
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(') st.push(i);
        else if(s[i]==')')
        {
            br[broi].na=st.top();
            br[broi].kr=i;
            br[broi].use=true;
            broi++;
            st.pop();
        }
    }
    for(int i=0;i<broi;i++)
    {
        if(st[br[i].na]-1=='('&&st[br[i].kr]+1==')')

    }
    return 0;
}
/*
((&+&)*&)/&
&+(&*(&-&)-(&-&))
&-((((&/&))))/&
*/
