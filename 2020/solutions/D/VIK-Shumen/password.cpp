#include <iostream>
using namespace std;

int main()
{
string a;
cin>>a;
int br=0;
char b='a';
char c=a[0];
int len=a.size();
string d=" ";
for(int i=0;i<len;i++)
{
    if(a[i]==c)
    {
        br++;
    }
    else
    {
        c=a[i];
        br=1;
    }
    if(br==3)
    {
        if(a[i]==b)
        {
            a[i]=b+1;
            b=(int)(b-'a')+2;
            b=(char)(b+'a');
        }
        else
        {
            a[i]=b;
            b=(int)(b-'a')+1;
            b=(char)(b+'a');
        }

    }
}
cout<<a<<endl;
    return 0;
}
