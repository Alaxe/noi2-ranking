#include<iostream>
#include<string>
using namespace std;

vector prime_nums(long long unsigned int k, vector<long long unsigned int> p)
{
    int x = 3;
    bool flag = false;
    for(int i=1; i<=k;i++)
    {
        for(int j=2; j<(x/2)+1;j++)
        {
           if(x%j==0)
           {
               flag = true;
               break;
           }
        }
        if(!flag)p.push_back(x);
        flag = false;
        x++;
    }
    return p;
}
bool isPrime(long long unsigned int k)
{
    bool flag = true;
    for(int j=2; j<(x/2)+1;j++)
    {
       if(x%j==0)
       {
           flag = false;
           break;
       }
    }
    flag = true;
    return flag;
}
int main()
{
 long long unsigned int n,x,result;
}
