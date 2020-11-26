#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cmath>
#include <cstring>

using std::vector;
using std::pair;
using std::make_pair;



typedef pair<double,pair<int,int>> ppi;

double dis(int x1,int x2,int y1,int y2)
{
 return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int find(vector<vector<int> > &adj,bool visited[],int x,int y)
{
 if(x==y) 
  return 1;
 visited[x]=true;
  for(int i=0;i<adj[x].size();i++)
 {
   if(!visited[adj[x][i]])
   if(find(adj,visited,adj[x][i],y))
   return 1;
 } 
return 0;
}


double clustering(vector<int> x, vector<int> y, int k) {

  double result = 0.;
   int n=x.size();

int m=(n*(n-1))/2;  
//vector <ppi> edges(m);    //DON'T MAKE VECTOR,ERROR IS COMING
ppi edges[m];    // MAKE ARRAY FOR STORING EDGES 
int l=0;
for(int i=0;i<n;i++)
 for(int j=i+1;j<n;j++)
  if(i!=j&&i<=j)
  { edges[l]=make_pair(dis(x[i],x[j],y[i],y[j]),make_pair(i,j));
   l++;
  }
 
//bool mark[n]={false};
 
std::sort(edges,edges+m);  //SORT IN INCREASING ORDER ,ERROR IS COMING IN DECREASING ORDER
/*for(int i=0;i<m;i++)
 std::cout<<edges[i].first<<" - ("<<edges[i].second.first<<","<<edges[i].second.second<<")\n";
*/

vector<vector<int> > adj(n,vector<int>());
l=0;
int conn=1;
result+=edges[k].first;
adj[edges[l].second.first].push_back(edges[l].second.second);
adj[edges[l].second.second].push_back(edges[l].second.first);

bool visited[n];
memset(visited,false,sizeof(visited));
if(n==2)
  return edges[0].first;
while(l<m-1)
{ 
 l++; 
 int x=edges[l].second.first;
 int y=edges[l].second.second;
 memset(visited,false,sizeof(visited));
 if(!find(adj,visited,x,y))
   conn++;
  adj[edges[l].second.first].push_back(edges[l].second.second);
  adj[edges[l].second.second].push_back(edges[l].second.first);
  if(conn>n-k)
   return edges[l].first;
}

 
  return -1.;
} 

int main() {
  size_t n;
  int k;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cin >> k;
  std::cout <<std::fixed<< std::setprecision(10) << clustering(x, y, k) << std::endl;
}
