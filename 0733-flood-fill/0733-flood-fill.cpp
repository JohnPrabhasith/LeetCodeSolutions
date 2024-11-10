class Solution {
private:
    void dfs(vector<vector<int>> &arr, int i, int j, int color, int init_color, int m, int n) {
        if((i < 0) || (j < 0) || (i >= n) || (j >= m) || (arr[i][j] != init_color) ){
            return;
        }
        arr[i][j] = color;

        dfs(arr,i+1,j,color,init_color,m,n);
        dfs(arr,i-1,j,color,init_color,m,n);
        dfs(arr,i,j+1,color,init_color,m,n);
        dfs(arr,i,j-1,color,init_color,m,n);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        if (image[sr][sc] == color) {
            return image;
        }

        int init_color = image[sr][sc];
        dfs(image, sr, sc, color, init_color, m, n);

        return image;
    }
};