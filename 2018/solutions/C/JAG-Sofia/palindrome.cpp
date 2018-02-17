#include <iostream>
using namespace std;
int main()
{
 string St;
 int i , j , i2 , A[1500] , sreda , zamqna = 0 , proverka = 2 ;
 cin >> St;
 for (i = 0; i < St.size() ; i++ ) A[i] = St[i] - '0' ;

 if ( St.size() % 2 == 0 )
 {
     sreda = A [ St.size() / 2 - 1 ] * 10 + A [ St.size() / 2 ] ;

  if ( sreda == 0 )
  {

    for ( j = St.size()/2 - 2; j >= 0; j-- )
    {
     if (  A [ j ] > A [ St.size() - 1 - j ] ) { proverka = 1; break; }
     if (  A [ j ] < A [ St.size() - 1 - j ] ) { proverka = 0; break; }
    }
     if ( proverka == 1 )
     { for ( j = 0; j < St.size()/2 - 1 ; j++ ) {A [ St.size() - 1 - j ] = A [ j ] ;}
       for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
       zamqna = 1;
     }
  }

  if ( sreda < 99 && zamqna == 0)
  {
      proverka = 2;
    for ( j = St.size()/2 - 2; j >= 0; j-- )
    {
     if (  A [ j ] > A [ St.size() - 1 - j ] ) { proverka = 1; break; }
     if (  A [ j ] < A [ St.size() - 1 - j ] ) { proverka = 0; break; }
    }
  if ( proverka == 1 )
     { for ( j = 0; j < St.size()/2 - 1; j++ ) {A [ St.size() - 1 - j ] = A [ j ] ;}
       if ( sreda % 11 == 0 ) sreda = sreda ;
       else sreda = (sreda / 11 + 1) * 11 ;
       A [ St.size() / 2 - 1] = sreda / 10 ;
       A [ St.size() / 2 ] = sreda % 10;
       for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
       zamqna = 1;
     }
   else {
   if ( sreda % 11 == 0 ) sreda += 11 ;
   else sreda = (sreda / 11 + 1) * 11 ;
   A [ St.size() / 2 - 1] = sreda / 10 ;
   A [ St.size() / 2 ] = sreda % 10;
   for ( j = 0; j < St.size()/2 ; j++ ) { A [ St.size() - 1 - j ] = A [ j ]; }
   for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
   zamqna = 1;
   }
  }

  if (sreda == 99 && zamqna == 0)
  {
      proverka = 2;
    for ( j = St.size()/2 - 2; j >= 0; j-- )
    {
     if (  A [ j ] > A [ St.size() - 1 - j ] ) { proverka = 1; break; }
     if (  A [ j ] < A [ St.size() - 1 - j ] ) { proverka = 0; break; }
    }
     if ( proverka == 1 )
     { for ( j = 0; j < St.size()/2 - 1; j++ ) {A [ St.size() - 1 - j ] = A [ j ] ;}
       for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
       zamqna = 1;
     }
     else {
    sreda = 0 ;
    A [ St.size() / 2 - 1] = 0 ;
    A [ St.size() / 2 ] = 0;
    A [ St.size() / 2 - 2] ++;
    for ( j = St.size() / 2 - 2 ; j >= 0; j -- )
    { if ( A [ j ] < 10 ) break;
      if ( A [ j ] == 10 && j != 0) { A [ j ] = 0; A [ j - 1 ] ++ ; }
      if ( A [ j ] == 10 && j == 0) { break; } }

    for ( j = 0; j < St.size()/2 ; j++ )
      {
          if ( j == 0)
          {
           if ( A [ j ] == 10 ) A [ St.size() - 1 ] = 1 ;
           else A [ St.size() - 1 ] = A [ j ] ;
          }
          if ( j != 0 )
          {
             A [ St.size() - 1 - j ] = A [ j ] ;
          }
      }

     for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}

    }
  }
 }

 if ( St.size() % 2 == 1)
 {
   sreda = A[St.size() / 2];

   if ( sreda == 0 )
   {
       int proverka = 2;
    for ( j = St.size()/2 - 1; j >= 0; j-- )
    {
     if (  A [ j ] > A [ St.size() - 1 - j ] ) { proverka = 1; break; }
     if (  A [ j ] < A [ St.size() - 1 - j ] ) { proverka = 0; break; }
    }
     if ( proverka == 1 )
     { for ( j = 0; j < St.size()/2 ; j++ ) {A [ St.size() - 1 - j ] = A [ j ] ;}
       for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
       zamqna = 1;
     }
   }


   if ( sreda < 9 && zamqna == 0)
   {
       proverka = 2;
    for ( j = St.size()/2 - 1; j >= 0; j-- )
    {
     if (  A [ j ] > A [ St.size() - 1 - j ] ) { proverka = 1; break; }
     if (  A [ j ] < A [ St.size() - 1 - j ] ) { proverka = 0; break; }
    }
     if ( proverka == 1 )
     { for ( j = 0; j < St.size()/2 ; j++ ) {A [ St.size() - 1 - j ] = A [ j ] ;}
       for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
       zamqna = 1;
     }
     else {
    sreda ++;
    A [ St.size()/2 ] = sreda;
   for ( j = 0; j < St.size()/2 ; j++ ) { A [ St.size() - 1 - j ] = A [ j ]; }
   for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
   zamqna = 1; }
   }
   if (sreda == 9 && zamqna == 0)
   {

         proverka = 2;
    for ( j = St.size()/2 - 1; j >= 0; j-- )
    {
     if (  A [ j ] > A [ St.size() - 1 - j ] ) { proverka = 1; break; }
     if (  A [ j ] < A [ St.size() - 1 - j ] ) { proverka = 0; break; }
    }
     if ( proverka == 1 )
     { for ( j = 0; j < St.size()/2 ; j++ ) {A [ St.size() - 1 - j ] = A [ j ] ;}
       for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;}
       zamqna = 1;
     }
     else{
    sreda = 0 ;
    A [ St.size() / 2 ] = 0;
    A [ St.size() / 2 - 1] ++;
    for ( j = St.size() / 2 - 1 ; j >= 0; j -- )
    { if ( A [ j ] < 10 ) break;
      if ( A [ j ] == 10 && j != 0) { A [ j ] = 0; A [ j - 1 ] ++ ; }
      if ( A [ j ] == 10 && j == 0) { break; } }

    for ( j = 0; j < St.size()/2 ; j++ )
      {
          if ( j == 0)
          {
           if ( A [ j ] == 10 ) A [ St.size() - 1 ] = 1 ;
           else A [ St.size() - 1 ] = A [ j ] ;
          }
          if ( j != 0 )
          {
             A [ St.size() - 1 - j ] = A [ j ] ;
          }
      }

     for ( j = 0 ; j < St.size() ; j++ ) { cout << A [ j ] ;} }


   }
 }
 return 0;
}
