#include<bits/stdc++.h>
using namespace std;
using ll = long long;

// Depth-First Search function 
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& stk) {     
	visited[node] = true;     
	for (int neighbor : adj[node]) {         
		if (!visited[neighbor]) {             
			dfs(neighbor, adj, visited, stk);         
		}     
	}     
	stk.push(node); 
}  
// Topological Sorting function 
stack<int> topologicalSort(vector<vector<int>>& adj, int n) {     
	vector<bool> visited(n+1, false);     
	stack<int> stk;      

	// DFS traversal for each unvisited vertex     
	for (int i = 1; i <= n; i++) {         
		if (!visited[i]) {             
			dfs(i, adj, visited, stk);         
		}     
	}      
	// Extracting the result from stack     
	//vector<int> result;     
	//while (!stk.empty()) {         
	//	result.push_back(stk.top());         
	//	stk.pop();     
	//}     
	return stk;//result; 
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<vector<int>> adj(n+1);
	for(int i=1;i<=n;i++){
		int u;
		while(cin>>u){
			if(!u)break;
			adj[i].push_back(u);
		}
	}
	stack<int> s = topologicalSort(adj,n);
	//vector<int> speakers_order = topologicalSort(adj,n);
	//for(int i=1;i<=n;i++){
	//	cout<<speakers_order[i]<<' ';
	//}
		 //Output the adjacency list     
		//cout << "Adjacency List:" << endl;     
		//for (int u = 1; u <= n; ++u) {         
			////cout << u << " -> ";         
			//for (int v : adj[u]) {             
				//cout << v << " ";         
			//}         
			//cout << endl;     
		//}
	while(!s.empty()){
		cout<< s.top()<<' ';
		s.pop();
	}
	return 0;
}
