#include <iostream>
#include <string.h>
using namespace std;
int main(){
    char minn='Z',maxx='A';
    string a,smallest,biggest;
    cin>>a;
    smallest=a;
    biggest=a;
    int toadd[a.length()];
    for(long i=1;i<a.length();i++){
        toadd[i]=a[i]-a[i-1];
    }
    for(long long i=0;i<a.length();i++){
        if(minn>a[i]){minn=a[i];}
        if(maxx<a[i]){maxx=a[i];}
    }
    smallest[0]=a[0]-(minn-'A');
    biggest[0]=a[0]+('Z'-maxx);
    for(long i=1;i<a.length();i++){
        smallest[i]=smallest[i-1]+toadd[i];
        biggest[i]=biggest[i-1]+toadd[i];
    }
    cout<<smallest<<endl;
    cout<<biggest<<endl;
    return 0;
}
