class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int top = x;
        int bottom = x + k - 1;
        
        while (top < bottom) {
            for (int j = 0; j < k; j++) {
                swap(grid[top][y + j], grid[bottom][y + j]);
            }
            top++;
            bottom--;
        }
        
        return grid;
    }
};
