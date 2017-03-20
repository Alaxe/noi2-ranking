#include  <bits/stdc++.h>
using  namespace  std;

int main()
{
ios_base::sync_with_stdio(false);
string str;
getline(cin,str);
int s=str.size();
int n,i=0,brsim=0,br=1;
//1 2 3; 5 7 9; 12 15 18; 22 26 30 34; 39 44 49; 55 61 67; 74 81 88 95; 103 111 119 128 137 146 156
do
{
    i++;
    n=3;
    if(br%10==0){n=4;}
    for(int j=1;j<=n;j++)
    {
        brsim+=i;br++;
        if(brsim==s)break;
    }
}while(brsim!=s);
cout<<br-1<<'\n';

return 0;
}

