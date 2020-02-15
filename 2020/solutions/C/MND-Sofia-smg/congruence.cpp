#include<bits/stdc++.h>
using namespace std;
bool b[30];
vector<pair <int,int> > v;
vector<pair <int,int> > t;
int main(){
    string a;
    cin>>a;
    for(int i=0;i<a.size();i++){
        a[i]=a[i]-'A'+1;
        b[(int)a[i]]=1;
    }
    int counter1=1;
    int counter2=90;
    /*for(int i=0;i<30;i++){
        if(b[i]==1){
            cout<<i<<" ";
        }
    }
    */
    //cout<<endl;
    for(int i=0;i<30;i++){
        if(b[i]==1){
            v.push_back(make_pair(i,counter1));
            counter1++;
        }
    }




    for(int i=29;i>=0;i--){
        if(b[i]==1){
            t.push_back(make_pair(i,counter2));
            //cout<<"*";
            //cout<<i<<" "<<counter2<<endl;
            counter2--;
        }
    }
    for(int i=0;i<a.size();i++){
        //int sec;
        for(int j=0;j<v.size();j++){
            if(v[j].first==(int)a[i]){
                cout<<(char)(v[j].second+64);
                break;
            }
        }
    }
    cout<<endl;
    for(int i=0;i<a.size();i++){
        //int sec;
        for(int j=0;j<t.size();j++){
            if(t[j].first==(int)a[i]){
                cout<<(char)(t[j].second);
                break;
            }
        }
    }
return 0;
}
