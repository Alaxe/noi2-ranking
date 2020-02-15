#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    long long strlena,br=0,brmax,i,c1;
    char N[18];
    cin>>N;
    strlena=strlen(N);
    br=(strlena-1)*9;
    c1=N[0];
    for(i=0; i<strlena; i++)
    {
        if(N[i]<c1)
        {
            break;
        }
    }
    c1=c1-'0';
    if(i<strlena)
    {
        br+=(c1-1);
    }
    else
    {
        br+=c1;
    }
    cout<<br;
}
