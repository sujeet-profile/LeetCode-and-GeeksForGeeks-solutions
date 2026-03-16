class Solution {
public:
    int possibleAns(vector<vector<int>> &grid, int i, int j, int k, int m, int n){
        int ans = 0, count = 0;
        int leftX = i + k, leftY = j - k;
        int botX = i + (2 *k), botY = j;
        int rightX = i + k, rightY = j + k;

        if(leftY < 0 || leftX >= m || rightX >= m || rightY >= n || botX >= m || botY >= n)
            return -1;

        for(int p = i, q = j; p < m && q >= 0 && p <= leftX && q >= leftY; ++p, q--){
            ans += grid[p][q];   
        }

        for(int p = leftX + 1, q = leftY + 1; p < m && q < n && q >= 0 && p <= botX && q <= botY ; ++p, ++q){
            ans += grid[p][q];
        }
        
        for(int p = i + 1, q = j + 1; p < m && q < n && p <= rightX && q <= rightY; ++p, ++q){
            ans += grid[p][q];
        }

        for(int p = rightX + 1, q = rightY - 1; p < m && q < n && p < botX && q > botY ; ++p, --q){
            ans += grid[p][q];
        }

        return ans;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> s;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = 0; k < ceil((float)max(m, n)/2); ++k){
                    int res = possibleAns(grid, i, j, k, m, n);
                    if(s.find(res) != s.end()) continue;
                    s.insert(res);
                    if(pq.size() == 3 && pq.top() < res){
                        pq.pop();
                        pq.push(res);
                    }
                    else if(pq.size() < 3){
                        pq.push(res);
                    }
                }
            }
        }
        vector<int> result;
        while(!pq.empty()){
            if(pq.top() != -1)
            result.push_back(pq.top());
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};