#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <stack>
#include <cstring>
using namespace std;
int palindromes(int a,int b)
{
    cin>>a>>b;
    int pr=a*b;
    int hil=pr/1000;
    int stot=pr/100%10;
    int des=pr/10%10;
    int ed=pr%10;
    int obr=ed*1000+des*100+stot*10+hil;
    return pr+obr;
}
int main()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;
    int max=a*b;
    if(max<palindromes(a,b))max=palindromes(a,b);
    cout<<a<<" "<<b<<endl;
    cout<<palindromes(a,b)<<endl;

    return 0;
}
