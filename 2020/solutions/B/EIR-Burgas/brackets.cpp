#include <iostream>     ///Should be n
using namespace std;    //I managed to get lost in the recursion. Seems to work, don't know if it does. :(

int sSize;
string s;

bool recurseBrackets(int, int&);

int main()
{
    int currLast;

    cin>>s;
    sSize=s.size();
    s='!'+s+'!';
    for (int i=1; i<=sSize; i++){
        if (s[i]=='('){
            if (recurseBrackets(i, currLast)){
                /*cout<<"!-------!"<<endl;
                cout<<s<<endl;
                for (int j=0; j<i; j++) cout<<" ";
                cout<<"^";
                for (int j=0; j<currLast-i-1; j++) cout<<" ";
                cout<<"^\n";
                cout<<i<<" "<<currLast<<endl;//*/

                s.erase(i, 1);
                s.erase(currLast-1, 1);
                sSize-=2;
                currLast-=2;
            }
            i=currLast;
            continue;
        }
    }

    cout<<s.substr(1, sSize)<<endl;

    return 0;
}

///-------------------------

bool recurseBrackets(int from, int &last)
{
    int currLast, currInside;
    bool before, after, rf=false, inside;

    inside=true;

    if (s[from-1]=='*' or s[from-1]=='/') before=true;
    else before=false;

    for (int i=from+1; ; i++){
        if (s[i]=='&') continue;
        if (s[i]=='('){
            if (recurseBrackets(i, currLast)){
                /*cout<<"!-------!"<<endl;
                cout<<s<<endl;
                for (int j=0; j<i; j++) cout<<" ";
                cout<<"^";
                for (int j=0; j<currLast-i-1; j++) cout<<" ";
                cout<<"^\n";
                cout<<i<<" "<<currLast<<endl;//*/

                s.erase(i, 1);
                s.erase(currLast-1, 1);
                sSize-=2;
                currLast-=2;
            }
            i=currLast;
            continue;
        }
        if (s[i]=='*' or s[i]=='/'){
            if (s[from-1]=='/') rf=true;
            //inside=true;
        }
        if (s[i]=='+' or s[i]=='-') inside=false;

        if (s[i]==')'){
            last=i;
            break;
        }
    }

    if (s[last+1]=='*' or s[last+1]=='/') after=true;
    else after=false;

    if (rf) return false;
    if ((before or after) and !inside) return false;
    if (!inside and s[from-1]=='-') return false;
    return true;
}

/**
((&+&)*&)/&
-------------------
&+(&*(&-&)-(&-&))
-------------------
&+((((&/&))))/&
-------------------
&+(&-(&*(&/&-&)))
-------------------
&/((&*&)*&)
*/
