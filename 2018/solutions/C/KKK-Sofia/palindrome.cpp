#include<iostream>
bool makeNeeded[13000];
int main(){
    std::cin.tie(nullptr);
    std::cout.sync_with_stdio(false);
    std::string input;
    std::cin>>input;
    int n=input.size();
    int first=(n-1)/2,second=n/2;
    bool requirement=0;
    int needed=1;
    for(int i=0;i<(n+1)/2;i++){
        if(input[first-i]>input[second+i]){
            makeNeeded[i]=1;
        }
    }
    for(int i=(n+1)/2-2;i>=0;i--){
        if(input[first-i]==input[second+i]){
            makeNeeded[i]=makeNeeded[i+1];
        }
    }
    for(int i=0;i<(n+1)/2;i++){
        if(requirement){
            input[second+i]=input[first-i];
            continue;
        }
        if(input[first-i]>input[second+i]){
            input[second+i]=input[first-i];
            requirement=1;
            continue;
        }
        if(input[first-i]<input[second+i]){
            input[first-i]++;
            input[second+i]=input[first-i];
            requirement=1;
            continue;
        }
        if(input[first-i]==input[second+i]){
            if(makeNeeded[i+1]){
                continue;
            }
            if(input[first-i]!='9'){
                input[first-i]++;
                if(first-i!=second+i){
                    input[second+i]++;
                }
                requirement=1;
                continue;
            }else{
                input[first-i]='0';
                input[second+i]='0';
            }
        }
    }
    if(input[0]=='0'){
        input='1'+input;
        input[n]='1';
    }
    std::cout<<input<<std::endl;
    return 0;
}
