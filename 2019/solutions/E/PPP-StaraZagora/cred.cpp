 #include <iostream>
 using namespace std;
 int main()
{int m;
int n;
 cin>>n>>m;
 int a=n%10;
 n=n/10;
 int b=n%10;
 n=n/10;
 int c=n%10;
 n=n/10;
 int k=n%10;
 n=n/10;
 int e=n%10;
 if (m<=100)
 {
 for (n=n; n=m ; n++) {n=n+a+b;}
 }
 if (m<=1000)
 {
 for (n=n; n=m ; n++) {n=n+a+b+c;}
 }
 if (m<=10000)
 {
 for (n=n; n=m ; n++) {n=n+a+b+c+k;}
 }
 if (m<=100000)
 {
 for (n=n; n=m ; n++) {n=n+a+b+c+k+e;}
 }
 cout<<n<<endl;
    return 0;

}
