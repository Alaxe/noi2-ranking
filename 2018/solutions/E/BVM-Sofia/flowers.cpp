#include<iostream>
using namespace std;
int main()
{
    long long obsth_broi_kapki = 0,kapki,broi_cvetq,nai_golqma_vis = 0;
    cin>>broi_cvetq;
    long long vis_cvetq[broi_cvetq];
    for(int i = 0; i < broi_cvetq ; i++){
        cin>>vis_cvetq[i];
    }
    cin>>kapki;
    for(int i = 0; i < broi_cvetq ; i++){
        if(nai_golqma_vis < vis_cvetq[i]){
            nai_golqma_vis = vis_cvetq[i];
        }
    }
    for(int i = 0 ; i < broi_cvetq ; i++){
         obsth_broi_kapki += (nai_golqma_vis-vis_cvetq[i])*kapki;
    }
    cout<<obsth_broi_kapki<<"\n";
    return 0;
}
