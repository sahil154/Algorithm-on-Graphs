#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using std::vector;
using std::queue;

int bipartite(vector<vector<int> > &adj) 
{
  //write your code here
queue<int> q;
int n=adj.size();
bool visited[n];
int color[n];
memset(visited,false,sizeof(visited));
memset(color,-1,sizeof(color));
int s=0;
visited[s]=true;
color[s]=0;
q.push(s);
while(!q.empty())
{
int u=q.front();
q.pop();
for(int i=0;i<adj[u].size();i++)
{
  if(visited[adj[u][i]]==false)
   {q.push(adj[u][i]);
   visited[adj[u][i]]=true;}
  int curr=color[adj[u][i]];
 if(curr==-1)
  color[adj[u][i]]=!color[u];
 else if(curr==color[u])
  return 0;
}
}
return 1;
 
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  std::cout << bipartite(adj);
}
