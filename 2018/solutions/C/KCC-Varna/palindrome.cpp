#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i;
    string t;
    cin >> t;
    if(t.size()==1)
    {
        cout << (t[0]-'0')+1 << endl;
        return 0;
    }
    string t2=t;
    for(i=t.size()-1; i>=t.size()/2; i--) t2[i]=t[t.size()-(i+1)];
    if(t<t2)
    {
        cout << t2 << endl;
        return 0;
    }
    if(t.size()%2==0)
    {
        if(t[i]=='9')
        {
            while(t[i]=='9')
            {
                t[i]='0';
                i--;
            }
            if(t[0]=='0') t='1'+t;
            else t[i]=char(((t[i]-'0')+1)+'0');
            for(i=t.size()-1; i>=t.size()/2; i--) t[i]=t[t.size()-(i+1)];
        }
        else
        {
            t[i]=char(((t[i]-'0')+1)+'0');
            for(i=t.size()-1; i>=t.size()/2; i--) t[i]=t[t.size()-(i+1)];
        }
    }
    else
    {
        i++;
        if(t[i]=='9')
        {
            while(t[i]=='9')
            {
                t[i]='0';
                i--;
            }
            if(t[0]=='0') t='1'+t;
            else t[i]=char(((t[i]-'0')+1)+'0');
            for(i=t.size()-1; i>=t.size()/2; i--) t[i]=t[t.size()-(i+1)];
        }
        else
        {
            t[i]=char(((t[i]-'0')+1)+'0');
            for(i=t.size()-1; i>=t.size()/2; i--) t[i]=t[t.size()-(i+1)];
        }
    }
    cout << t << endl;
    return 0;
}
/**
2018
143567
99
149941
14567
14967
*/
