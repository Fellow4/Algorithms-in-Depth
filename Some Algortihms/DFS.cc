#include <bits/stdc++.h>
using namespace std;

void addEdge(list <int> adj[],int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
  return ;
}

void DFS_Iterative(list <int> adj[],int *visited,int n,int source){
  stack <int> s;
  s.push(source);
  while(!s.empty()){
    int v = s.top();
    s.pop();
    if(!visited[v]){
      cout<<v<<endl;
      visited[v] = 1;
    }
    for(auto it = adj[v].begin();it != adj[v].end();it++)
      if(!visited[*it])
        s.push(*it);
}
}

void printGraph(list <int> adj[],int v){
  for(int i=0;i<v;i++){
    for(auto it = adj[i].begin();it != adj[i].end();++it)
       cout<<*it<<" ";
    cout<<endl;
  }
}
//Assume 1 is the source node initially
void DFS_Recursive(list <int> adj[],int source,int *visited){
  if(source == 1) visited[source] = 1;
  cout<<source<<endl;
  for(auto it = adj[source].begin(); it != adj[source].end(); it++){
    if(!visited[*it]){
      visited[*it] = 1;
      DFS_Recursive(adj,*it,visited);
    }
}
}

int main (){
  list <int> adj[6];
  int visited[6];
  for(int i = 0;i < 6 ;i++) visited[i] = 0;
  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,1,3);
  addEdge(adj,1,4);
  addEdge(adj,4,5);
  DFS_Iterative(adj,visited,5,0);
  cout<<"Demarcator"<<endl;
  for(int i = 0;i < 6 ;i++) visited[i] = 0;
  DFS_Recursive(adj,1,visited);
  return 0;
}
