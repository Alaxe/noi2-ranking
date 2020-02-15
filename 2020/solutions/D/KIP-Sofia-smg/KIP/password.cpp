#include<bits/stdc++.h>
using namespace std;
int sreshtania[30];
vector<pair<char,int>> nepravilni;
vector<pair<int,int>> problems;
vector<char> zamestvane;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin>>a;

    int d=a.size(),half=d/2;
    for(int i=0;i<d;i++) {
        sreshtania[a[i]-'a']++;
    }



    for(int i=0;i<28;i++) {
        if(sreshtania[i]<half) {
            zamestvane.push_back(i+'a');
        }
    }
    reverse(zamestvane.begin(),zamestvane.end());



    for(int i=0;i<a.size();i++) {
        int j,nachalo=i,duljina=0;
        for(j=i;a[j]==a[i];j++) {
            duljina++;
        }
        if(duljina>1) {
            i=nachalo+duljina-1;
            problems.push_back(make_pair(nachalo,duljina));
        }
    }


    for(int i=0;i<problems.size();i++) {
        int nachalo=problems[i].first;
        int krai=nachalo+problems[i].second-1;
        for(int j=nachalo+2;j<a.size() && j<=krai;j=j+2) {
            char symbol=zamestvane[zamestvane.size()-1];
            if(a[j]==a[j+1] && a[j+1]==a[j+2]) {
                sreshtania[a[j]-'a']--;
                a[j]=symbol;
                if(symbol-'a'>=0 && symbol-'a'<=27) {
                    sreshtania[symbol-'a']++;
                }
                if(sreshtania[symbol-'a']==half) {
                    zamestvane.pop_back();
                }
            }

        }
    }


    for(int i=0;i<28;i++) {
        if(sreshtania[i]>half) {
            nepravilni.push_back(make_pair(i+'a',sreshtania[i]-half));
        }
    }

    for(int i=0;i<nepravilni.size();i++) {
        char bukva=nepravilni[i].first;
        int broiPuti=nepravilni[i].second;
        for(int j=0;j<a.size() && broiPuti>0;j++) {
            if(a[j]==bukva) {
                a[j]=zamestvane[zamestvane.size()-1];
                sreshtania[zamestvane[zamestvane.size()-1]-'a']++;
                if(sreshtania[zamestvane[zamestvane.size()-1]-'a']==half) {
                    zamestvane.pop_back();
                }
                broiPuti--;
            }
        }
    }
    cout<<a<<endl;

    return 0;
}
