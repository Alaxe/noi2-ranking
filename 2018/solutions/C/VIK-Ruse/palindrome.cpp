#include<iostream>

using namespace std;

string getHalf(string s)
{
    s.erase(s.size()/2+s.size()%2,s.size()/2);
    
    return s;
}

string reverse(string s)
{
    int i;
    
    for(i=0;i<s.size()/2;i++)
    {
        swap(s[i],s[s.size()-i-1]);
    }
    
    return s;
}

string addOne(string s)
{
    int i;
    
    for(i=s.size()-1;i>=0;i--)
    {
        if(s[i]!='9')
        {
            s[i]++;
            return s;
        }
        s[i]='0';
    }
    s="1"+s;
    
    return s;
}

int main ()
{
    string s,s2;
    
    ios::sync_with_stdio(false);
    
    cin>>s;
    
    if(s.size()%2==0)
    {
        s2=getHalf(s);
        s2=s2+reverse(s2);
        if(s2>s)
        {
            cout<<s2<<endl;
            return 0;
        }
        s2=addOne(getHalf(s));
        
        if(s2.size()>s.size()/2)
        {
            
            s2.erase(s2.size()-1,1);
            s2=s2+reverse(addOne(getHalf(s)));
            cout<<s2<<endl;
            return 0;
        }
        
        s2=s2+reverse(s2);
        cout<<s2<<endl;
        return 0;
    }
    s2=getHalf(s);
    //cout<<s2<<endl;
    s2.erase(s2.size()-1,1);
    s2=getHalf(s)+reverse(s2);
    //cout<<s2<<endl;
    if(s2>s)
    {
        cout<<s2<<endl;
        return 0;
    }
    s2=addOne(getHalf(s));
    
    if(s2.size()>s.size()/2+1)
    {
        
        s2.erase(s2.size()-1,1);
        s2=s2+reverse(s2);
        cout<<s2<<endl;
        return 0;
    }
    
    s2.erase(s2.size()-1,1);
    
    s2=addOne(getHalf(s))+reverse(s2);
    cout<<s2<<endl;
    return 0;
}