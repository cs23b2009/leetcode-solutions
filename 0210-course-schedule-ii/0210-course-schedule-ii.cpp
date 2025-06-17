class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        vector<int> indegree(numCourses, 0);
        vector<int> ans;
        // Build adjacency list and indegree array
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adjlist[prereq].push_back(course);  // prereq -> course
            indegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        
        while (!q.empty()) {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (int neighbor : adjlist[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        if(ans.size()==numCourses){
            return ans;
        }
        return {};
    }
};