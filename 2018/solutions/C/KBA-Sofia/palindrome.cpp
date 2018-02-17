#include<iostream>
using namespace std;
string n;
bool mojeDaSeUwelichi(int duljina) {
    bool razlichniSa=false;
    bool lqwa;
    int broqch=duljina/2;
    int left,right;
    while(!razlichniSa && broqch<duljina) {
        right=n[broqch]-'0';
        left=n[duljina-broqch-1]-'0';
        if(right!=left) {
            razlichniSa=true;
            if(right>left) {
                lqwa=false;
            } else {
                lqwa=true;
            }
        }
        broqch++;
    }
    if(!razlichniSa || lqwa==true) {
        return true;
    } else {
        return false;
    }
}
bool mojeDaSeUwelichi2(int duljina) {
    bool razlichniSa=false;
    bool lqwa;
    int broqch=duljina/2+1;
    int left,right;
    while(!razlichniSa && broqch<duljina) {
        right=n[broqch]-'0';
        left=n[duljina-broqch-2]-'0';
        if(right!=left) {
            razlichniSa=true;
            if(right>left) {
                lqwa=false;
            } else {
                lqwa=true;
            }
        }
        broqch++;
    }
    if(!razlichniSa || lqwa==true) {
        return true;
    } else {
        return false;
    }
}
int main() {
    cin>>n;
    int l=n.length();
    int m;
    int h=0;
    if(l%2==0) {
        if(!mojeDaSeUwelichi(l)) {
            m=l/2-1;
            while(n[m]=='9' && m>=0) {
                m--;
                h+=2;
            }
            n[m]++;
            m++;
            while(h>0) {
                n[m]='0';
                h--;
                m++;
            }
        } else {
            m=l/2;
        }
        while(m<l) {
            n[m]=n[l-m-1];
            m++;
        }
    } else {
        if(!mojeDaSeUwelichi(l)) {
            m=l/2;
            while(n[m]=='9' && m>=0) {
                if(m==l/2) {
                    h++;
                } else {
                    h+=2;
                }
                m--;
            }
            n[m]++;
            m++;
            while(h>0) {
                n[m]='0';
                h--;
                m++;
            }
        } else {
            m=l/2+1;
        }
        while(m<l) {
            n[m]=n[l-m-1];
            m++;
        }
    }
    cout<<n;
    return 0;
}
