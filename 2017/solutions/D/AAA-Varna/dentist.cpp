#include<iostream>
#include<algorithm>
using namespace std;
struct test {
int a, b;}
cmp (bool, bool){
 if(a[x][1]<a[x+1][1])return true;
 else return false;
}
int main()
{

    int a[720][2],br=0;
    for(int i=0;i<720;i++){
     cin>>a[i][1]>>a[i][2];
     br++;
    }

    for(int i=0;i<br;i++){
    cout<<a[i][1]<<" "<<a[i][2];
    }
    cout<<endl;
    return 0;
}
