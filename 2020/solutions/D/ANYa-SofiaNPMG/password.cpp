#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> br;
string s;

char findAvailable(int d, char f) {
    for(char c='a';c<'z';c++) {
        if(br[c]+1 <= d && c != f) return c;
    }
}

void posledovatelni() {
    string s2 = s;
    for(int i=0;i<s.size();i++) {
        char seg = s[i];
        int posl = 0, j = i;
        while(s[j] == seg) {
            br[seg]++;
            posl++;
            j++;
        }
        while(posl > 2) {
            s[i+2] = '.';
            posl -= 3;
            i += 3;
        }
        i = j-1;
    }

    for(int i=0;i<s.size();i++) {
        if(s[i] == '.') {
            char neww = findAvailable(s.size()/2, s2[i]);
            s[i] = neww;
            br[s2[i]]--;
            br[neww]++;
        }
    }
}

void broiki() {
    char c;
    for(int i=0;i<s.size();i++) {
        c = s[i];
        if(br[c] > s.size()/2) {
            char neww = findAvailable(s.size()/2, c);
            s[i] = neww;
            br[c]--;
            br[neww]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>s;

    posledovatelni();
    broiki();

    cout<<s<<endl;


    return 0;
}
