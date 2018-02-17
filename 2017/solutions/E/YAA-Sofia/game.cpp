#include<iostream>
using namespace std;
int main()
{
    long long kris,eva,poredicach,cborove=0,dulgred,mqstonanaiblizko,segind=0;
    cin>>kris>>eva;
    long long naiblizko=kris+100000;
    for(dulgred=0; cborove<=eva and dulgred<200 ; dulgred++)
    {
        cin>>poredicach;
        segind++;
        if(poredicach%2==0)
        {
            cborove=cborove+poredicach;
        }
        if(poredicach-kris<0)
        {
            if(naiblizko-kris<0)
            {
                if(0-(naiblizko-kris)>=0-(poredicach-kris)  )
                {
                    naiblizko=poredicach;
                    mqstonanaiblizko=segind;
                }
            }
            else
            {
                if(naiblizko-kris>=0-(poredicach-kris)  )
                {
                    naiblizko=poredicach;
                    mqstonanaiblizko=segind;
                }
            }
        }
        else
        {
            if(naiblizko-kris>0)
            {
                if(naiblizko-kris>=poredicach-kris  )
                {
                    naiblizko=poredicach;
                    mqstonanaiblizko=segind;
                }
            }
            else
            {
                if(0-(naiblizko-kris)>=poredicach-kris  )
                {
                    naiblizko=poredicach;
                    mqstonanaiblizko=segind;
                }
            }
        }
    }


    cout<<mqstonanaiblizko<<" "<<cborove<<endl;


    return 0;
}
