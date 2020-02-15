#include <iostream>
using namespace std;
int main (){
int n,br=0,ch;
cin>>n;
for(int i=1;i<=n;i++)
{
    ch=i%10;
    i=i/10;
    if(ch==i){
        br=br+1;
    }
}

cout<<br;
return 0;
}
