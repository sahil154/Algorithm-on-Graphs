#include <iostream>
#include <vector>
#include <cstring>

using std::vector;
using std::pair;

int explore(vector<vector<int> > &adj,bool visited[], int x, int y)
{
   if(x==y)
    return 1;
  visited[x]=true;
  for(int i=0;i<adj[x].size();i++)
   {
    if(!visited[adj[x][i]])
     if(explore(adj,visited,adj[x][i],y))
             return 1;
   }
return 0;
}  
 
   
int reach(vector<vector<int> > &adj, int x, int y)
{
  //write your code here
   if(x==y)
    return 1;
 bool visited[adj.size()];
 memset(visited,false,sizeof(visited));
 return explore(adj,visited,x,y);

}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  std::cin >> x >> y;

  std::cout << reach(adj, x - 1, y - 1);
}

/*vector< vector<int> >::iterator row;
vector<int>::iterator col;
for (row = vvi.begin(); row != vvi.end(); row++) {
    for (col = row->begin(); col != row->end(); col++) {
        // do stuff ...
    }
}*/
