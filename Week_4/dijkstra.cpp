#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
 
using std::vector;
using std::queue;
using std::pair;
using std::make_pair;
using std::priority_queue;
using std::greater;
typedef pair <long long, int> pi;

long long distance(vector <vector<int> > &adj, vector <vector<int> > &cost, int s, int t) 
{
  int n=adj.size();
int l=INT_MAX;
long long dist[n];
for(int i=0;i<n;i++)
dist[i]=2147483647;

//MEMSET IS PUTTING INT_MAX AS -1 IN ARRAY

dist[s]=0;

priority_queue <pi, vector<pi>, greater<pi> > min; 
min.push(make_pair(dist[s],s));
while(!min.empty())
{
 pair <int,int> temp=min.top();
 min.pop();
 int s=temp.second;
 for(int i=0;i<adj[s].size();i++)
{
 int v=adj[s][i];
if(dist[v]>dist[s]+cost[s][i])
  {dist[v]=dist[s]+cost[s][i];
min.push(make_pair(dist[v],v));}
}
}
if(dist[t]==l)
return -1;
return dist[t];
  
}

int main()
 {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++)
 {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;

  std::cin >> s >> t;

  std::cout << distance(adj, cost, s-1, t-1);
return 0;

}
