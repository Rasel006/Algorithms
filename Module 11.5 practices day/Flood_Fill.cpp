

class Solution {
public:
    int startPixel;
    vector<vector<int>> colorImage;
    vector<vector<bool>> visited{50, vector<bool>(50, false)};
    vector<pair<int, int> > direction = {{0, -1}, {0, 1}, {1, 0},{-1, 0}};

    bool isValid(int i, int j, int n, int m){
        return (i >=0 && i < n && j >= 0 && j < m);
    }
    void BFS(int si, int sj, int color,vector<vector<int>> &image, int n, int m){
        queue<pair<int, int>> q;
        q.push({si, sj});
        visited[si][sj] = true;
        image[si][sj] = color;
        
        while(!q.empty()){
            pair<int,int> Unpair = q.front();
            q.pop();

            int i = Unpair.first;
            int j = Unpair.second;

            for(auto && d : direction){
                int ni = i + d.first;
                int nj = j + d.second;
                
                if(isValid(ni, nj, n, m) && !visited[ni][nj] && image[ni][nj] == startPixel){
                    q.push({ni, nj});
                    image[ni][nj] = color;
                    visited[ni][nj] = true;
                }

            }

        }
         
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
     startPixel = image[sr][sc];
     int n = image.size() ;
     int m =image[0].size();
    //  cout << m << n;
     BFS(sr,sc,color,image, n, m);
     return image;   
    }
};