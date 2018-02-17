#include<iostream>
using namespace std;
int main()
{
    bool ovelichislo_li_se_e,da_produlzhavam_li,ima_li_lipshvastha_cifra_v_chisloto = false;
    long long ostatuk,broi_ovce,broi_lipsvashti_cifri,turseno,kopie_na_turseno;
    cin>>broi_ovce>>broi_lipsvashti_cifri;
    long long lipshvashti_cifri[broi_lipsvashti_cifri];
    for(int i = 0 ; i < broi_lipsvashti_cifri ; i++)cin>>lipshvashti_cifri[i];
    for(int i = 0,turseno = 1;i < broi_ovce ; i++,turseno++)
    {
        for(int j = 0,kopie_na_turseno = turseno,ima_li_lipshvastha_cifra_v_chisloto = false,ovelichislo_li_se_e = false;kopie_na_turseno > 0 ; j++)
        {
            ostatuk = kopie_na_turseno%10;
            kopie_na_turseno/=10;
            for(int x = 0,da_produlzhavam_li = true;x < broi_lipsvashti_cifri && da_produlzhavam_li ; x++){
            if(ostatuk == lipshvashti_cifri[x])
            {
                ima_li_lipshvastha_cifra_v_chisloto = true;
                da_produlzhavam_li = false;
            }
            }
            if(ima_li_lipshvastha_cifra_v_chisloto && ovelichislo_li_se_e == false){
                    broi_ovce++;
                    ovelichislo_li_se_e = true;
            }
        }
    }
    cout<<broi_ovce<<"\n";
        return 0;
}
