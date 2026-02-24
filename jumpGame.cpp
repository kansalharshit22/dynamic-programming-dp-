class Solution {//brute 0(n^2) kindof bottom up
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        if(nums[0]==0)return false;

        vector<bool>canvisit(n,false);
        for(int i=n-2; i>=0; i--){
            int val=nums[i];
            for(int j=1; j<=val; j++){
                if(i+j==n-1||canvisit[i+j]==true){
                    canvisit[i]=true;
                    break;
                }
            }
        }
        return canvisit[0];
    }
};
//----------------------------recur+memo------------------------
class Solution {
public:
    int n;
    int t[10001];
    bool solve(int idx,vector<int>& nums){
        if(idx>=n-1)return true;
        if(t[idx]!=-1)return t[idx];
        for(int i=1; i<=nums[idx]; i++){
            if(solve(idx+i,nums))return t[idx]=true;
        }
        return t[idx]=false;
    }
    bool canJump(vector<int>& nums) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};
//----------------------greedy o(N)-----------------------------
class Solution {
public://smart->O(n)
    bool canJump(vector<int>& nums) {
        int maxr=0;
        for(int i=0; i<nums.size(); i++){
            if(i>maxr)return false;
            maxr=max(maxr,i+nums[i]);
        }
        return true;
    }
};
