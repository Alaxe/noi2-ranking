#include <iostream>
#include <map>

using namespace std;
#define MAXN 100010

map<int, int> samea;
map<int, int> sameb;

map<string, int> diffa;
map<string, int> diffb;

int w, k, n, m;
int a[MAXN] = {}, b[MAXN] = {};
string stra[MAXN] = {}, strb[MAXN] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>w>>k;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];

        int x = a[i];
        string str = "";

        while(x>0) {
            char t = (char) (x%10) + '0';
            str += t;
            x /= 10;
        }
        stra[i] = str;
    }

    cin>>m;
    for(int i = 0; i < m; i++) {
        cin>>b[i];

        int x = b[i];
        string str = "";

        while(x>0) {
            char t = (char) (x%10) + '0';
            str += t;
            x /= 10;
        }
        strb[i] = str;
    }

    if(w == 2) {
        for(int i = 0; i < n; i++) {
            int br = 1, j;

            for(j = i + 1; j < n; j++)
                if(a[j]==a[i]) br++;
                else break;

            if(br >= k) {
                if(samea.count(a[i]) > 0) samea[a[i]] += br - k + 1;
                else samea[a[i]] = br - k + 1;
            }

            i = j - 1;
        }

        for(int i = 0; i < m; i++) {
            int br = 1, j;

            for(j = i + 1; j < m; j++)
                if(b[j]==b[i]) br++;
                else break;


            if(br >= k) {
                if(sameb.count(b[i]) > 0) sameb[b[i]] += br - k + 1;
                else sameb[b[i]] = br - k + 1;
            }

            i = j - 1;
        }

        long long ans = 0;
        for(map<int, int>::iterator it = samea.begin(); it != samea.end(); ++it) {
            if(sameb.count(it->first) > 0) {
                ans += sameb[it->first] * (it->second);
            }
        }

        cout<<ans<<"\n";
    }

    if(w == 1) {
        for(int i = 0; i < n; i++) {
            int br = 1, j;

            for(j = i + 1; j < n; j++)
                if(a[j]>a[j-1]) br++;
                else break;


            if(br >= k) {
                for(int l = i; l <= j - k; l++) {
                    string str = stra[l];

                    for(int h = l + 1; h < l + k; h++){
                        str += " " + stra[h];
                    }

                    if(diffa.count(str) > 0) diffa[str]++;
                    else diffa[str] = 1;
                }
            }

            i = j - 1;
        }

        for(int i = 0; i < m; i++) {
            int br = 1, j;

            for(j = i + 1; j < m; j++)
                if(b[j]>b[j-1]) br++;
                else break;


            if(br >= k) {
                for(int l = i; l <= j - k; l++) {
                    string str = strb[l];

                    for(int h = l + 1; h < l + k; h++){
                        str += " " + strb[h];
                    }

                    if(diffb.count(str) > 0) diffb[str]++;
                    else diffb[str] = 1;
                }
            }

            i = j - 1;
        }

        long long ans = 0;
        for(map<string, int>::iterator it = diffa.begin(); it != diffa.end(); ++it) {
            if(diffb.count(it->first) > 0) {
                ans += diffb[it->first] * (it->second);
            }
        }

        cout<<ans<<"\n";
    }
    return 0;
}
/*
2 3
11
3 4 4 4 4 5 6 6 6 6 7
16
3 6 6 6 4 4 4 5 6 6 6 7 7 6 6 6

1 2
6
2 1 3 4 3 6
6
3 6 1 3 6 7
*/
