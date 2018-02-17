#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int tests,current_test;
vector < int > a,b,ans;
int d;
int base;

vector < int > get_vector(string a) {
    vector < int > ans;
    ans.push_back(0);
    for(int i=0;i<(int)(a.size());i++) {
        if(a[i]>='0' && a[i]<='9') ans.push_back(a[i]-'0');
        else ans.push_back(a[i]-'A'+10);
    }
    return ans;
}

void print(vector < int > a) {
    for(int i=1;i<(int)(a.size());i++) {
        if(a[i]>=0 && a[i]<=9) cout<<a[i];
        else cout<<(char)('A'+(a[i]-10));
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i;

    tests=4;
    cin>>base;
    for(current_test=1;current_test<=tests;current_test++) {
        string tmp;
        cin>>tmp;
        b=get_vector(tmp);
        d=(int)(b.size())-1;

        //Try to construct a solution with d digits
        if(d!=1) {
            a.assign(d+1,0);
            for(int a1=1;a1<base;a1++) {
                a[1]=a1;
                int carry=0;
                for(i=d;i>=2;i--) {
                    if(a[i==d ? 1 : i+1]>=(b[i]+carry)) {
                        a[i]=a[i==d ? 1 : i+1]-(b[i]+carry);
                    }
                    else {
                        a[i]=base+a[i==d ? 1 : i+1]-(b[i]+carry);
                    }
                    carry=(a[i]+b[i])/base;
                }
                if(carry+b[1]+a[1]==a[2]) {
                    print(a);
                    goto NEXT_CASE;
                }
            }
        }

        //TODO: Try to construct a solution with d+1 digits
        a.assign(d+2,0);
        for(int a1=1;a1<base;a1++) {
            a[1]=a1;
            int carry=0;
            for(i=d+1;i>=2;i--) {
                if(a[i==d+1 ? 1 : i+1]>=b[i-1]+carry) {
                    a[i]=a[i==d+1 ? 1 : i+1]-(b[i-1]+carry);
                }
                else {
                    a[i]=base+a[i==d+1 ? 1 : i+1]-(b[i-1]+carry);
                }
                carry=(a[i]+b[i-1])/base;
            }
            if(carry+a[1]==a[2]) {
                print(a);
                goto NEXT_CASE;
            }
        }

        //No solution
        cout<<0<<endl;

        NEXT_CASE:
        continue;
    }

    return 0;
}
