#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, bool> isTrue;

int main()
{
    unsigned long long m, n;
    cin>>m>>n;
    
    unsigned long long res = 0;
    
    unsigned long long numNow = 0;
    unsigned long long lastIndex = 1;
    
    while(true)
    {
        numNow = lastIndex * (lastIndex - 1);
        
        ++lastIndex;
        
        if(numNow >= m && numNow <= n)
        {
            ++res;
        }
        else if(numNow > n)
        {
            break;
        }
    }
    
    cout<<res<<endl;
    
    return 0;
}
