#include<iostream>
using namespace std;

int a[1400],b[1400],br=1,p;
bool pal=false;
void palindrom(int n)
{int i=-1,j=0;
b[0]=n;b[br-1]=n;

for(i=0;i<br;i++)
cout<<b[i];

for(j=br-1;j>=0;j--)
{if(b[j]>a[j]){pal=true; break; }
 else if(b[j]<a[j])break;}
 cout<<j<<endl;
   
    while(pal==false)
{  i++; cout<<i<<endl;
    if(i==p)i=0;
    b[p-i]++; b[p+i+1]++;
    if(b[1]==9){for(j=1;j<br-1;j++)
                b[j]=0;    
                b[0]++;b[br-1]++;}    
    
   for(j=br-1;j>=0;j--)
{if(b[j]>a[j]){ pal=true; break;}
 else if(b[j]<a[j])break;} 
}
    
}
int main()
{
 
int i=0;
long long n;
cin>>n;
//cout<<n;

while(n>0)
{a[i]=n%10;
n=n/10;
i++;
//cout<<br;
br++;  
}
br=br-1;
cout<<br<<endl;

for(i=0;i<br;i++)
cout<<a[i];
  cout<<endl;  

p=br/2-1;
n=a[br-1];
cout<<n<<endl;
if(br%2==0)
{palindrom(n);
    
}

for(i=0;i<br;i++)
cout<<b[i];

return 0;
}