#include<iostream>
using namespace std;
int a[26];
int main()
{
    string n;
    cin>>n;
    int br=1;
    for(int i=0; i<n.size(); i++)
    {
        int c=(int)(n[i]-'a');
        a[c]++;
    }
    string rez="";
    for(int i=1; i<n.size(); i++)
    {
        if(n[i]==n[i-1])
            br++;
        else
        {
            int minind=0;
            for(int l=0; l<26; l++)
            {
                if(a[minind]>a[l])
                    minind=l;
            }
            for(int l=0; l<br; l++)
            {
                int minind=0;
                for(int l=0; l<26; l++)
                {
                    if(a[minind]>a[l])
                        minind=l;
                }
                if(br>=3&&br<=5)
                {
                    if(l==br/2)
                        {rez=rez+(char)(minind+'a');
                        a[minind]++;}
                    else
                        rez=rez+n[i-1];
                }
                else if(br>5)
                {
                    if((l+1)%3==0)
                        {rez=rez+(char)(minind+'a');
                        a[minind]++;}
                    else
                        rez=rez+n[i-1];
                }
                else
                    rez=rez+n[i-1];
            }
            br=1;
        }
    }
    int len=n.size();
    int minind=0;
    for(int l=0; l<26; l++)
    {
        if(a[minind]>a[l])
            minind=l;
    }
    for(int l=0; l<br; l++)
    {
        if(br>=3&&br<=5)
        {
            if(l==br/2)
                rez=rez+(char)(minind+'a');
            else
                rez=rez+n[len-1];
        }
        else if(br>5)
        {
            if(l%3==0)
                rez=rez+(char)(minind+'a');
            else
                rez=rez+n[len-1];
        }
        else
            rez=rez+n[len-1];
    }
    br=1;
    cout<<rez<<endl;
    return 0;
}
