#include <iostream>
#include <string>

using namespace std;

bool isBigger(string a, string b) {
    for(int i=0; i<a.length(); i++) {
        if(a[i]!=b[i]) {
            int ia = (int)a[i];
            int ib = (int)b[i];
            if(ib>ia) {
                return true;
            }else {
            return false;
            }
            break;
        }
    }
}

int main() {
    int nLength;
    string n;
    string ansRight="";
    string ansLeft="";
    cin>>n;
    string newstr = n;
    if(n=="1" || n=="2" || n=="3" || n=="4" || n=="5" || n=="6" || n=="7" || n=="8" || n=="9") {
        cout<<n<<endl;
    }else {
       nLength = n.length();

       if(nLength%2==0) {
       for(long long i=0; i<nLength/2; i++) {
            ansRight+=n[i];
       }

       string testAns = ansRight;
       for(int j=nLength/2-1; j>=0; j--) {
            testAns+=ansRight[j];
        }

        if(isBigger(n, testAns)) {
            cout<<testAns<<endl;
        }else {


        if(ansRight[nLength/2-1]=='0') {
            ansRight[nLength/2-1]='1';
        }else if(ansRight[nLength/2-1]=='1') {
            ansRight[nLength/2-1]='2';
        }else if(ansRight[nLength/2-1]=='2') {
            ansRight[nLength/2-1]='3';
        }else if(ansRight[nLength/2-1]=='3') {
            ansRight[nLength/2]='4';
        }else if(ansRight[nLength/2-1]=='4') {
            ansRight[nLength/2-1]='5';
        }else if(ansRight[nLength/2-1]=='5') {
            ansRight[nLength/2-1]='6';
        }else if(ansRight[nLength/2-1]=='6') {
            ansRight[nLength/2-1]='7';
        }else if(ansRight[nLength/2-1]=='7') {
            ansRight[nLength/2-1]='8';
        }else if(ansRight[nLength/2-1]=='8') {
            ansRight[nLength/2-1]='9';
        }else if(ansRight[nLength/2-1]=='9') {
            ansRight[nLength/2-1]='0';
            if(ansRight[nLength/2-2]=='0') {
            ansRight[nLength/2-2]='1';
        }else if(ansRight[nLength/2-2]=='1') {
            ansRight[nLength/2-2]='2';
        }else if(ansRight[nLength/2-2]=='2') {
            ansRight[nLength/2-2]='3';
        }else if(ansRight[nLength/2-2]=='3') {
            ansRight[nLength/2-2]='4';
        }else if(ansRight[nLength/2-2]=='4') {
            ansRight[nLength/2-2]='5';
        }else if(ansRight[nLength/2-2]=='5') {
            ansRight[nLength/2-2]='6';
        }else if(ansRight[nLength/2-2]=='6') {
            ansRight[nLength/2-2]='7';
        }else if(ansRight[nLength/2-2]=='7') {
            ansRight[nLength/2-2]='8';
        }else if(ansRight[nLength/2-2]=='8') {
            ansRight[nLength/2-2]='9';
        }else if(ansRight[nLength/2-2]=='9') {
            ansRight[nLength/2-2]='0';

        }


        }


        for(int j=nLength/2-1; j>=0; j--) {
            ansRight+=ansRight[j];
        }
        cout<<ansRight<<endl;
        }

       }else {
            nLength = n.length();


       for(long long i=0; i<=nLength/2; i++) {
            ansRight+=n[i];
       }

       string testAns = ansRight;
       for(int j=nLength/2-1; j>=0; j--) {
            testAns+=ansRight[j];
        }

        if(isBigger(n, testAns)) {
            cout<<testAns<<endl;
        }
        else {
        if(ansRight[nLength/2]=='0') {
            ansRight[nLength/2]='1';
        }else if(ansRight[nLength/2]=='1') {
            ansRight[nLength/2]='2';
        }else if(ansRight[nLength/2]=='2') {
            ansRight[nLength/2]='3';
        }else if(ansRight[nLength/2]=='3') {
            ansRight[nLength/2]='4';
        }else if(ansRight[nLength/2]=='4') {
            ansRight[nLength/2]='5';
        }else if(ansRight[nLength/2]=='5') {
            ansRight[nLength/2]='6';
        }else if(ansRight[nLength/2]=='6') {
            ansRight[nLength/2]='7';
        }else if(ansRight[nLength/2]=='7') {
            ansRight[nLength/2]='8';
        }else if(ansRight[nLength/2]=='8') {
            ansRight[nLength/2]='9';
        }else if(ansRight[nLength/2]=='9') {
            ansRight[nLength/2-1]='0';
            if(ansRight[nLength/2-1]=='0') {
            ansRight[nLength/2]='1';
        }else if(ansRight[nLength/2-1]=='1') {
            ansRight[nLength/2-1]='2';
        }else if(ansRight[nLength/2-1]=='2') {
            ansRight[nLength/2-1]='3';
        }else if(ansRight[nLength/2-1]=='3') {
            ansRight[nLength/2-1]='4';
        }else if(ansRight[nLength/2-1]=='4') {
            ansRight[nLength/2-1]='5';
        }else if(ansRight[nLength/2-1]=='5') {
            ansRight[nLength/2-1]='6';
        }else if(ansRight[nLength/2-1]=='6') {
            ansRight[nLength/2-1]='7';
        }else if(ansRight[nLength/2-1]=='7') {
            ansRight[nLength/2-1]='8';
        }else if(ansRight[nLength/2-1]=='8') {
            ansRight[nLength/2-1]='9';
        }else if(ansRight[nLength/2-1]=='9') {
            ansRight[nLength/2-1]='0';

        }

        }

        for(int j=nLength/2-1; j>=0; j--) {
            ansRight+=ansRight[j];
        }
        cout<<ansRight<<endl;
        }

    }
    }
}
