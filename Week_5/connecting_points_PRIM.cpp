//#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <climits>
#include <queue>

using std::pair;
using std::vector;
using std::make_pair;
using std::queue;
using std::priority_queue;
using std::greater;

typedef pair<double,int> pi;

double dis(int x1,int x2,int y1,int y2)
{
 return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}


double minimum_distance(vector<int> x, vector<int> y) 
{
  double result = 0;
  int n=x.size();
  vector<vector<int>> adj(n,vector<int> ());
vector<vector<double>> cost(n,vector<double> ());
for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
  if(i!=j)
  {adj[i].push_back(j);
  cost[i].push_back(dis(x[i],x[j],y[i],y[j]));}
 
// MAKING GRAPH AND THEIR CORRESPONDING WEIGHTS

vector <double> cost1(n,INT_MAX);
vector <int> inmst(n,0);

priority_queue<pi,vector<pi>,greater<pi>> p;
cost1[0]=0;
p.push(make_pair(cost1[0],0));

while(!p.empty())
{
 double w=p.top().first;
 int a=p.top().second;
 p.pop();
 if(inmst[a]==0)
 {result+=w;
 inmst[a]=1;}
 
 for(int i=0;i<adj[a].size();i++)
  if(inmst[adj[a][i]]==0&&cost1[adj[a][i]]>cost[a][i])
  {
    cost1[adj[a][i]]=cost[a][i];
    p.push(make_pair(cost[a][i],adj[a][i]));
   }
  
}
  return result;
} 


int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed<<std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
