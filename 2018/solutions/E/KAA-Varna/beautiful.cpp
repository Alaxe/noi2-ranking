   #include <iostream>
   using namespace std;
   int main()
{
   int n,k,d;
   cin>>n>>k;
   d=n;
   long long e=1,c=0;
   if (n==1&&k<10) cout<<k<<endl;
   else {for (;d>0;d--){e*=10;}
   e/=10;
   if (n==1&&k>=10) cout<<"NO"<<endl;
   c=e*5+1;
   while (e<c)
   {
   if (e%k==0){cout<<e<<endl; break;}
   e++;
   }
   }
   return 0;
}
