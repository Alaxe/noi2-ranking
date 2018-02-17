#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector <char> d;
vector <string> s;
vector <string> generate ( vector <string> prev, vector <char> digits )
{
    vector <string> next;
    for(int i=0; i<digits.size(); i++)
    {
        if(i%2 == 0)
        {
            for(int j=0; j<prev.size(); j++)
                next.push_back(digits[i]+prev[j]);
        }
        else
        {
            for(int j=prev.size()-1; j>=0; j--)
                next.push_back(digits[i]+prev[j]);
        }
    }
    return next;
}

int sbor(string r)
{
    int sum=0;
    for(int a=0; a<r.size(); a++)
    {

        sum+=r[a]-'0';
    }
    return sum;
}
int n,k;
long long A,B;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k>>A>>B;

    for(int a=0; a<n; a++)
    {
        char r;
        string t;
        cin>>t;
        r=t[0];
        d.push_back(r);
        s.push_back(t);
    }

    for(int a=1; a<k; a++)
        s=generate(s,d);

    string t=s[A-1];
    int w=sbor(s[A-1]);
    int q,ans=0;
    for(int a=A; a<B; a++)
    {
        t=max(t,s[a]);
        q=sbor(s[a]);
        int ab=abs(w-q);
        ans=max(ans,ab);
        w=q;
    }
    cout<<t<<" "<<ans<<endl;

    return 0;
}
/**
3 2 3 5
7 1 5
*/
