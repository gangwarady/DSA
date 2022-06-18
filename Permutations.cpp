class Solution {
public:
    
    void solve( vector<vector<int>> &ans, vector<int> &ds, unordered_map <int,int> &freq, vector<int>& nums){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(!freq[nums[i]]){
                ds.push_back(nums[i]);
                freq[nums[i]] = 1;
                solve(ans, ds, freq, nums);
                freq[nums[i]] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        unordered_map <int,int> freq;
        for(int i =0;i<nums.size(); i++){
            freq[nums[i]] = 0;
        }
        solve(ans, ds, freq, nums);
        return ans;
        
    }
};
