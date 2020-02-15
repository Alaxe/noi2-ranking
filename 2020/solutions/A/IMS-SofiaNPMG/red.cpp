#include<iostream>
#include<vector>
using namespace std;

const int MAXN=1e5+5,MAXAB=2*1e6+5;
long long red1[MAXN],red2[MAXN],poredni,koi,brRed1,brRed2;
long long br1[MAXAB],br2[MAXAB];

vector<int> edno,dve;

long long ravni(){
    ///111111111111
    long long otg=0,curr=1;
    long long minch=min(red1[0],red2[0]),maxch=max(red1[0],red2[0]);
    for(int i=1;i<brRed1;i++){
        minch=min(red1[i],minch);
        maxch=max(red1[i],maxch);
        if(red1[i]==red1[i-1]){
            curr++;
        }else{
            br1[red1[i-1]]+=max(0ll, curr-poredni+1);
            curr=1;
        }
    }
    if(curr>1){
        br1[red1[brRed1-1]]+=max(0ll, curr-poredni+1);
    }
    ///222222222222
    curr=1;
    for(int i=1;i<brRed2;i++){
        minch=min(red2[i],minch);
        maxch=max(red2[i],maxch);
        if(red2[i]==red2[i-1]){
            curr++;
        }else{
            br2[red2[i-1]]+=max(0ll, curr-poredni+1);
            curr=1;
        }
    }
    if(curr>1){
        br2[red2[brRed2-1]]+=max(0ll, curr-poredni+1);
    }
    ///otg
    //cout<<minch<<" "<<maxch;
    for(int i=minch;i<=maxch;i++){

        otg=otg+br1[i]*br2[i];
    }
    return otg;
}

long long narastvasta(){
    long long otg=0,br=1;
    for(int i=1;i<brRed1;i++){
        if(red1[i]<=red1[i-1]){
            /*if(br>=poredni){
                cout<<i-br<<" "<<flush;
                edno.push_back(i-br);
            }*/
            br=1;
        }else{
            br++;
            if(br>=poredni){
                edno.push_back(i-poredni+1);
                //cout<<i-poredni+1<<" "<<flush;
            }
        }
    }
    br=1;
    //cout<<"\n"<<flush;
    for(int i=1;i<brRed2;i++){
        if(red2[i]<=red2[i-1]){
            /*if(br>=poredni){
                cout<<i-br<<" "<<flush;
                dve.push_back(i-br);
            }*/
            br=1;
        }else{
            br++;
            if(br>=poredni){
                dve.push_back(i-poredni+1);
                //cout<<i-poredni+1<<" "<<flush;
            }
        }
    }
    //cout<<"\n"<<flush;
    for(int i=0;i<edno.size();i++){
        //cout<<"wtf"<<i<<endl<<flush;
        for(int j=0;j<dve.size();j++){
                //cout<<"uat"<<j<<" "<<dve[j]<<" "<<endl<<flush;
            bool ednakvi=true;
            for(int k=0;k<poredni;k++){
                //cout<<"bla"<<k<<" "<<edno[i]<<" "<<dve[j]<<" "<<endl<<flush;
                if(red1[edno[i]+k]!=red2[dve[j]+k]){
                    ednakvi=false;
                }
            }
            if(ednakvi){
                //cout<<"################################TUK"<<i<<" "<<j<<" "<<edno[i]<<" "<<dve[j]<<"\n";
                otg++;
            }
        }
    }
    return otg;
}


/**
long long narastvasta(){
    long long otg=0;
    long long minch=min(red1[0],red2[0]),maxch=max(red1[0],red2[0]);
    for(int i=0;i<brRed1;i++){
        minch=min(red1[i],minch);
        maxch=max(red1[i],maxch);
        edno[red1[i]].push_back(i);
    }
    for(int i=0;i<brRed2;i++){
        minch=min(red2[i],minch);
        maxch=max(red2[i],maxch);
        dve[red2[i]].push_back(i);
    }
    for(int curr=minch;curr<=maxch;curr++){
        for(int j=0;j<edno[curr].size() and edno[curr][j]+poredni-1<brRed1;j++){
            for(int i=0;i<dve[curr].size() and dve[curr][i]+poredni-1<brRed2;i++){
                bool ednakvi=true;
                for(int k=0;k<poredni;k++){
                    if(red1[k+edno[curr][j]]!=red2[k+dve[curr][i]]){
                        ednakvi=false;
                        break;
                    }
                }
                if(ednakvi){
                    otg++;
                }
            }
        }
    }
    return otg;
}
*/

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>koi>>poredni;
    cin>>brRed1;
    for(int i=0;i<brRed1;i++){
        cin>>red1[i];
    }
    cin>>brRed2;
    for(int i=0;i<brRed2;i++){
        cin>>red2[i];
    }
    cout<<(koi==1?narastvasta():ravni())<<"\n";
    return 0;
}
