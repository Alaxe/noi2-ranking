#include <iostream>
using namespace std;
int main () {
string s;
cin>>s;
long long ch=2;
int st=1;
long long ss=s.size();

for (int i=0; i<=ss/2; i++) {
if (ch%10!=s[ss-1] && ch/10%10!=s[ss-2]) {
ch*=2;
st++;
}
else {
break;
}
}
cout<<st<<endl;
}



