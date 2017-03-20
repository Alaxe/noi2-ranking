#include<iostream>

using namespace std;


int next_story(int current,int mul,int add,int mod){
    return (current*mul+add)%mod;
}

int main(){
    int n,k;
    unsigned long long first,mul,add,mod;
    cin>>n>>k>>first>>mul>>add>>mod;

    if(k==1){
        unsigned long long a=0;
        for(int i=0;i<n;i++){
            a+=first;
            first=next_story(first,mul,add,mod);

        }
        cout<<a;
        return 0;
    }


{


//    unsigned long long sum=first;
//    unsigned long long test=first;
//    unsigned long long a,b;
//
//
//    bool cicle[mod];
//    int qq[mod];
//    qq[0]=test;
//
//    for(int i=0;i<mod;i++){
//        cicle[i]=0;
//    }
//    //int summ=0;
//
//    for(int i=0;i<mod;i++){
//        if(cicle[test-1]==false){
//            cicle[test-1]=true;
//            test=next_story(test,mul,add,mod);
//            //summ+=test;
//            qq[i+1]=test;
//        }else{
//            a=get_first_index(qq,mod,qq[test-1]);
//            b=test-2;
//            break;
//        }
//    }


    //cout<<summ;
    //cout<<endl<<a<<" "<<b;
}

}
