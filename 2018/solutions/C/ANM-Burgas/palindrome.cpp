#include<iostream>
using namespace std;

const int maxi=1303;
string number1;
int number[maxi];

int main()
{
    cin>>number1;
    int t=1;
    int l=number1.length();
    for(int i=l-1; i>=0; i--)
    {
        number[i]=number1[i]-'0';
        t=t*10;
    }
    /*
    for(int i=0; i<l; i++)
    {
        cout<<number[i];
    }
    cout<<endl;
    */
    int same=l/2;
    if(l%2==0)
    {
        same--;
        t=same+1;
        int sameclone=same;
        while(number[sameclone]==number[t])
        {
            if(sameclone==0)
            {
                number[same]++;
                number[same+1]++;
                for(int i=0; i<l; i++)
                {
                    cout<<number[i];
                }
                cout<<endl;
                return 0;
            }
            sameclone--;
            t++;
        }
        if(number[sameclone]>number[t])
        {
            for(int i=0; i<same+1; i++)
            {
                cout<<number[i];
            }
            for(int i=same; i>=0; i--)
            {
                cout<<number[i];
            }
            cout<<endl;
            return 0;
        }
        if(number[sameclone]<number[t])
        {
            number[same]++;
            number[same+1]++;
            for(int i=0; i<same+1; i++)
            {
                cout<<number[i];
            }
            for(int i=same; i>=0; i--)
            {
                cout<<number[i];
            }
            cout<<endl;
            return 0;
        }
    }
    else
    {
        t=same+1;
        int sameclone=same-1;
        while(number[sameclone]==number[t])
        {
            if(sameclone==0)
            {
                number[same]++;
                for(int i=0; i<l; i++)
                {
                    cout<<number[i];
                }
                cout<<endl;
                return 0;
            }
            sameclone--;
            t++;
        }
        if(number[sameclone]>number[t])
        {
            for(int i=0; i<same; i++)
            {
                cout<<number[i];
            }
            for(int i=same; i>=0; i--)
            {
                cout<<number[i];
            }
            cout<<endl;
            return 0;
        }
        if(number[sameclone]<number[t])
        {
            number[same]++;
            for(int i=0; i<same; i++)
            {
                cout<<number[i];
            }
            for(int i=same; i>=0; i--)
            {
                cout<<number[i];
            }
            cout<<endl;
            return 0;
        }
    }
    return 0;
}
