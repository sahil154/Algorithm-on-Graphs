#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;

//IMPORTANT : CHECKING CONDITION (DISTANCE[K]!=L) IN IF CONDITION IS NECESSARY (BECAUSE VERTEX WITH DISTANCE INT_MAX IS NOT REACHABLE FROM SOURCE VERTEX S), OTHERWISE IT WILL PUSH UNREACHABLE VERTEX TO QUEUE.

void explore(vector<vector<int> > &adj,vector<int> &visited,vector<int> &reachable, int x)
{
 if(visited[x])
   return;
  visited[x]=true;
  for(int i=0;i<adj[x].size();i++)
   {
     reachable[adj[x][i]]=1;
    if(!visited[adj[x][i]])
      explore(adj,visited,reachable,adj[x][i]);          
   }
return;
}  


void shortest_paths(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, vector<long long> &distance, vector<int> &reachable, vector<int> &shortest) 
{
vector <int> visited(adj.size(),0);
reachable[s]=1;
explore(adj,visited,reachable,s);  //FINDING ALL VERTICES REACHABLE FROM SOURCE VERTEX S

int l=INT_MAX;


  distance[s]=0;
queue <int> q;
int n=adj.size();
for(int i=0;i<n-1;i++)
{
   for(int k=0;k<n;k++)
     {for(int j=0;j<adj[k].size();j++)
      {
        int a=adj[k][j];
        if(distance[k]!=l&&distance[a]>distance[k]+cost[k][j])
         distance[a]=distance[k]+cost[k][j];
       }
     }
} //RUNNING BELLMAN FORD ALGORITHM FOR |V|-1 TIMES


vector<int> visited1(n,0);
   for(int k=0;k<n;k++)
     {for(int j=0;j<adj[k].size();j++)
      {
        int a=adj[k][j];
        if(distance[k]!=l&&distance[a]>distance[k]+cost[k][j])
         { q.push(a);
           distance[a]=distance[k]+cost[k][j];
           }
       }
     }//STORING VERTICES RELAXING ON Vth ITERATION OF BELLMAN FORD


while(!q.empty())
{
 int s=q.front();
 q.pop();
visited1[s]=1;
shortest[s]=0;
 for(int i=0;i<adj[s].size();i++)
  if(!visited1[adj[s][i]])
    {q.push(adj[s][i]);
     visited1[adj[s][i]]=1;
     shortest[adj[s][i]]=0;}
}//MARKING VERTICES WHICH ARE PRESENT IN NEGATIVE CYCLE 

distance[s]=0;

return;

  
}

int main() {
  int n, m, s;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cin >> s;
  s--;
  int l=INT_MAX;
  vector<long long> distance(n,l);
  vector<int> reachable(n, 0);
  vector<int> shortest(n, 1);
  shortest_paths(adj, cost, s, distance, reachable, shortest);
  for (int i = 0; i < n; i++) {
    if (!reachable[i]) {
      std::cout << "*\n";
    } else if (!shortest[i]) {
      std::cout << "-\n";
    } else {
      std::cout << distance[i] << "\n";
    }
  }
}
