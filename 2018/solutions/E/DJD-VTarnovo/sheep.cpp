#include<iostream>
using namespace std;
int main()
{
    long long i=0,j = 0,namiraneNaMaximalnoChislo[1024],L,n,lipsvashtiOvce[4],maximalnoChislo=0;
    cin>>n>>L;
    for(int i = 0; i != L; i++)
        cin>>lipsvashtiOvce[i];
   for(j = 1; j != n;j++){

        for(int i = 0; i != L; i++)
        {
            if(j == lipsvashtiOvce[i])
			{
                namiraneNaMaximalnoChislo[j] = j+1;
			}
                if(namiraneNaMaximalnoChislo[j] >maximalnoChislo)
                {
                    maximalnoChislo = namiraneNaMaximalnoChislo[j];
                }
                namiraneNaMaximalnoChislo[j] = j;

		}
    }
    cout<<maximalnoChislo<<endl;
    return 0;
}
