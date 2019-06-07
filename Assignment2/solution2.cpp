#include <bits/stdc++.h>
using namespace std;

void addEdge(list <int> adj[],int u,int v){
  adj[u].push_back(v);
}

void Add_list_to_queue(list <int> l,queue <int> &q,int *visited){
  for(auto it = l.begin();it != l.end(); it++)
   if(!visited[*it]){
     q.push(*it);
     visited[*it] = 1;
   }
}

void BFS(list <int> adj[],int *visited,int source,vector <int> &path){
  queue <int> q;
  visited[source] = 1;
  q.push(source);
  while(!q.empty()){
    int front = q.front();
    path.push_back(front);
    q.pop();
    //Add the neighbours of the popped node
    Add_list_to_queue(adj[front],q,visited);
  }
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		int m,n,k;
		int MAX = 1e5;
  int flag = 1,source;
  cin >> m >> n >> k;
  char arr[m][n];
  int maze[m][n];
  for(int i = 0; i < m; i++)
     for(int j = 0; j < n; j++){
       cin >> arr[i][j];
       if(arr[i][j] == '.')
         maze[i][j] = n*i + j;
      else maze[i][j] = 0;
     }
   for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
        if(arr[i][j] == '.'){
          source = maze[i][j];
          flag = 0;
          break;
        }
      }
      if(flag == 0) break;
  }
     list <int> adj[MAX];
     int visited[MAX];;
     for(int i = 0; i < MAX; i++) visited[i] = 0;
     //Iterate through the entire maze to find the neighbours of a certain index
     for(int i = 0; i < m ; i++)
       for(int j = 0; j < n; j++)
          if(arr[i][j] == '.'){
            if(i == 0 && j == 0){
              if(arr[i+1][j] == '.' ) addEdge(adj,maze[i][j],maze[i+1][j]);
              if(arr[i][j+1] == '.' ) addEdge(adj,maze[i][j],maze[i][j+1]);
            }
            if(i == m-1 && j == n-1){
              if(arr[i-1][j] == '.' ) addEdge(adj,maze[i][j],maze[i-1][j]);
              if(arr[i][j-1] == '.' ) addEdge(adj,maze[i][j],maze[i][j-1]);
            }
            if(i == m-1 && j == 0){
              if(arr[i-1][j] == '.' ) addEdge(adj,maze[i][j],maze[i-1][j]);
              if(arr[i][j+1] == '.' ) addEdge(adj,maze[i][j],maze[i][j+1]);
            }
            if(i == 0 && j == n-1 ){
              if(arr[i][j-1] == '.' ) addEdge(adj,maze[i][j],maze[i][j-1]);
              if(arr[i+1][j] == '.' ) addEdge(adj,maze[i][j],maze[i+1][j]);
            }
            if(i < m-1 && j < n-1 )
            if(i > 0 && j > 0 ){
              if(arr[i][j+1] == '.' ) addEdge(adj,maze[i][j],maze[i][j+1]);
              if(arr[i-1][j] == '.' ) addEdge(adj,maze[i][j],maze[i-1][j]);
              if(arr[i][j-1] == '.' ) addEdge(adj,maze[i][j],maze[i][j-1]);
              if(arr[i+1][j] == '.' ) addEdge(adj,maze[i][j],maze[i+1][j]);
            }
            if((i == 0 && j > 0 ))
              if(j < n-1 ){
              if(arr[i][j+1] == '.' ) addEdge(adj,maze[i][j],maze[i][j+1]);
              if(arr[i][j-1] == '.' ) addEdge(adj,maze[i][j],maze[i][j-1]);
              if(arr[i+1][j] == '.' ) addEdge(adj,maze[i][j],maze[i+1][j]);
              }
              if(j == 0 && i > 0)
              if(i < m-1 ){
                if(arr[i][j+1] == '.' ) addEdge(adj,maze[i][j],maze[i][j+1]);
                if(arr[i-1][j] == '.' ) addEdge(adj,maze[i][j],maze[i-1][j]);
                if(arr[i+1][j] == '.' ) addEdge(adj,maze[i][j],maze[i+1][j]);
              }
              if(j == n-1 && i > 0)
              if(i < m-1 ){
                if(arr[i][j-1] == '.' ) addEdge(adj,maze[i][j],maze[i][j-1]);
                if(arr[i+1][j] == '.' ) addEdge(adj,maze[i][j],maze[i+1][j]);
                if(arr[i-1][j] == '.' ) addEdge(adj,maze[i][j],maze[i-1][j]);
              }
              if(i == m-1 && j > 0)
              if(j < n-1){
                if(arr[i-1][j] == '.' ) addEdge(adj,maze[i][j],maze[i-1][j]);
                if(arr[i][j-1] == '.' ) addEdge(adj,maze[i][j],maze[i][j-1]);
                if(arr[i][j+1] == '.' ) addEdge(adj,maze[i][j],maze[i][j+1]);
              }
          }
          vector <int> path;
          BFS(adj,visited,source,path);
          vector < pair <int,int> > v;
          for(int i = 0; i < path.size()-k ; i++)
          	v.push_back(make_pair(path[i]/n,path[i]%n));
          for(int i = 0; i < m; i++)
          	for(int j = 0; j < n; j++) maze[i][j] = 0;
          for(int i = 0; i < v.size(); i++) maze[v[i].first][v[i].second] = 1;
          	for(int i = 0; i < m; i++){
          	for(int j = 0; j < n; j++)
          		if(maze[i][j] == 1) cout << ".";
          	    else cout << "#";  
          			cout << endl;    
          }
          return 0;
 }