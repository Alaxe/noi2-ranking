#include<iostream>
#include<vector>
using namespace std;
vector<int> m,n;

void convert(vector<int> &result,string &s){
    for(int i=s.size()-1;i>=0;i--){
        result.push_back(s[i]-'0');
    }
}

void print(vector<int> &a){
    if(a.size()==0){
        cout<<"0\n";
        return;
    }
    for(int i=a.size()-1;i>=0;i--){
            cout<<a[i];
    }
    cout<<"\n";
}

int cmp(vector<int> &a,vector<int> &b){
    if(a.size()>b.size()) return 1;
    if(a.size()<b.size()) return 0;
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]>b[i]) return 1;
        if(a[i]<b[i]) return 0;
    }
    return 2;
}

void longSum(vector<int> &a,vector<int> &b){
    for(int i=0;i<b.size();i++){
        a[i]+=b[i];
    }
    for(int i=0;i+1<a.size();i++){
            a[i+1]+=a[i]/10;
            a[i]%=10;
    }
    while(a.back()>9){
            int mem=a.back();
            a.back()%=10;
            a.push_back(mem/10);
    }
}

void longMinus(vector<int> &a,vector<int> &b){
    for(int i=0;i<b.size();i++){
        if(a[i]<b[i]){
                a[i]=a[i]+10-b[i];
                int j=i+1;
                while(a[j]==0){
                        a[j]=9;
                        j++;
                }
                a[j]--;
        }else{
            a[i]-=b[i];
        }
    }
    while(a.size()!=0 && a.back()==0){
            a.pop_back();
    }
}

void mul(vector<int> &result,vector<int> &a,vector<int> &b){
    for(int i=0;i<a.size()+b.size();i++){
            result.push_back(0);
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            result[i+j]+=a[i]*b[j];
        }
    }
    for(int i=0;i+1<result.size();i++){
        result[i+1]+=result[i]/10;
        result[i]%=10;
    }
    while(result.back()>9){
            int mem=result.back();
            result.back()%=10;
            result.push_back(mem/10);
    }
    while(result.back()==0){
            result.pop_back();
    }
}

void del2(vector<int> &a){
    vector<int> result;
    int current=0;
    for(int i=a.size()-1;i>=0;i--){
        current*=10;
        current+=a[i];
        result.push_back(current/2);
        current%=2;
    }
    for(int i=0;i<result.size()/2;i++){
            swap(result[i],result[result.size()-1-i]);
    }
    while(result.back()==0){
            result.pop_back();
    }
    a=result;
}

void pow2(vector<int> &a,int power){
    a.push_back(1);
    for(int i=0;i<power;i++){
            for(int i=0;i<a.size();i++){
                a[i]*=2;
            }
            for(int i=0;i+1<a.size();i++){
                    a[i+1]+=a[i]/10;
                    a[i]%=10;
            }
            while(a.back()>9){
                    int mem=a.back();
                    a.back()%=10;
                    a.push_back(mem/10);
            }
    }
}

void longSqrt(vector<int> &result,vector<int> &a){
    vector<int> copyA=a;
    int cnt=0;
    while(copyA.size()>0){
        del2(copyA);
        cnt++;
    }
    cnt--;
    cnt/=2;
    pow2(copyA,cnt);
    cnt--;
    for(int i=cnt;i>=0;i--){
        vector<int> helper1,helper2;
        pow2(helper1,i);
        longSum(copyA,helper1);
        mul(helper2,copyA,copyA);
        if(cmp(helper2,a)==2){
                result=copyA;
                return;
        }
        if(cmp(helper2,a)==1){
                longMinus(copyA,helper1);
        }
    }
    result=copyA;
}

void plusOne(vector<int> &a){
    int prenos=1;
    for(int i=0;i<a.size();i++){
        a[i]+=prenos;
        prenos=a[i]/10;
        a[i]%=10;
        if(prenos==0) break;
    }
    if(prenos!=0) a.push_back(prenos);
}

void minusOne(vector<int> &result){
    int j=0;
    while(result[j]==0){
            result[j]=9;
            j++;
    }
    result[j]--;
    if(result.back()==0) result.pop_back();
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string strm,strn;
    cin>>strm>>strn;
    convert(m,strm);
    convert(n,strn);
    vector<int> sqrtm,sqrtn;
    longSqrt(sqrtm,m);
    vector<int> sqrtmNext=sqrtm,sqrtmMul;
    plusOne(sqrtmNext);
    mul(sqrtmMul,sqrtm,sqrtmNext);
    if(cmp(sqrtmMul,m)!=0){
            minusOne(sqrtm);
    }
    longSqrt(sqrtn,n);
    vector<int> sqrtnNext=sqrtn,sqrtnMul;
    plusOne(sqrtnNext);
    mul(sqrtnMul,sqrtn,sqrtnNext);
    if(cmp(sqrtnMul,n)==1){
            minusOne(sqrtn);
    }
    longMinus(sqrtn,sqrtm);
    print(sqrtn);
    return 0;
}
