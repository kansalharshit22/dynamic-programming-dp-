//recursive+memo
class Solution {
public:
    int t[101];
    int solve(int idx,vector<int>& nums){
        if(idx>=nums.size())return 0;
        if(t[idx]!=-1)return t[idx];

        int take=nums[idx]+solve(idx+2,nums);
        int skip=solve(idx+1,nums);
        return t[idx]=max(skip,take);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};
// ---------------------------------------------------------------------------------------------------------------------------------------
//bottom-up
class Solution {
public://
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>t(n+1,0);//indexing 0 to n
        t[1]=nums[0];
        for(int i=2; i<=n; i++){
            int take=nums[i-1]+t[i-2];
            int skip=t[i-1];
            t[i]=max(take,skip);
        }
        
        return t[n];
    }
};
