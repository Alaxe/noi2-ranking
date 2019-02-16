#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int nmax=50000;     // Максимален брой върхове
const int mmax=100000;     // Максимален брой ребра

struct edge{
   int first;
   int second;
   bool incl=false;
};

vector<edge> jedges;
vector<int> path;

int n,m;
int k;

bool compare(edge a, edge b){
  return((a.first < b.first) || ((a.first==b.first) && (a.second < b.second)));
}

int finded(edge x){
  int ans;
  int L, R, M;

  ans=0;

  L=0; R=jedges.size()-1;
  while (L<=R){
    M=(L+R)/2;
    if (compare(x, jedges[M]))
        R=M-1;
    else
        L=M+1;
  }

  if ((jedges[R].first != x.first) || (jedges[R].second != x.second))
      ans = 1;
  else
      if (jedges[R].incl)
          ans = 2;
      else
          jedges[R].incl = true;
  return ans;
}

int main(int argc, char *argv[]) {
   int jcount, ccount;
   int i,j,p;
   edge ed;
   int prstop;
   int nextstop;
   int fe;
   FILE *in = fopen(argv[1], "r");
    if (!in) {
        fprintf(stderr,"In-file %s not found\n",argv[1]);
        printf("0\n");
        return 0;
    }

    FILE *sol = fopen(argv[2],"r");
    if (!sol) {
        fprintf(stderr,"Sol-file %s not found\n",argv[2]);
        printf("0\n");
        return 0;
    }

    FILE *out = fopen(argv[3], "r");
    if (!out) {
        fprintf(stderr,"Out-file %s not found\n",argv[3]);
        printf("0\n");
        return 0;
    }

    // Проверка на правилността на минималния брой трамвайни маршрути
    fscanf(sol,"%d", &jcount);
    fscanf(out,"%d", &ccount);
    if (ccount != jcount){
        fprintf(stderr,"Wrong answer: incorrect minimum number of tram routes\n");
        printf("0\n");
        return 0;
    }

    // Ако минималният брой трамвайни маршрути е верен, проверява дали самите маршрути са верни

    // Първо прочита от входа самите линии от трамвайната мрежа

    fscanf(in,"%d %d", &n, &m);

    // Прочита ребрата на входния граф и ги сортира във възходящ ред
    for (i=1;i<=m;i++) {
        fscanf(in,"%d %d", &ed.first, &ed.second);
        if (ed.first>ed.second)
            swap(ed.first, ed.second);
        jedges.push_back(ed);
    }

    sort(jedges.begin(), jedges.end(), compare);

    // Чете последователно всеки трамваен маршрут, даден от състезателя.
    // За всяка линия от машрута, изведена от състезателя, проверява
    // дали действително съществува и дали вече не е включена в някакъв маршрут

    for (p=1; p<=ccount; p++){
       fscanf(out,"%d", &k);  // Прочита броя на спирките в маршрута
       /*if (k<2 || k>m+1) {
          fprintf(stderr,"Wrong answer: invalid tram stops number (%d) in tram route\n", k);
          printf("0\n");
          return 0;
       }*/
       // Прочита номера на първата спирка от маршрура
       fscanf(out,"%d", &prstop);
       if (prstop<1 || prstop>n) {
          fprintf(stderr,"Wrong answer: invalid tram stop number (%d) in tram route\n", prstop);
          printf("0\n");
          return 0;
       }
       for (j=2;j<=k;j++){
          fscanf(out,"%d", &nextstop);
          if (nextstop<1 || nextstop>n) {
             fprintf(stderr,"Wrong answer: invalid tram stop number (%d) in tram route\n", nextstop);
             printf("0\n");
             return 0;
          }
          ed.first = prstop;
          ed.second = nextstop;
          if (ed.first>ed.second)
             swap(ed.first, ed.second);
          fe = finded(ed);
          if (fe == 1){
             fprintf(stderr,"Wrong answer: there is no tram line (%d %d)\n", prstop,nextstop);
             printf("0\n");
             return 0;
          }

          if (fe == 2){
             fprintf(stderr,"Wrong answer: tram line (%d %d) is on more than 1 tram routes\n", prstop,nextstop);
             printf("0\n");
             return 0;
          }

          prstop = nextstop;

       }
    }
    // Проверява дали всички линии са включени в маршрути
    for (i=0;i<jedges.size();i++)
       if (!jedges[i].incl){
          fprintf(stderr,"Wrong answer: tram line (%d %d) is not included in a route\n", jedges[i].first, jedges[i].second);
          printf("0\n");
          return 0;
       }
    fprintf(stderr,"Correct\n");
    printf("1\n");
    return 0;
}
