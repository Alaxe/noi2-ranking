#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

vector<string> generate(vector<string> prev, vector<char> digits)
{
    vector<string> next;
    for(int i=0; i<digits.size(); i++)
    {
        if (i%2==0) {
            for (int j=0; j<prev.size(); j++) {
               next.push_back(digits[i]+prev[j]);
            }
        } else {
            for (int j=0; j<prev.size(); j++) {
               next.push_back(digits[i]+prev[j]);
               cout<<j;
            }
        }
    }
    system("pause");
    return next;
}

int main()
{
    int N,K,A,B;
    char input;
    cin>>N>>K>>A>>B;
    cin.get();
    vector<char> mN;
    vector<string> temp;
    for (int i=0; i<N; i++)
    {
        cin>>input; cin.get();
        mN.push_back(input);
    };
    generate(temp,mN);
}
