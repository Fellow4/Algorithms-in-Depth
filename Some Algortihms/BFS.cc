#include <bits/stdc++.h>
using namespace std;

void addEdge(list <int> adj[],int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
  return ;
}

void print_list(list <int> adj){
  list <int> :: iterator it;
  for(it = adj.begin();it != adj.end();it++)
     cout<<*it<<" ";
}

void printGraph(list <int> adj[],int v){
  for(int i=0;i<v;i++){
    for(auto it = adj[i].begin();it != adj[i].end();++it)
       cout<<*it<<" ";
    cout<<endl;
  }
}

void printqueue(queue <int> q){
   queue <int> temp = q;
   while(!temp.empty()){
     cout<<temp.front()<<" ";
     temp.pop();
   }
}

void Add_list_to_queue(list <int> l,queue <int> &q,int *visited){
  for(auto it = l.begin();it != l.end(); it++)
   if(!visited[*it]){
     q.push(*it);
     visited[*it] = 1;
   }
}

void dfs(list <int> adj[],int *visited,int source){
  queue <int> q;
  visited[source] = 1;
  q.push(source);
  while(!q.empty()){
    int front = q.front();
    cout<<"Current element is:"<<front<<endl;
    q.pop();
    //Add the neighbours of the popped node
    Add_list_to_queue(adj[front],q,visited);
  }
}


int main(){
  list <int> adj[4];
  int visited[4];
  for(int i = 0;i < 4;++i) visited[i] = 0;
  addEdge(adj,0, 1);
  addEdge(adj,0, 2);
  addEdge(adj,1, 2);
  addEdge(adj,2, 0);
  addEdge(adj,2, 3);
  addEdge(adj,3, 3);
  dfs(adj,visited,0);
  return 0;
}
