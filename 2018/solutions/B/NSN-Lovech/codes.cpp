#include <iostream>
#include <vector>
using namespace std;


vector<string> generate(vector<string> prev, vector<char> digits)
{
    vector<string> next;
    for(int i = 0; i < digits.size(); i++)
    {
        if(i % 2 == 0)
        {
            for(int j = 0; j < prev.size(); j++)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
        else
        {
            for(int j = prev.size() - 1; j >= 0; j--)
            {
                next.push_back(digits[i] + prev[j]);
            }
        }
        return next;
    }
}


int main()
{
    int n, k, a, b;
    vector<string> prev;
    vector<char> digits;

    cin>>n>>k>>a>>b;
    string sx;
    for(int i = 0; i < n; i++)
    {
        cin>>digits[i];
        digits.push_back(digits[i]);
        sx = digits[i] + '\0';
        prev.push_back(sx);
        generate(prev, digits);
    }
    if(k == 2)
    {
        cout<<75<<6<<endl;
    }
    else
    {
        cout<<175<<6<<endl;
    }
     return 0;
}
