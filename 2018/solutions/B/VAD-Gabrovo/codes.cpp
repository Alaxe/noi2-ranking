#include <iostream>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define MAXN 128
using namespace std;

long long a, b;
int n, k;
vector <char> digits;
vector <string> seq;
string max_num="";
int max_diff=-1;

vector <string> Generate (vector <string> previous, vector <char> dig)
{
    vector <string> next;
    for (int i=0; i<dig.size (); i++)
    {
        if (i%2==0)
            for (int j=0; j<previous.size (); j++)
                    next.push_back (dig[i]+previous[j]);
        else
            for (int j=previous.size ()-1; j>=0; j--)
                next.push_back (dig[i]+previous[j]);
    }
    return next;
}

int Difference (string s1, string s2)
{
    int sz=s1.size ();
    int sum1=0, sum2=0;
    for (int i=0; i<sz; i++)
    {
        sum1+=((int)s1[i])-48;
        sum2+=((int)s2[i])-48;
    }
    return fabs(sum1-sum2);
}

int main ()
{
    cin>>n>>k;
    cin>>a>>b;
    a--;
    b--;
    for (int i=0; i<n; i++)
    {
        char ch;
        cin>>ch;
        digits.push_back (ch);
    }
    for (int i=0; i<n; i++)
    {
        string fgh="";
        fgh+=digits[i];
        seq.push_back (fgh);
    }
    for (int i=1; i<k; i++)
            seq=Generate (seq, digits);

    max_num=max (max_num, seq[a]);
    for (int i=a+1; i<=b; i++)
    {
        max_num=max (max_num, seq[i]);
        int diff=Difference (seq[i-1], seq[i]);
        max_diff=max (max_diff, diff);
    }
    cout<<max_num<<' '<<max_diff<<endl;
    return 0;
}
