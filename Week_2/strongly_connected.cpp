#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using std::vector;
using std::pair;
using std::stack;


void explore(vector<vector<int> > &dup,bool visited[],int x,stack<int> &st)
{
 if(visited[x])
  return;
 visited[x]=true;
 for(int i=0;i<dup[x].size();i++)
  if(!visited[dup[x][i]])
   explore(dup,visited,dup[x][i],st);
    
  st.push(x);
}



int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  stack<int> st;
    int sz=adj.size();
 bool visited[sz];
 
 memset(visited,false,sizeof(visited));
 
 for(int i=0;i<dup.size();i++)
  if(!visited[i])
  explore(adj,visited,i,st);

 vector<vector<int> > dup(sz,vector<int>());
for(int i=0;i<adj.size();i++)
 for(int j=0;j<adj[i].size();j++)
  dup[adj[i][j]].push_back(i);
 
memset(visited,false,sizeof(visited));
while(!st.empty()) 
{int x=st.top();
 st.pop();
 if(!visited[x])
  {stack<int> st1;
explore(dup,visited,x,st1);
   result++;}
}
  

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
