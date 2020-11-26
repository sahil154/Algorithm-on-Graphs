#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::pair;

void dfs(vector<vector<int> > &adj, vector<int> &used, vector<int> &order, int x,int &count)
{
  //write your code here
  if(used[x]) 
   return;
  used[x]=1;
  for(int i=0;i<adj[x].size();i++)
  if(!used[adj[x][i]])
    {dfs(adj,used,order,adj[x][i],count);
     order[adj[x][i]]=count++;}
  
}     

vector<int> toposort(vector<vector<int> > adj) {
  vector<int> used(adj.size(), 0);
  vector<int> order(adj.size(), 0);
  int count=0;
  for(int i=0;i<adj.size();i++)
  if(!used[i])
  {dfs(adj,used,order,i,count);
   order[i]=count++;}
  

  //write your code here
  return order;
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
  vector<int> order = toposort(adj);
vector<int> order1(adj.size());
 for(int i=0;i<order.size();i++)
  order1[order[i]]=i;
  for (int i = order.size()-1; i>=0; i--) {
    std::cout << order1[i] + 1 << " ";
  }
}
