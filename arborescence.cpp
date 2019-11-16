#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>> >& graph, int root, int* vis){

    vis[root] = true;
    cout << root+1 << " ";
    int i, j;
    for(i = 0; i < graph[root].size(); i++){
        if(vis[graph[root][i].first] == false){
            dfs(graph, graph[root][i].first, vis);
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, w, root, i, j, k;
        cin >> n >> root;
        cin >> m;
        root--;
        vector<vector<pair<int, int>> > graph(n), entering_graph(n), temp_graph(n);
        for(i = 0; i < m; i++){
            int x, y;
            cin >> x >> y >> w;
            graph[x-1].push_back(make_pair(w, y-1));
        }
        
        int vis[n];
        memset(vis, false, n*sizeof(int));
        dfs(graph, root, vis);

		for(i = 0; i < n; i++){
			if(vis[i] == false){
				graph[i].clear();
			}
		}

        cout << "\n";
        
        for(i = 0; i < n; i++){
            if(graph[i].begin() == graph[i].end())
                continue;
            for(j = 0; j < graph[i].size(); j++){
                cout << i+1 << " " << graph[i][j].second+1 << " " << graph[i][j].first << "\n";
                entering_graph[graph[i][j].second].push_back({graph[i][j].first, i});
                temp_graph[graph[i][j].second].push_back({graph[i][j].first, i});
            }
        }
        cout << "\n";
        
        int flag = false;
        for(i = 0; i < n; i++){
            if(graph[i].begin() == graph[i].end())
                continue;
            sort(temp_graph[i].begin(), temp_graph[i].end());
            if(temp_graph[i][0].second == root){
            	flag = true;
            }
        }
        
        if(flag == false){
        	vector<pair<int, int>> v = graph[root];
        	if(v.size() == 0){
        		cout << "No edge comming out of root node!\n" ;
        	}
        	else{
        		sort(v.begin(), v.end());
        		temp_graph[v[0].second][0] = v[0];
        	}
        }

    }
    return 0;
}
