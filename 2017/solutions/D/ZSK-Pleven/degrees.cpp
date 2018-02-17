#include <bits/stdc++.h>
using namespace std;
int main()
{
    int temp=1;
    int br=0;
    string s;
    getline(cin, s);
    for(int i=0;i<s.size();)
    {
        i+=temp;
        if(i%3==0)temp++;
        br++;
    }
    if(br>12)
    cout<<br+1<<endl;
    else
    cout<<br<<endl;
    return 0;
}
///2481632641282565121024204840968192163843276865536131072262144
