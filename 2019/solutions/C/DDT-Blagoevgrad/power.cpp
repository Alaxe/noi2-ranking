#include<iostream>
#include<vector>
using namespace std;

long long up_power(int number, int power)
{
   int n=number;
   for(int i=2; i<=power; i++)
    number*=n;
   return number;
}

long long nok(long long a, int b, vector<int> prnum)
{
   vector<int> st;
   int s=prnum.size();
   while(a>1 || b>1)
    {
       for(int i=0; i<s; i++)
        {
           if(a%prnum[i]==0 || b%prnum[i]==0)
            {
               st.push_back(prnum[i]);
               if(a%prnum[i]==0)
                a/=prnum[i];
               if(b%prnum[i]==0)
                b/=prnum[i];
               break;
            }
        }
    }

   int s2=st.size();
   a=st[0];
   for(int i=1; i<st.size(); i++)
    {
       a*=st[i];
    }
   return a;
}
int main()
{
   int n, k;
   vector<int> numbers, prnum;
   cin >> n >> k;

   for(int i=2; i<=1000; i++)
    {
       bool b=true;
       for(int p=0; p<prnum.size(); p++)
        if(i%prnum[p]==0)
         b=false;
       if(b)
        prnum.push_back(i);
    }

   int n2;
   cin >> n2;
   numbers.push_back(n2);
   int a=n2;

   for(int i=1; i<n; i++)
    {
       int number;
       cin >> number;
       numbers.push_back(number);

       a=nok(a, number, prnum);
    }
    int a2=a;
   vector<long long> st;
   st.push_back(0);
   st.push_back(1);
   int i=1;
   while(a!=st[i])
    {
       for(i; st[i]<=a; i++)
        {
            st.push_back(up_power(i+1, k));
        }
        a+=a2;
    }
  cout << i << endl;

  return 0;
}
