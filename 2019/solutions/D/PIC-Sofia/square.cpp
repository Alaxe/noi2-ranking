#include<iostream>
#include<cmath>
using namespace std;
int NOD(int a,int b)
{
int big=0,small=0,result=1;
if(a>b){big=a;small=b;}
else{big=b;small=a;}
while(result!=0)
    {
    result=big%small;
    //cout<<"big%small=result | "<<big<<"%"<<small<<"="<<result<<endl;
    big=small;small=result;
    }
return big;
}
int NOK(int a,int b)
{
int result=0,help=0;
help=NOD(a,b);
result=help*(a/help)*(b/help);
return result;
}
int main(){
int n,NOKofemall=1,answer=0,B=0;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
for(int i=0;i<n;i++)
    {
    NOKofemall=NOK(a[i],NOKofemall);
    }
int counter=1;
while(answer==0)
    {
    double help=0;
    B=counter*NOKofemall;
    help=sqrt(B);
    if(help==(int) help)
        {
        answer=(int) help;
        break;
        }
    counter++;
    }
cout<<answer<<endl;

return 0;
}
