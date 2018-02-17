#include<iostream>
using namespace std;
    int main()
    {
        int c;
        unsigned long long int a,b,st,st1,br=0,br2=0;
        cin>>a;
        cin>>b;
        st1=b-a;
        cin>>c;
        st=a;
        unsigned long long int e[st1];
        for(unsigned long long int j=0;j<=st1;j++)
        {
            for( unsigned long long int i=0;i<100000;i++)
            {
            if(a%2==0)
                br=br+1;
            a=a/2;
            if(a==1)
                break;
            }
        e[j]=br;
        br=0;
        a=st+1+j;
        }

        for(int k=0;k<=st1;k++)
           {
               if(e[k]==c)
                br2=br2+1;
           }
           cout<<br2;
    }
