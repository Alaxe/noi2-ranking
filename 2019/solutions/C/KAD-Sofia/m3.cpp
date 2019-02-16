#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>>borders;
double results[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s,a,b,c,d;
    long long k;
    cin>>s>>k>>a>>b>>c>>d;
    long long br=k/(4*d);
    int curr_a,curr_b,curr_c;
    switch(br%4){
    case 0:
        curr_a=a;
        curr_b=c;
        curr_c=b;
        break;
    case 1:
        curr_a=b;
        curr_b=a;
        curr_c=c;
        break;
    case 2:
        curr_a=b;
        curr_b=c;
        curr_c=a;
        break;
    case 3:
        curr_a=c;
        curr_b=a;
        curr_c=b;
        break;
    }
    //cout<<br%4<<" "<<curr_a<<" "<<curr_b<<" "<<curr_c<<endl;
    borders.push({curr_a,1});
    borders.push({curr_b,2});
    borders.push({curr_c,3});
    borders.push({d,4});
    double ost=k-br*(4*d);
    int counter=0,last=-1;
    while(!borders.empty()){
        int w=borders.top().second,b=borders.top().first;
        borders.pop();
        double curr=w*b;
        //cout<<b<<" "<<w<<" "<<curr<<" "<<ost<<" ";
        if(curr==ost){
            if(last==-1){
                for(int i=0;i<w;i++){
                    results[i]=b;
                }
            }else{
                for(int i=last;i<w+last and i<4;i++){
                    results[i]=b;
                }
            }
            break;
        }else if(counter==3){
            if(w<4){
                results[w-1]=ost/2;
                results[w]=ost/2;
            }else{
                results[w-1]=ost;
            }
        }else if(curr<ost){
            for(int i=0;i<w;i++){
               results[i]=b;
            }
            last=w;
            ost-=curr;
        }
        counter++;
        //cout<<endl;
    }
    cout<<fixed<<setprecision(3);
    for(int i=0;i<4;i++){
        cout<<results[i]<<" ";
    }
    cout<<endl;
return 0;
}
/**
1 12
2 3 5 7
*/
