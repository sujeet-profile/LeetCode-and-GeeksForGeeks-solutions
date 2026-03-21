class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rows = grid.size();
        int col = grid[0].size();
        for(int i = x, j = x + k - 1; i < x + k / 2 && i < rows; ++i, j--){
            for(int p = y; p < y + k; ++p){
                int temp = grid[i][p];
                grid[i][p] = grid[j][p];
                grid[j][p] = temp;
            }
        }
        return grid;
    }
};