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


//printing lcs

string printLCS(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();

    // 1. Build standard Bottom-Up DP Table
    vector<vector<int>> t(n1 + 1, vector<int>(n2 + 1, 0));

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (text1[i - 1] == text2[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            } else {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }

    // 2. Trace Back to Construct the LCS String
    string lcs = "";
    int i = n1, j = n2;

    while (i > 0 && j > 0) {
        if (text1[i - 1] == text2[j - 1]) {
            lcs.push_back(text1[i - 1]); // Character is part of LCS
            i--;
            j--; // Move diagonally up-left
        } else if (t[i - 1][j] > t[i][j - 1]) {
            i--; // Move UP
        } else {
            j--; // Move LEFT
        }
    }

    // 3. Reverse string as we built it backward
    reverse(lcs.begin(), lcs.end());

    return lcs;
}
