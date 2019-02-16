 #include<iostream>
 using namespace std;
 int main()
{
 long long int a,b,c,i,r,br=0;
 cin>>a>>b;
 for(i=a;i<=b;i++)
 for(r=2;r<i;r++)
 {if(r*r==i)br++;}


cout<<br<<endl;
}
