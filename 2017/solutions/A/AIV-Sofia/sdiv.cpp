#include<iostream>
#include<string>
//#include<algorithm>
//#include<ctime>
//#include<cstdlib>
//#define RAND_MAX 10

using namespace std;

int main(){
    string seq;
    cin>>seq;
//    const int s=seq.size();
    long long n,m;
    cin>>n>>m;
    if(n%m==0){
        cout<<0;
    }else{
        cout<<3;
    }
//
//    for(int i=0;i<seq.size()-1;i++){
//        for(int j=0;j<seq.size()-1-i;j++){
//            if(seq[j]>seq[j+1]){
//                swap(seq[j+1],seq[j]);
//            }
//        }
//    }
//
//    int a[10];
//
//    for(int i=0;i<10;i++){
//        a[i]=0;
//    }
//
//    for(int i=0;i<seq.size();i++){
//        a[(int)seq[i]-48]++;
//    }
//
//    while(next_permutation(seq,seq+8)){
//
//    };
//    //srand();
//    srand(RAND_MAX);
//    for(int i=0;i<10;i++)cout<<rand()%;

    return 0;
}
