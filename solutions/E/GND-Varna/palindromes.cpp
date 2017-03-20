#include<iostream>
using namespace std;
bool is_pal(int ch)
{
int pal=0,curr=ch;
while(ch){
pal=pal*10+ch%10;
ch/=10;
}
if(curr==pal)return 1;
return 0;
}
int main() {

int n,fir,sec,maxch=1;
cin>>n;
for(int i=0;i<n;i++)
for(int j=i+1;j<n;j++)
if(is_pal(i*j) && i*j>maxch){
maxch=i*j;
fir=i;
sec=j;
}
cout<< fir<<" "<< sec<<endl<<maxch <<endl;
}

