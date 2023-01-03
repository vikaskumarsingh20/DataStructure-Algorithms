class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> q;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){ // push all rotten oranges
                    q.push({i,j});
                }
            }
        }
        
        int time=0;
        vector<pair<int,int>> validmove={{1,0},{-1,0},{0,-1},{0,1}};
        while(!q.empty())
        {
            int size=q.size();
            bool is_any_rotten=false;
            for(int i=0;i<size;i++){

                auto p=q.front();
                q.pop();
                int x1=p.first;
                int y1=p.second;

                for(int k=0;k<4;k++){
                    int x=x1+validmove[k].first;
                    int y=y1+validmove[k].second;
                    if(x<0 || x>=m || y<0 || y>=n || grid[x][y]!=1){
                        continue;
                    }
                
                    is_any_rotten=true;
                    grid[x][y]=2;
                    q.push({x,y});
                }
                
            }
            if(is_any_rotten)
                time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){ // checking is any fresh oraneg reamin
                   return -1;
                }
            }
        }
        return time;
    }
};
