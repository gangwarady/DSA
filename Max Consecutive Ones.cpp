class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flag = 1;
        for(int i =0; i<nums.size();i++){
            if(nums[i]==1){
                flag=0;
            }
        }
        if(flag==1){
            return 0;
        }
        int maxi = 1;
        int count = 1;
        for(int i =0; i<nums.size()-1; i++){
            if(nums[i]==1 && nums[i+1]==1){
                count++;
            }
            else{
                count = 1;
            }
            maxi = max(maxi,count);
        }
        return maxi;
    }
};
