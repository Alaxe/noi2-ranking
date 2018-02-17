#include<iostream>
#include<string.h>
#include<string>
using namespace std;
int ans1[201],ans2[201],len1;
int find (int a[], int len, int step) {
    int l[201],r[201],mid[201],sb[201],mult[201];
    int prev1,cur,st,fl,i,j,dig;
    for (i=0; i<len1; i++) {
        l[i]=0; r[i]=9;
        } //cout << "aaaa" << step << "aaa";
    for (;;) {
        prev1=1;
        for (i=len1-1; i>=0; i--) {
            sb[i]=l[i]+prev1;
            prev1=sb[i]/10; sb[i]%=10;
            }
        fl=0;
        for (i=0; i<len1; i++) {
            if (sb[i]==r[i]) continue;
            fl++;
            break;
            }
        if (fl==0) break;
        prev1=0;
        for (i=len1-1; i>=0; i--) {
            sb[i]=l[i]+r[i]+prev1;
            prev1=sb[i]/10; sb[i]%=10;
            }
        prev1=0;
        for (i=0; i<len1; i++) {
            dig=prev1*10+sb[i];
            prev1=dig%2; dig/=2;
            mid[i]=dig;
            }
        /*for (i=0; i<len1; i++) {
            cout << l[i] ;
            } cout << "    ";
        for (i=0; i<len1; i++) {
            cout << r[i] ;
            } cout << "    ";
        for (i=0; i<len1; i++) {
            cout << mid[i] ;
            } cout << endl ;*/
        memset(mult,0,sizeof(mult));
        cur=len1-1;
        for (i=len-1; ; i--) {
            mult[i]=mid[cur]; cur--;
            if (cur==-1) break;
            }
        for (i=len1-1; i>=0; i--) {
            st=len-1-(len1-1-i); prev1=0;
            for (j=st; j>st-len1; j--) {
                dig=prev1+mult[j]+mid[i]*mid[len1-1-(st-j)];
                prev1=dig/10; dig%=10;
                mult[j]=dig;
                }
            for (j=st-len1; ; j--) {
                if (prev1==0) break;
                dig=mult[j]+prev1;
                prev1=dig/10; dig%=10;
                mult[j]=dig;
                }
            }
        /*for (i=0; i<len; i++) {
            cout << mult[i] ;
            } cout << endl ;*/
        fl=0;
        for (i=0; i<len; i++) {
            if (mult[i]==a[i]) continue;
            if (mult[i]<a[i]) fl=-1;
            else fl=1;
            break;
            }
        if (step==0) {
           if (fl>=0) {
              for (i=0; i<len1; i++) {
                  r[i]=mid[i];
                  }
              }
           else { for (i=0; i<len1; i++) {
                      l[i]=mid[i];
                      } }
           }
        else { if (fl>0) {
                  for (i=0; i<len1; i++) {
                      r[i]=mid[i];
                      }
                  }
               else { for (i=0; i<len1; i++) {
                          l[i]=mid[i];
                          } } }
        }
    for (i=0; i<len1; i++) {
        if (step==0) ans1[i]=l[i];
        else ans2[i]=l[i];
        }

}
int main () {
    string a,b;
    int num1[201],num2[201],len,fl,i;
    cin >> a >> b ;
    for (i=b.size()-a.size(); i>=1; i--) {
        a="0"+a;
        }
    len=a.size(); len1=len/2+1;
    a="0"+a; b="0"+b;
    a="0"+a; b="0"+b;
    len=a.size();
    for (i=0; i<len; i++) {
        num1[i]=a[i]-'0';
        num2[i]=b[i]-'0';
        }
    find(num1,len,0);
    find(num2,len,1);
    for (i=len1-1; i>=0; i--) {
        if (ans2[i]<ans1[i]) ans2[i-1]--, ans2[i]+=10;
        ans2[i]-=ans1[i];
        }
    fl=0;
    for (i=0; i<len1; i++) {
        if (ans2[i]!=0) fl++;
        if (fl!=0) cout << ans2[i] ;
        if ((fl==0)&&(i==len1-1)) cout << 0 ;
        }
    return 0;
}
