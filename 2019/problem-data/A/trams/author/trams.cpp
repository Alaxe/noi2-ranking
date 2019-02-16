#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

const int nmax=50000;     // Максимален брой върхове
const int mmax=150000;    // Максимален брой ребра

struct vertex {
   int vn;                // Номер на връх
   int next_v;            // Индекс на следващ връх от списъка
   int prev_v;            // Индекс на предходен връх от списъка
   int uk;                // Указател към мястото в списъка на инцидентния връх
   bool dummy_ed;          // Индикация за фиктивно ребро към този връх (false - не; true - да)
};

vector<vertex> graph[nmax+1];
int neighbors_count[nmax+1];
int head_index[nmax+1];
int vdegree[nmax+1];
int n,m,inpm;

typedef pair<int,int> edge;
typedef pair<int,bool> ve;

vector<edge> edges;

vector<int> path;
vector<ve> eucycle;

stack<ve> swork;
stack<ve> scycle;

int lines_number;
int odddeg = 0;
void input() {
   int u,v;
   vertex wa;
   edge ed;
   scanf("%d %d", &n, &m);
   inpm = m;
   for (int i=1;i<=n;i++){
      neighbors_count[i]=0;
      head_index[i] = 0;
      vdegree[i]=0;
   }

   for (int i=1;i<=m;i++){
     scanf("%d %d", &u, &v);
     ed.first = u;
     ed.second = v;
     edges.push_back(ed);
     vdegree[u]++;
     vdegree[v]++;
   }

   int prevodd = 0;
   for (int i=1;i<=n;i++)
      if (vdegree[i]%2 == 1){
         odddeg++;
         if (prevodd == 0)
            prevodd = i;
         else{
            ed.first = prevodd;
            ed.second = i;
            if (ed.first > ed.second)
                swap(ed.first, ed.second);
            edges.push_back(ed);
            m++;
            prevodd = 0;
         }
      }
   lines_number = odddeg/2;
   if (lines_number == 0)
      lines_number = 1;

   for (int i=0;i<m;i++){

      u=edges[i].first;
      v=edges[i].second;

      neighbors_count[u]++;
      neighbors_count[v]++;
      wa.vn = v;
      wa.next_v = 0;
      wa.prev_v = 0;
      if (i<inpm)
         wa.dummy_ed = false;
      else
         wa.dummy_ed = true;
      wa.uk = neighbors_count[v]-1;
      graph[u].push_back(wa);
      if (neighbors_count[u] > 1){
         graph[u][neighbors_count[u]-2].next_v = neighbors_count[u]-1;
         graph[u][neighbors_count[u]-1].prev_v = neighbors_count[u]-2;
      }
      wa.vn=u;
      wa.uk = neighbors_count[u]-1;
      graph[v].push_back(wa);
      if (neighbors_count[v] > 1){
         graph[v][neighbors_count[v]-2].next_v = neighbors_count[v]-1;
         graph[v][neighbors_count[v]-1].prev_v = neighbors_count[v]-2;
      }
  }
}

void buildEulerCycle(){
   int u, v;
   int uk;
   ve vert;
   ve uvert;

   vert.first = 1;
   vert.second = false;
   swork.push(vert);
   while (!swork.empty()) {
      uvert = swork.top();
      u = uvert.first;
      if (neighbors_count[u] > 0) {
         v=graph[u][head_index[u]].vn;
         vert.first = v;
         vert.second = graph[u][head_index[u]].dummy_ed;
         swork.push(vert);
         // Взема се индекса на u в списъка със съседи на v
         uk = graph[u][head_index[u]].uk;
         // Премахва се v от списъка със съседи на u
         head_index[u] = graph[u][head_index[u]].next_v;
         neighbors_count[u]--;

         // Премахва се u от списъка със съседи на v

         if (uk==head_index[v])
            head_index[v]=graph[v][head_index[v]].next_v;
         else{
            graph[v][graph[v][uk].prev_v].next_v = graph[v][uk].next_v;
            if (graph[v][uk].next_v > 0)
                graph[v][graph[v][uk].next_v].prev_v =graph[v][uk].prev_v;
         }
         neighbors_count[v]--;

      }
      else {
         scycle.push(uvert);
         swork.pop();

      }
   }
}

int main() {
  ve w;
  input();

  buildEulerCycle();

  printf("%d\n", lines_number);

  while (!scycle.empty()){
     w=scycle.top();
     scycle.pop();
     eucycle.push_back(w);
  }

 /* for (int i=0; i<eucycle.size();i++){
     printf("%d ",eucycle[i].first);
     if (eucycle[i].second)
        printf("*");
     printf("\n");
  }
*/

  int edcount = 0;
  int ibeg,i,k;
  int eusize;

  eusize = eucycle.size()-1;
  eucycle[0].second = eucycle[eusize].second;

  // Търси ребро, което е първо в някакъв път.
  // Ако графът е Ойлеров цикъл, то направо го извежда;
  // Ако има фиктивни ребра, то търсим такова, че началото му да е в отбелязан връх, а
  // краят в неотбелязан. Отбелязаният път ще бъде началото на първия път

  if (odddeg == 0) {
      printf("%d", eucycle.size());
      for (int p=0; p<eucycle.size();p++)
         printf(" %d", eucycle[p].first);
      printf("\n");
      return 0;
  }
  else {
      i=0;
      k=1;
      while (!((eucycle[i].second) && (!eucycle[k].second))){
          i++;
          if (i>eusize-1) i=0;
          k=i+1;
          if (k>eusize-1) k=0;
      }

      ibeg = k;
  }

  i=ibeg;

  while (edcount <= inpm){
    k=i-1;
    if (k<0) k=eusize-1;
    if (!eucycle[i].second){
       edcount++;
       if (eucycle[k].second){
          path.push_back(eucycle[k].first);
          path.push_back(eucycle[i].first);
       }
       else
          path.push_back(eucycle[i].first);
    }
    else{
        if (path.size()>0){
            printf("%d", path.size());
            for (int p=0; p<path.size();p++)
                printf(" %d", path[p]);
            printf("\n");
         path.clear();
        }
    }
    i++;
    if (i>eusize-1) i=0;
  }

}

/*
6 10
6 1
1 2
2 3
3 4
6 5
5 4
1 5
4 1
5 2
2 4

*/
