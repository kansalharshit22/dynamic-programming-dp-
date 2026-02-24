//recur+memo
class Solution {
public:
    int t[2501][2501];
    int solve(vector<int>& nums, int i, int p){
        if(i>=nums.size())return 0;
        if(p!=-1&&t[i][p]!=-1)return t[i][p];

        int take=0;
        if(p==-1||nums[i]>nums[p]){
            take=1+solve(nums,i+1,i);
        }
        int skip=solve(nums,i+1,p);
        if(p!=-1)t[i][p]=max(take,skip);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,-1);
    }
};

//-----------------bottom up-------------------
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //bottom-up
        int maxl=1;
        vector<int>t(nums.size(),1);//initially 1 size subsequence

        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[i],t[j]+1);//update LIS ending at i
                    maxl=max(maxl,t[i]);
                }
            }
        }
        return maxl;
    }
};

//lis Variant
//follow up max length of pair chain 
//similar ques same template
