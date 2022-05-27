class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(!nums2.empty()){
            int ind = 0;
            for(int i=0; i<m; i++){
                if(nums1[i]>nums2[ind]){
                    swap(nums1[i], nums2[ind]);
                    sort(nums2.begin(), nums2.end());
                }
            }
            for(int i = m; i<nums1.size(); i++){
                nums1[i]= nums2[ind];
                ind++;
            }
        }
        
    }
};
