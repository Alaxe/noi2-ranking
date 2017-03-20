#include <iostream>
#include <string>

using namespace std;

string input;
int size;
long long res;
char chars[11000];
long long n, m;

bool lastDigits[11];


long long parse(int maxIndex)
{
    long long tens = 1;
    long long ress = 0;
    
    for(int i = 0; i <= maxIndex; ++i)
    {
        ress += (chars[i] - '0') * tens;
        tens *= 10;
    }
    
    return ress;
}

void recursion(int index, int arrIndex)
{
    if(arrIndex < 0)
    {
        if(index == 0)
        {
            return;
        }
        
        index--;
        
        if(parse(index) % n == 0)
        {
            ++res;
        }
        
        return;
    }
    
    recursion(index, arrIndex - 1);
    
    if(index == 0)
    {
        if(lastDigits[input[arrIndex] - '0'])
        {
            chars[index] = input[arrIndex];
            recursion(index + 1, arrIndex - 1);
        }
    }
    else
    {
        chars[index] = input[arrIndex];
        recursion(index + 1, arrIndex - 1);
    }
}

int main()
{
    cin>>input;
    
    size = input.size();
    
    cin>>n>>m;

    int num = 0;
    int lastNum = 0;
    
    while(true)
    {
        lastNum = num % 10;
        
        if(lastDigits[lastNum])
        {
            break;
        }
        
        lastDigits[lastNum] = true;
        num += n;
    }
    
    for(int i  = size - 1; i >= 0; --i)
    {
        if(lastDigits[(input[i] - '0')])
        {
            recursion(0, i);
            break;
        }
    }
    
    cout<<res % m<<endl;
    
    return 0;
}
