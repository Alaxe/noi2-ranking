#include<iostream>
#include<cstring>
#include<iomanip>

using namespace std;

int br_izpozvani_bukwi[26];
char pass[5000+1];

int find_min( char let )
{
    int miny;
    int ind = 0;

    miny = br_izpozvani_bukwi[0];

    for( int i = 1; i < 26; i++ )
    {
        if ( (br_izpozvani_bukwi[i] < miny) &&
             (((char)(i + 'a') != let))
           )
        {
            miny = br_izpozvani_bukwi[i];
            ind = i;
        }

        if( miny == 0 )
        {
            break;
        }
    }

    return ind;
}

int main()
{
    char false_let, new_let;
    int br_flase_let = 0, br = 0;
    int br_poredni = 1, len, k = 0;
    bool ima_false = false, breakk;

    cin >> pass;

    len = strlen(pass);
    new_let = (char)(find_min( false_let ) + 'a');

    for ( int i = 1; i <len; i++ )
    {
        if( pass[i] == pass[i - 1] )
        {
            br_poredni++;
        }
        else
        {
            br_poredni = 1;
        }

        if( br_poredni > 2 )
        {
            pass[i] = new_let;
        }
    }

    for( int i = 0; i < 26; i++ )
    {
        br_izpozvani_bukwi[i] = 0;
    }

    for( int i = 0; i < len; i++ )
    {
         br_izpozvani_bukwi[(int)(pass[i] - 'a')]++;
    }

    for( int i = 0; i < 26; i++ )
    {
        if( br_izpozvani_bukwi[i] > (len/2) )
        {
            ima_false = true;
            break;
        }
    }

    if( ima_false == false )
    {
        cout << pass << endl;
    }
    else
    {
        //cout << " ffeegyhk" <<endl;
        for( int i = 0; i < 26; i++ )
        {
            if( br_izpozvani_bukwi[i] > len/2 )
            {
                br_flase_let = br_izpozvani_bukwi[i] - len/2;
                false_let = (char)(i + 'a');
                break;
            }
        }

        for( int i = 1; i <= br_flase_let; i++ )
        {
            for( int i = 0; i < len; i++ )
            {
                if(pass[i] == false_let)
                {
                    if( br_izpozvani_bukwi[k] < (len/2)
                       )
                    {
                            if( ((char)(k+'a')) != false_let)
                            {
                                pass[i] = (char)(k + 'a');
                                k++;
                                break;
                            }
                            else
                            {
                                k++;
                                pass[i] = (char)(k + 'a');
                                break;
                            }

                    }
                }
            }
        }

        cout << pass << endl;
    }

    return 0;
}

