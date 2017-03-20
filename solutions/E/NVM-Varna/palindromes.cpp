#include <iostream>
#include <Windows.h>
using namespace std;
int n,d,b,testVal,dryb,onRn = 1,maxval = -9999,dMemGet,bMemGet,edMemGet,desMemGet,stMemGet,hMemGet;
int ed=1,des=2,st=3,h=4;
int mirrors[1000];
int dMem[1000];
int bMem[1000];
int edMem[1000];
int desMem[1000];
int stMem[1000];
int hMem[1000];
bool mirrorSuccess = false;
void isMirrored(int nM) {
while(1) {
if(ed == h && des == st) {
mirrors[onRn]=d*b;
dMem[onRn] = d;
bMem[onRn] = b;
edMem[onRn] = ed;
desMem[onRn] = des;
stMem[onRn] = st;
hMem[onRn] = h;
onRn++;
if(onRn == 1000) {
    break;
}
}
testVal = rand() % nM;
dryb = rand() % 3;
if(dryb == 1) {
d=testVal;
}
else {
    b=testVal;
}
int mirrorNum;
mirrorNum = d * b;
ed = mirrorNum % 10;
des = mirrorNum / 10 % 10;
st = mirrorNum / 100 % 10;
h=mirrorNum / 1000;


}
    for(int i=1; i <=1000;i++) {
        if(maxval < mirrors[i]) {
            maxval = mirrors[i];
            dMemGet = dMem[i];
            bMemGet = bMem[i];
            edMemGet = edMem[i];
            desMemGet = desMem[i];
            stMemGet = stMem[i];
            hMemGet = hMem[i];
        }
    }
    if(bMemGet<dMemGet) {
    cout <<bMemGet<<" "<<dMemGet<<endl;
    }
    else {
        cout <<dMemGet<<" "<<bMemGet<<endl;
    }
    cout <<edMemGet<<desMemGet<<stMemGet<<hMemGet<<endl;
}
int main() {
char c;
cin >>n;
d=n;
b=n;
isMirrored(n);
return 0;
}
