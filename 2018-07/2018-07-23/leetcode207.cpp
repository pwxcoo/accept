////////////////////////////////////DFS////////////////////////////////////////////////////
class Solution {
public:
    vector<unordered_set<int>> makegraph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> g(numCourses);
        for(auto edge: prerequisites)
        {
            g[edge.second].insert(edge.first);
        }
        return g;
    }
    
    bool dfs(int now, vector<unordered_set<int>>& g, vector<bool>& visited, vector<bool>& onpath)
    {
        if(visited[now]) return true;
        
        onpath[now] = true;
        for(auto i: g[now])
        {
            if(visited[i]) continue;
            if(onpath[i]) return false;
            if(!dfs(i, g, visited, onpath)) return false;
        }
        onpath[now] = false;
        visited[now] = true;
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = makegraph(numCourses, prerequisites);
        vector<bool> visited(numCourses, false), onpath(numCourses, false);
        
        for(int i = 0; i < numCourses; i++)
        {
            if(!dfs(i, graph, visited, onpath)) return false;
        }
        return true;
    }
};


////////////////////////////////////////BFS//////////////////////////////////////////////////

class Solution {
public:
    vector<unordered_set<int>> makegraph(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<unordered_set<int>> g(numCourses);
        for(auto edge: prerequisites)
        {
            g[edge.second].insert(edge.first);
        }
        return g;
    }
    
    vector<int> compute_degree(vector<unordered_set<int>> g)
    {
        vector<int> d(g.size());
        for(auto edges: g)
            for(auto node: edges)
            {
                d[node]++;
            }
        return d;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        auto graph = makegraph(numCourses, prerequisites);
        auto degree = compute_degree(graph);
        
        int ok = 0;
        while(1)
        {
            int i;
            for(i = 0; i < numCourses; i++)
            {
                if(!degree[i]) break;
            }
            if(i == numCourses) return false;
            if(++ok == numCourses) return true;
            
            degree[i] = -1;
            for(auto node: graph[i])
                degree[node]--;
        }
        return true;
    }
};