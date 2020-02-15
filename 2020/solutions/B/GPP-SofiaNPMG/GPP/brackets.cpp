#include<iostream>
using namespace std;
int main() {
char niz[200000];
cin>>niz;
int a=0;
while (niz[a]!='') {
    if (niz[a]==')') {
        if (niz[a+1]=='/'||niz[a+1]=='*') {

        }
        if (niz[a+1]=='+'||niz[a+1]=='-') {

        }
        if (niz[a+1]==')') {
           niz[a-4] = niz[a-3];
           niz[a-3] = niz[a-2];
           niz[a-2] = niz[a-1];
           niz[a-1] = niz[a];
           int k=a;
           while (niz[k+2]!='') {
            niz[k] = niz[k+2];
            k+=1;
           }
           niz[k] = '';
           niz[k+1] = '';
        }
    }
    else {
        a+=1;
    }
}
return 0;
}

