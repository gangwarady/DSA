class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        sort(intervals.begin(), intervals.end());
        for(int i =0; i< intervals.size(); i++){
            if(v.empty()){
                v.push_back(intervals[i]);
            }
            else{
                if(v.back()[1]>=intervals[i][0]){
                    v.back()[1] = max(v.back()[1],intervals[i][1] );
                }
                else{
                    v.push_back(intervals[i]);
                }
            }
        }
        return v;
    }
};
