#include<iostream>
using namespace std;
int main()
{int n;
 cin>>n;
 int x;
 cin>>x;
 int pc=0;
 int br=0;
 if(n>=0&&n<=9)
   {
       cout<<n<<endl;
       return 0;
   }
   if(n==10)
   {
       cout<<"9"<<endl;
       return 0;
   }
 for(int i=0;i<=n;i++)
 {
   cin>>x;
   pc=i-(i/10*10);
   i=i/10;
   while(i>0)
   {
        if(i-i/10*10==pc)
        {
            i=i/10;
            pc=i-i/10*10;
        }
   }
   cin>>x;
   br++;
 }
 cout<<br<<endl;
    return 0;
}
