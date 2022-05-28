class Solution {
public:
    int find(int x,int y,int m,int n, vector<vector<int>> &dp){
        if(y==(n-1)&&x==(m-1)) return 1;
        if(y>=n||x>=m) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
     else return dp[x][y]=find(x+1,y,m,n,dp)+find(x,y+1,m,n,dp);
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int x = 0;
        int y = 0;
        int paths=find(0,0,m,n,dp);
        if(m==1&&n==1)
            return paths;
        return dp[0][0];
    }
};
