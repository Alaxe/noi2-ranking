#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int br=0;
    int i=1;
    int num=1;
    while(br<=k)
    {
        string r="";
        string m="1";
        int pred=r[num];
        r[num]++;
        num++;
        m+=r;
        if(r[num]>pred)
        {
            r[num]=pred;
            if(n==pred)
            {
                br++;
                num==i;
            }
        }
        m=m+r[num];
    }
    cout<<i<<endl;
    return 0;
}
