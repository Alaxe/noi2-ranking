#include<iostream>
using namespace std;
string a,b;
void degree()
{
    int l,d=0;
    for(int i=0;i<a.size();i++)
    {
        l=a[i]-48;
        l<<=1;
        l+=d;
        a[i]=l%10+48;
        d=l/10;
    }
    if(d==1)a+="1";
}
int main()
{
cin>>b;
int br=b.size();
a="1";
int k=0;
while(br>0)
{
    degree();
    k++;
    br-=a.size();
}
cout<<k<<endl;
return 0;
}
/*
2
248163264128256512102420484096
*/
