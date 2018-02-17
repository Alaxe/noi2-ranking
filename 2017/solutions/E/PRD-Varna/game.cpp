#include<iostream>
using namespace std;
int main()
{
    int m, k, sumk=0, nomer=1,i=1, ch, minraz=100000;
    cin>>m>>k;
    while(i>=0)
    {
        cin>>ch;
        if(ch%2==0) sumk+=ch;
        if(ch>m)
        {
            if(ch-m<=minraz){minraz=ch-m; nomer=i;}
        }
        else if(ch<m)if(m-ch<=minraz){minraz=m-ch; nomer=i;}
         i++;
        if(sumk>k || ch==200) break;

    }
    cout<<nomer<<" "<<sumk<<endl;
    return 0;
}
