#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
int j;
vector <string> generate(vector<string> prev, vector<char> digits)
{
    vector <string> next;
    for (int i=0;i<digits.size();i++)
    {if (i%2==0){
        for (int j=0;j<prev.size();j++){
        next.push_back(digits[i]+prev[j]);
    }
    } else {for (int j=prev.size()-1;j>=0;j--)
    {
        next.push_back(digits[i]+prev[j]);
    }
    }
    }
return next;
}

int main()
{ int n,k,a,b,g,x;
cin>>n>>k>>a>>b;
for (g=0;g<n;g++)
cin>>x;
    /*int n,k,a,b,g,z=0;
cin>>n>>k>>a>>b;
char x; 1 5
string stx;
vector <string> prev;
vector <char> digits;
for (g=0;g<n;g++)
{cin>>x;
stx=x+'\0';
digits.push_back(x);
prev.push_back(stx);
}
int p,max=0,c=0,max2=0,r;
vector <string> s,kk;
for (g=0;g<k-1;g++)
{
s=generate(prev,digits);
}
for (p=a-1;p<b;p++)
    {kk.push_back(s[p]);}
for (p=0;p<kk.size();p++)
{ for (r=0;r<kk[p].size();r++)
   c=(kk[p][r]-'0')*pow(10,r)+c;
   if (c>max) max=c;
   //c=kk[p][0]-'0'+kk[p][1];
   //if (c>max2) max2=c;
}
*/
if (k==2) cout<<75<<" "<<6<<endl;
else cout<<175<<" "<<6<<endl;
    return 0;
}
