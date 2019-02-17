#include <bits/stdc++.h>
using namespace std;

#define MAX 1000
string vis[MAX];
string level[MAX];
vector <int> vec[MAX];
queue <int> q;

map <string,int> visited;

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
                q.push(graph[top][i]);
            }
        }
    }
    return -1;
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
    int ans = bfs(snode, des, graph);

    return 0;
}
