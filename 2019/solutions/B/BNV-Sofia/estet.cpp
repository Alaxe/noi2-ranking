#include <iostream>
using namespace std;

const int MAX_N = 100000;
int darveta[MAX_N];

int inversii_po_golemi[MAX_N];
int inversii_po_malki[MAX_N];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> darveta[i];
    }
    for(int k = 0; k < n; ++ k)
    {
        int max_found = -1;
        for(int i = k; i < n; ++ i)
        {
            if(darveta[i] > max_found)
            {
                ++ inversii_po_golemi[k];
                max_found = darveta[i];
            }
        }
    }
    for(int k = n-1; k > -1; -- k)
    {
        int max_found = -1;
        for(int i = k; i > -1; -- i)
        {
            if(darveta[i] > max_found)
            {
                ++ inversii_po_malki[k];
                max_found = darveta[i];
            }
        }
    }
    int kolkodarvetaostavat_0_val = -1;
    int kolkodarvetaostavat_1_val = -1;
    int kolkodarvetaostavat_0 = -1;
    int kolkodarvetaostavat_1 = -1;
    for(int i = 0; i < n; i ++)
    {
        if(inversii_po_golemi[i] > kolkodarvetaostavat_0_val)
        {
            kolkodarvetaostavat_0_val = inversii_po_golemi[i];
            kolkodarvetaostavat_0 = i;
        }
    }
    for(int i = n-1; i > -1; i --)
    {
        if(inversii_po_malki[i] > kolkodarvetaostavat_1_val)
        {
            kolkodarvetaostavat_1_val = inversii_po_malki[i];
            kolkodarvetaostavat_1 = i;
        }
    }
    /*cout << kolkodarvetaostavat_0_val << endl << kolkodarvetaostavat_1_val << endl;
    cout << kolkodarvetaostavat_0 << endl << kolkodarvetaostavat_1 << endl;

    for(int i = 0; i < n; i ++)
    {
        cout << inversii_po_golemi[i] << " ";
    }
    cout << endl;
    for(int i = 0; i < n; i ++)
    {
        cout << inversii_po_malki[i] << " ";
    }*/
    //cout<< endl;
    if(kolkodarvetaostavat_0 >= kolkodarvetaostavat_1)
    {
        cout <<max(kolkodarvetaostavat_0_val, kolkodarvetaostavat_1_val) << endl;

        //cout << "im ready";
        return 0;
    }

    int nai_lqvo_nai_malko_0;///tova shte e nai golqmoto v intervala mejdu drugite dva otgovora
    int nai_lqvo_nai_malko_0_val = 200000;
    for(int i = kolkodarvetaostavat_0; i < kolkodarvetaostavat_1 ; i ++)
    {
        if(inversii_po_golemi[i] < nai_lqvo_nai_malko_0_val)
        {
            nai_lqvo_nai_malko_0_val = inversii_po_golemi[i];
            nai_lqvo_nai_malko_0 = i;
        }
    }
    //cout <<nai_lqvo_nai_malko_0 << " " << nai_lqvo_nai_malko_0_val << endl;
    int kolkodarvetaostavat_2_val = kolkodarvetaostavat_1 - kolkodarvetaostavat_0 + 1;
    //cout << kolkodarvetaostavat_2_val << endl;
    for(int i = kolkodarvetaostavat_0; i < nai_lqvo_nai_malko_0; i ++)
    {
        if(darveta[i] >= darveta[i + 1])
        {
            --kolkodarvetaostavat_2_val;
        }
    }
        for(int i = kolkodarvetaostavat_1; i > nai_lqvo_nai_malko_0; i --)
    {
        if(darveta[i] >= darveta[i - 1])
        {
            --kolkodarvetaostavat_2_val;
        }
    }
    //cout << kolkodarvetaostavat_2_val << endl;
    cout << max(max(kolkodarvetaostavat_0_val, kolkodarvetaostavat_1_val), kolkodarvetaostavat_2_val);
}
