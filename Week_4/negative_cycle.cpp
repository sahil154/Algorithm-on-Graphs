#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using std::vector;



int negative_cycle(vector<vector<int> > &adj, vector<vector<int> > &cost) {
 int l=INT_MAX;
  int n=adj.size();
vector <long> dis(n,l);
dis[0]=0;
for(int i=0;i<n-1;i++)
{
   for(int k=0;k<n;k++)
     {for(int j=0;j<adj[k].size();j++)
      {
        int a=adj[k][j];
        if(dis[a]>dis[k]+cost[k][j])
         dis[a]=dis[k]+cost[k][j];
       }
     }
}

for(int k=0;k<n;k++)
     {for(int j=0;j<adj[k].size();j++)
      {
        int a=adj[k][j];
        if(dis[a]>dis[k]+cost[k][j])
         return 1;
       }
     }
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  std::cout << negative_cycle(adj, cost);
}
