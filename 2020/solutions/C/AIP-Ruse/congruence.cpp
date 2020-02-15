#include<iostream>
#include<algorithm>

using namespace std;

bool used[1000];

char change[1000];

int main()
{
    string a;
    char where = 'A';
    cin>>a;
    
    for(int i = 0;i < a.size();i++)
    {
        used[a[i]] = true;
    }
    
    for(int i = 'A';i <= 'Z';i++)
    {
        if(used[i] == true)
        {
            change[i] = where;
            where++;
        }
    }
    
    for(int i = 0;i < a.size();i++)
    {
        cout<<change[a[i]];
    }
    cout<<endl;
    
    where = 'Z';
    
    for(int i = 'Z';i >= 'A';i--)
    {
        if(used[i] == true)
        {
            change[i] = where;
            where--;
        }
    }
    
    for(int i = 0;i < a.size();i++)
    {
        cout<<change[a[i]];
    }
    cout<<endl;
    
    return 0;
}

/*
class symbol
{
public:
    char ch;
    char ch2;
    int indx;
};

bool sorter(symbol a, symbol b)
{
    return a.ch < b.ch;
}

bool sorter2(symbol a, symbol b)
{
    return a.indx < b.indx;
}

int main()
{
    string a;
    
    cin>>a;
    
    symbol b[a.size()];
    
    char where = 'A';
    
    for(int i = 0;i < a.size();i++)
    {
        b[i].ch = a[i];
        b[i].indx = i;
    }
    
    sort(b,b + a.size(),sorter);
    
    for(int i = 0;i < a.size();i++)
    {
        b[i].ch = where;
        where++;
        if(i != a.size() - 1)
        {
            if(b[i + 1].ch == b[i].ch)
            {
                where--;
            }
        }
    }
    
    where = 'Z';
    
    for(int i = a.size() - 1;i >= 0;i--)
    {
        b[i].ch2 = where;
        where--;
        if(i != 0)
        {
            if(b[i - 1].ch == b[i].ch)
            {
                where++;
            }
        }
    }
    
    sort(b,b + a.size(),sorter2);
    
    for(int i = 0;i < a.size();i++)
    {
        cout<<b[i].ch;
    }
    cout<<endl;
    
    for(int i = 0;i < a.size();i++)
    {
        cout<<b[i].ch2;
    }
    cout<<endl;
}
*/