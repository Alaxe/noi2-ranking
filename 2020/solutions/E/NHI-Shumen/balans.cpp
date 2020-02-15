#include<iostream>
using namespace std;
int main()
{int n;
 cin>>n;
 char x;
 cin>>x;
 int ab=0;
 int cd=0;
 int po=0;
 for(int i=0;i<n;i++)
 {
     if(x=='a'||x=='b')
     {
         ab++;
     }
     else
     {
         cd++;
     }
     if(i%2==0)
     {
         if(ab==cd)
         {
             po=ab+cd;
         }
     }
 }
 cout<<po<<endl;
    return 0;
}
