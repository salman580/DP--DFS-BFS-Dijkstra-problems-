#include <bits/stdc++.h>
using namespace std;
const int mx=1000;
bool visited[mx];
vector<int> graph[mx];
int dist[mx];
void bfs(int source)
{
    memset(visited,0,sizeof(visited));
    queue<int> q;
    dist[source]=0;
    visited[source]=true;
    q.push(source);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int i=0;i<graph[node].size();i++){
            int next=graph[node][i];
            if(!visited[next]){
                visited[next]=true;
                q.push(next);
                dist[next]=dist[node]+1;
            }
        }
    }

}
int main()
{
    int x=-1,y=-1,l=0;
    bool b[mx]={0},s=false;
    while(scanf("%d%d", &x, &y) && ( x || y )){
        graph[x].push_back(y);
        while(scanf("%d%d", &x, &y) && ( x || y )){
            b[x]=true;b[y]=true;
            graph[x].push_back(y);
        }
        long sum=0,k=0;
        for(int i=1;i<=100;i++){
            if(b[i]){k++;bfs(i);
                for(int j=1;j<=100;j++){if(b[j]){sum+=dist[j];}
                }
            }
        }
        for(int i=0;i<=100;i++){
            graph[i].clear();
        }
        memset(b,false,sizeof(b));
        l++;
        cout<<"Case "<<l<<": average length between pages = "<<fixed<<setprecision(3)<<(double)sum/(k*(k-1))<<" clicks"<<endl;
    }

}
