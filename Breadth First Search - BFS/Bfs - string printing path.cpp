#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
string vis[MAX];
string level[MAX];
vector <int> vec[MAX];
queue <int> q;

map <string,int> visited;
map <string,string> route;

int bfs(string snode, string des, map<string, vector<string> > graph)
{
    queue <string> q;
    q.push(snode);
    visited[snode] = 0;

    while(!q.empty()){
        string top = q.front();
        cout << top << "   " << visited[top] << endl;
        q.pop();

        if (top == des)
            return visited[top];

        for (int i=0; i<graph[top].size(); i++){
            string n = graph[top][i];

            if (visited[graph[top][i]] == -1){
                visited[graph[top][i]] = visited[top] + 1;
                route[graph[top][i]] = top; //store parent for printing path
                q.push(graph[top][i]);
            }
        }
    }
    return -1;
}

void printpath(string a, string b){
  if(a==b){return;}
  printpath(route[a],b);
  cout<<route[a]<<" "<<a<<endl;;
}



int main()
{
    map<string, vector<string> > graph;
    string a, b, snode, des;
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        visited[a] = -1;
        visited[b] = -1;
    }
    cin >> snode >> des;

    if(bfs(snode,des,graph)!=-1)
      printpath(des,snode);
     else
      printf("No route\n");

    return 0;
}

