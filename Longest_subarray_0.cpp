class Solution{
    public:
    int maxLen(vector<int>&v, int n)
    {   
        int sum =0;
        int maxi =0;
        unordered_map<int,int> m;
        for(int i=0; i<n; i++){
            sum+=v[i];
            //cout<<sum<<endl;
            if(sum==0){
                maxi = i+1;
                //cout<<"max"<<maxi<<endl;
            }
            else if(m.find(sum)!=m.end()){
                maxi = max(maxi, i-m[sum]);
                //cout<<"max2"<<maxi<<endl;
            }
            else{
                m[sum] = i;
            }
        }
    return maxi;
    }
};
