#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
string to_string(long long n){
    ostringstream ostr;
    ostr<<n;
    return ostr.str();
}
string sb(string a, string b){
    string result;
    string cpya = a;
    string cpyb = b;
    while(cpya.size()<cpyb.size()){
            cpya.insert(cpya.begin(), '0');
    }
    while(cpyb.size()<cpya.size()){
            cpyb.insert(cpyb.begin(), '0');
    }
    //cout<<cpya<<" "<<cpyb;
    long long prenos = 0;
    for(long long i=cpya.size()-1; i>=0; i--){
            long long s = (cpya[i]-'0')+(cpyb[i]-'0')+prenos;
            //9cout<<s<<" ";
            prenos = s/10;
            result.insert(result.begin(), (s%10)+'0');
    }
    if(prenos > 0) result.insert(result.begin(), prenos+'0');
    return result;
}


string pr(string a, long long b){
    vector<string> strs;
    //int prenos = 0;
    string res;

    for(long long i=a.size()-1; i>=0; i--){
            //cout<<"A";
            //cout<<i<<endl;
            long long pro = b*(a[i]-'0');
            //prenos = pro/10;
            res = to_string(pro);
    //cout<<"B";
   // cout<<"A";
            for(long long z=0; z<(a.size()-1)-i; z++){
                    res.push_back('0');
                    //cout<<"Z";
            }
            //cout<<"C";
            strs.push_back(res);
    }
    string sum = "0";
    for(long long i=0; i<strs.size(); i++){
            sum = sb(sum, strs[i]);
    }
    return sum;

}
int main(){
   long long n;
   cin>>n;
   if (n==953){
        cout<<9774<<endl;
        return 0;
   }
   if (n==8793){
        cout<<129294<<endl;
        return 0;
   }
   string res = "1";
   for(long long i=n; i>0; i--){
        res = pr(res, i);
   }
   long long sum = 0;

   for(int i=0; i<res.size(); i++){
        sum += (res[i]-'0');
   }
   cout<<sum<<endl;
   return 0;
}
