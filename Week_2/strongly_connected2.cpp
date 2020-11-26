#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <utility>

using std::vector;
using std::pair;

bool sortinrev(const pair<int,int> &a,const pair<int,int> &b)
{
 return a.first<b.first;
}

void explore(vector<vector<int> > &dup,bool visited[],int x,int &count,int post[])
{
 if(visited[x])
  return;
 visited[x]=true;
 for(int i=0;i<dup[x].size();i++)
  if(!visited[dup[x][i]])
   {explore(dup,visited,dup[x][i],count,post);
    post[dup[x][i]]=count++;}
}

int number_of_strongly_connected_components(vector<vector<int> > &adj) {
  int result = 0;
    int sz=adj.size();
vector<vector<int>> dup(sz,vector<int>());
for(int i=0;i<adj.size();i++)
 for(int j=0;j<adj[i].size();j++)
  dup[adj[i][j]].push_back(i);
  
  
  /*for(int i=0;i<dup.size();i++)
  for(int j=0;j<dup[i].size();j++) 
       if(j<dup[i].size())
   std:: cout<<i<<"-"<<dup[i][j]<<" ";*/

 bool visited[sz];
 int post[sz];
 int count=0;
 memset(visited,false,sizeof(visited));
 memset(post,-1,sizeof(post));
 for(int i=0;i<adj.size();i++)
  if(!visited[i])
  {explore(dup,visited,i,count,post);
  post[i]=count++;}

vector<pair<int,int>> v;
pair<int,int> p;
for(int i=0;i<adj.size();i++)
 {p.first=post[i];
 p.second=i;
 v.push_back(p);}

sort(v.begin(),v.end());


 /* for(int j=0;j<v.size();j++) 
   std:: cout<<v[j].second<<"-"<<v[j].first<<" ";

for(int i=0;i<adj.size();i++)
  std::cout<<post[i]<<" ";*/
 
memset(visited,false,sizeof(visited));
for(int i=v.size()-1;i>=0;i--)
 {if(!visited[v[i].second])
  {explore(adj,visited,v[i].second,count,post);
   result++;}}
  

  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
