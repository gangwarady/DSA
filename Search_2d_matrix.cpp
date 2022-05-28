class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool res = false;
        int m = matrix.size();
        int n = matrix[0].size();
        int row =-1;
        
        if(m>1){
            for(int i =0; i<m-1; i++){
                if(target>=matrix[i][0] && target<matrix[i+1][0]){
                    row = i;
                    
                }
                else if(target>=matrix[i+1][0] && i==m-2){
                    row = i+1;
                    
                    break;
                }
            }
        }
        else{
            row=m-1;
        }
        cout<<row;
        if(row>=0){
            for(int i =0 ; i<n; i++){
                if(matrix[row][i]==target){
                    res=true;
                    break;
                }
            }
        }    
        return res;
    }
};
