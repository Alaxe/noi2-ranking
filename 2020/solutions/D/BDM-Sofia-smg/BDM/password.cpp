#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int main() {
string pass;
cin>>pass;
int br=0;
for (int i=0;i<pass.length();i++) {
        br=0;
    for (int j=i+1;j<pass.length();j++) {
        if (pass[i]==pass[j]&&pass[i]==pass[j+1]&&pass[i]==pass[j+2]) {
            if (pass[i]=='a') {
            pass[j+1]='b';
            }else{
            pass[j+1]='a';
            }
            i+=2;
            break;
        }
    }
}
cout<<pass;
return 0;
}
