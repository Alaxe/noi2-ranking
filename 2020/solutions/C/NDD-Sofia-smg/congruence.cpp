#include <iostream>
using namespace std;
char a[15000000],b[1500000],c[15000000];
bool ima[26];
int main () {
    cin>>a;
    long long i=0,br=0,j=0;
    for(i=0;a[i]!='\0';i++) {
        if (ima[a[i]-'A']==false) {
            ima[a[i]-'A']=true;
            br++;
        }
    }
    char x[br];
    for(i=0;i<26;i++) {
        if(ima[i]==true){
            x[j]='A'+i;
            j++;
        }
    }
    for(i=0;a[i]!='\0';i++) {
        for(j=0;j<br;j++) {
            if(a[i]==x[j]) {
                    b[i]='A'+j;
                    c[i]='Z'-br+1+j;
                    break;
            }
        }
    }
    cout<<b<<endl<<c<<endl;
    return 0;
}
