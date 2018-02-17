#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<string> prev;
vector<char> digits;
vector<string> next;
string masiv[10000];
int main()
{
    int n,k;
    unsigned long long a,b;
    cin>>n>>k>>a>>b;
    for(int a=0; a<n; a++)
    {
        char x;
        string c;
        cin>>x;
        c=x;
        prev.push_back(c);
        digits.push_back(x);
    }
    for(int a = 0; a < k-1; a++)
    {
        for(int i=0; i<digits.size(); i++)
        {
            if(i%2==0)
            {
                for(int j=0; j<prev.size(); j++)
                {
                    next.push_back(digits[i]+prev[j]);
                }
            }
            else
            {
                for(int j = prev.size()-1; j>=0; j--)
                {
                    next.push_back(digits[i]+prev[j]);
                }
            }
        }
        prev.clear();

        swap(next,prev);
    }
    int o=0;
    for(o; o<prev.size(); o++)
    {
        masiv[o]=prev[o];
    }
    int s1=0,s2=0;
    string d=masiv[a-1];
    for(int a=0; a<d.size(); a++)
    {
        s1=s1+(d[a]-'0');
    }
	long long ans=-1;
    for(int h=a; h<=b-1; h++)
    {
        d=masiv[h];
        for(int s=0; s<d.size(); s++)
        {
            s2=s2+(d[s]-'0');
        }
        int z=abs(s1-s2);
        if(z>ans)
			ans=z;
		s1=s2;
		s2=0;
    }
    sort(masiv+a-1,masiv+b);
    reverse(masiv+a-1,masiv+b);
    cout<<masiv[a-1]<<" "<<ans<<endl;
    return 0;
}
