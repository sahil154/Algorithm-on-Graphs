#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;
using std::pair;
using std::make_pair;
using std::greater;

typedef pair<double,pair<int,int>> ppi;

double dis(int x1,int x2,int y1,int y2)
{
 return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0;
  int n=x.size();
  //vector<vector<int>> adj(n,vector<int> ());
//vector<vector<double>> cost(n,vector<double> ());
vector <ppi> edges;
for(int i=0;i<n;i++)
 for(int j=0;j<n;j++)
  if(i!=j)
  {//adj[i].push_back(j);
  //cost[i].push_back(dis(x[i],x[j],y[i],y[j]));
  if(i<=j)
  edges.push_back(make_pair(dis(x[i],x[j],y[i],y[j]),make_pair(i,j)));
   }

std::sort(edges.begin(),edges.end(),greater<ppi>()); 
//for(int i=0;i<edges.size();i++)
 //std::cout<<edges[i].first<<" "<<edges[i].second.first<<" "<<edges[i].second.second<<"\n";
//std::sort(edges.begin(),edges.end());
vector<int> inmst(n,0);
result+=edges[edges.size()-1].first;
inmst[edges[edges.size()-1].second.first]=1;
inmst[edges[edges.size()-1].second.second]=1;
std::cout<<result<<"\n";
while(edges.size()!=0)
{
 if((inmst[edges[edges.size()-1].second.first]==0&&inmst[edges[edges.size()-1].second.second]==0) ||             (inmst[edges[edges.size()-1].second.first]==0&&inmst[edges[edges.size()-1].second.second]==1) ||   (inmst[edges[edges.size()-1].second.first]==1&&inmst[edges[edges.size()-1].second.second]==0) )
{
 result+=edges[edges.size()-1].first;
 inmst[edges[edges.size()-1].second.first]=1;
 inmst[edges[edges.size()-1].second.second]=1;
}
std::cout<<result<<"\n";
edges.pop_back();
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
