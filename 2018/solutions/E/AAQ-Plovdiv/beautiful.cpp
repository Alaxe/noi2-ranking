 #include<iostream>
 using namespace std;
 int main()
 {
     long long n,k,i,z,j;
     cin>>n>>k;
     z=n;
     for (i=0;i<z-1;i++)
     {
         n=n*10;
     }
     n=n/z;
     while (n%k!=0)
     {
         n++;
     }
     cout<<n;
    return 0;
 }
