#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>list[], int u, int v){

    list[u].push_back(v);
    list[v].push_back(u);
}

void dfsRecursion(int node, vector<int>list[], vector<int>&visited){
	cout<<node<<" ";
	visited[node] = 1;
	
	for(auto i:list[node]){
		if(!visited[i]){
			dfsRecursion(i,list,visited);
		}
	}
}

void dfs(int n, vector<int>list[]){
	vector<int>visited(n+1,0);
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfsRecursion(i,list,visited);
		}
	}
}

void bfs(vector<int>list[],int n){
    //Check the adjacent vertices first and then move to the next
    
	//TAKING A VECTOR OF N+1 AND MARKING IT'S INITIAL VALUES AS FALSE THAT IS 0
	//WE TOOK ZERO IT MEANS THESE ALL ARE UNIVISITED AT FIRST
	vector<int>visited(n+1,0);

	//I USED A FOR LOOP BECAUSE THERE MIGHT BE MORE THAN ONE NUMBER OF COMPONENTS IN GRAPH
	//SO TO ITERATE THROUGH EACH OF THEM WE HAVE TO TAKE THIS OF APPROACH
    for(int i=1;i<=n;i++){
		
		//FIRST CHECKING THAT THE ARRAY IS VISITED OR NOT FOR THE FIRST COMPONENT
        if(!visited[i]){
			
			//TAKING A QUEUE TO PUT THE EACH VERTICE THAT I AM GOING TO ITERATE
            queue<int>q;
            q.push(i);
			//AND MARKING IT 1 SO IT MEANS I WILL NOW NOT INCLUDE THIS IN MY BFS
            visited[i] = 1;
			
			//NOW WE KNOW THAT WE HAVE PUTTED THE VALUE INSIDE THE QUEUE BUT NOW IT'S TIME TO
			//REMOVE THE VALUES AND PRINT THEM 
            while(!q.empty()){
                int node = q.front();
                q.pop();
                cout<<node<<" ";
				
				//NOW CHECKING THE ADJACENT NODES OF THAT PARTICULAR NODE AND WILL PUSH THEM IN QUEUE
                for(auto i: list[node]){
                    if(!visited[i]){
                        q.push(i);
                        visited[i] = 1;
                    }
                }
            }

        }
    }
}


void displayTheGraph(vector<int>list[], int n){
    for(int i=1;i<(n+1);i++){
        cout<<i<<" -> ";
        for(int j=0;j<list[i].size();j++){
            cout<<list[i][j]<<" ";
        }
        cout<<endl;
    }
}

void mainMenu(){
    cout<<"\nWhich task you want to perform"<<endl;
    cout<<"0  -  Exit \n";
    cout<<"1  -  Create Adjacency List \n";
    cout<<"2  -  Display The Graph \n";

    cout<<"Enter Your Option: ";
    int option;
    cin>>option;

    switch(option) {
        case 0:
            break;
        case 1:
            int n, m, u, v;
            cout << "Enter Number of Nodes: ";
            cin >> n;
            cout << "Enter Number of Edges: ";
            cin >> m;

            //Assuming the graph is 1 based index
            vector<int> list[n+1];

            for (int i = 0; i < m; i++) {
                cout << "Enter u value: ";
                cin >> u;

                cout << "Enter v value: ";
                cin >> v;

                addEdge(list, u, v);
            }
            for(int i=1;i<(n+1);i++){
                cout<<i<<" -> ";
                for(int j=0;j<list[i].size();j++){
                    cout<<list[i][j]<<" ";
                }
                cout<<endl;
            }
			cout<<"\nBFS TRAVERSAL IS: ";
            bfs(list,n);
			cout<<"\n\nDFS TRAVERSAL IS: ";
			dfs(n,list);
            mainMenu();
            break;
//        case 2:
//            displayTheGraph(list,n);
//            mainMenu();
//            break;
    }
}
int main(){
    mainMenu();
}