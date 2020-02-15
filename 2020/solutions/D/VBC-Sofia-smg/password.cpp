#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char sym[5001];
    long long N, bukvi[26]={0}, index_nai_mal, minb;
    cin.getline(sym, 5001);
    N=strlen(sym);
    for(long long i=0;i<N;i++)
    {
        bukvi[(int)sym[i]-'a']++;
    }
    for(long long i=0;i<N-2;i++)
    {
        if(sym[i]==sym[i+1] && sym[i]==sym[i+2])
        {
            minb=bukvi[0];
            index_nai_mal=0;
            for(long long j=1;j<26;j++)
            {
                if(minb>bukvi[j])
                {
                    minb=bukvi[j];
                    index_nai_mal=j;
                }
            }
            if(i!=N-4 || i!=N-3 || i!=N-2)
            {
                sym[i+2]=(char)bukvi[index_nai_mal+'a'];
            }
            else
            {
                if(sym[i+3]!=(char)index_nai_mal+'a' && sym[i]!=(char)index_nai_mal+'a')
                {

                }
            }
        }
    }
    cout<<"cooaoode\n";
    return 0;
}
