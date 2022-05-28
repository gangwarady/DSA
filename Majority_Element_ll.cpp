class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int limit = nums.size()/3;
        //cout<<limit<<endl;
        sort(nums.begin(), nums.end());
        int count = 1;
        for(int i =0; i< nums.size(); i++){
            if(i<nums.size()-1 && nums[i]==nums[i+1]){
                count+=1;
            }
            else{
                if(count>limit){
                    ans.push_back(nums[i]);
                }
                count = 1;
            }
        }
        return ans;
    }
};
