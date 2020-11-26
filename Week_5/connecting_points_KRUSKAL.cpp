#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstring>

using std::vector;
using std::pair;
using std::make_pair;
using std::greater;

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


double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
   int n=x.size();

int m=(n*(n-1))/2;  
//vector <ppi> edges(m);    //DON'T MAKE VECTOR,ERROR IS COMING
ppi edges[m];    // MAKE ARRAY FOR STORING EDGES 
int k=0;
for(int i=0;i<n;i++)
 for(int j=i+1;j<n;j++)
  if(i!=j&&i<=j)
  { edges[k]=make_pair(dis(x[i],x[j],y[i],y[j]),make_pair(i,j));
   k++;
  }
 
  
std::sort(edges,edges+m);  //SORT IN INCREASING ORDER ,ERROR IS COMING IN DECREASING ORDER

vector<vector<int> > adj(n,vector<int>());
k=0;
result+=edges[k].first;
adj[edges[k].second.first].push_back(edges[k].second.second);
adj[edges[k].second.second].push_back(edges[k].second.first);

bool visited[n];
memset(visited,false,sizeof(visited));

while(k<m-1)
{  
 k++;
 int x=edges[k].second.first;
 int y=edges[k].second.second;

 memset(visited,false,sizeof(visited));
 if(!find(adj,visited,x,y))
 {
  adj[edges[k].second.first].push_back(edges[k].second.second);
  adj[edges[k].second.second].push_back(edges[k].second.first);
  result+=edges[k].first;
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
  std::cout <<std::fixed<< std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
