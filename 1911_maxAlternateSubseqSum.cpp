class Solution {
public:
    int n;
    long long t[1000001][2];
    long long solve(int idx,vector<int>& nums,bool flag){
        if(idx>=n)return 0;
        if(t[idx][flag]!=-1)return t[idx][flag];
        
        long long skip=solve(idx+1,nums,flag);
        long long val=nums[idx];
        if(flag==false)val=-val;

        long long take=solve(idx+1,nums,!flag)+val;
        return t[idx][flag]=max(skip,take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums,true);
    }
};
//------------------------------------bottom up---------------------
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long>>t(n+1,vector<long>(2,0));//even->0, odd->1
        for(int i=1; i<n+1; i++){
            //even length
            t[i][0]=max(t[i-1][1]-nums[i-1],t[i-1][0]);

            //odd
            t[i][1]=max(t[i-1][0]+nums[i-1],t[i-1][1]);
        }
        return max(t[n][0],t[n][1]);
    }
};
