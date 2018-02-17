#include<iostream>
#include<vector>
using namespace std;
int main(){
    string str;
    vector<int> letters[30];
    unsigned long long br=0;
    cin>>str;
    br+=str.length();
    for(int i=0;i<str.length();i++){
        letters[(int)str[i]-97].push_back(i);
    }
    for(int i=0;i<30;i++){
        unsigned long long temp = 0;
        for(int j=0;j<letters[i].size();j++){
            if(j!=0){
                br += (letters[i][j] - letters[i][0])+temp;
                temp += (letters[i][j] - letters[i][0]);
            }
        }
    }
    cout<<br%1000000007<<endl;
    return 0;
}
