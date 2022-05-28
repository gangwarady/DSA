class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int m = 1;
        int value = nums[0];
        sort(nums.begin(), nums.end());
        for(int i =0; i<nums.size()-1; i++){
            if(nums[i]==nums[i+1]){
                count +=1;
                if(count>m){
                    m = count;
                    value = nums[i];
                }
              
            }
            else{
                count = 1;
            }
        }
        return value;
    }
};
