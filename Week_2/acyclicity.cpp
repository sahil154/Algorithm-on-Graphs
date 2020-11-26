#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::pair;

int explore(vector <vector<int>> &adj, bool visited1[],bool visited2[],int x,int y)
{
  if(visited1[x])
     return 0;
  visited1[x]=true;
  visited2[x]=true;
  for(int i=0;i<adj[x].size();i++)
  {
     if(adj[x][i]==y&&visited2[adj[x][i]]&&visited2[y])
         return 1;
     if(!visited1[adj[x][i]])
     if(explore(adj,visited1,visited2,adj[x][i],y))
      return 1;
  }
return 0;
}

int acyclic(vector<vector<int> > &adj) {
   bool visited1[adj.size()];
   bool visited2[adj.size()];
    memset(visited1,false,sizeof(visited1));
 memset(visited2,false,sizeof(visited2));
   int y=-1;
 for(int i=0;i<adj.size();i++)
     if(!visited1[i])
      { y=i;
       memset(visited2,false,sizeof(visited2));
      if(explore(adj,visited1,visited2,i,y))
           return 1;}

  return 0;
}


int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
