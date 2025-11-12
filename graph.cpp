#include<iostream>
using namespace std;
#define MAX 10

int main(){
    int n;
    cout<<"enter no of cities";
    cin>>n;

    int graph[MAX][MAX];
    cout<<"adjacency matrix";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
            int visited[MAX]={0};
            int stack[MAX],top = -1;
            stack[++top]=0;
            visited[0]=1;
    
    while(top != -1){
        int node=stack[top--];
        for(int i=0;i<n;i++){
            if(graph[node][i]==1 && visited[i]==0){
                visited[i]=1;
                stack[++top]=i;
            }
        }
    }
    bool connected=true;
    for(int i=0;i<n;i++){
        if(!visited[i]){
        connected=false;
        break;
    }
}
    if(connected)
        cout<<"graph is connected";
        else
        cout<<"graph is not connected";
        return 0;
    }
   
    
