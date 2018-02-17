#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long cards;
    cin>>cards;
    long long razm[cards][2];
    for(long long i=0; i<cards; i++){
            for(long long z=0; z<2; z++){
                    cin>>razm[i][z];
            }
    }
    long long proizv[cards];
    for(long long i=0; i<cards; i++){
            proizv[i]=razm[i][0]*razm[i][1];
    }
    vector<long long> br;
    long long sega=0;
    bool zap=false;
    bool full=true;
    for(long long i=0; i<cards-1; i++){
        if(proizv[i]>=proizv[i+1]){
            sega++;
            zap=true;
        }
        if(proizv[i]<proizv[i+1]){
                if(zap) sega++;
                br.push_back(sega);
                sega=0;
                zap=false;
                full=false;
        }
    }
    if(full) br.push_back(sega+1);
    int ng=0;
    for(long long i=0; i<br.size(); i++){
        if(br[i]>ng) ng=br[i];
    }
    cout<<ng;
    return 0;
}




