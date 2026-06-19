class Solution {//recursive based on indexing
  public:
    int n;
    int t[1001][1001];
    int solve(int i,vector<int>&wt, vector<int>&val, int W){
        if(i>=n||W==0)return 0;
        if(t[i][W]!=-1)return t[i][W];
        int take=0, skip=0;
        if(wt[i]<=W){
            take=val[i]+solve(i+1,wt,val,W-wt[i]);
        }
        skip=solve(i+1,wt,val,W);
        return t[i][W]=max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        n=val.size();
        memset(t,-1,sizeof(t));
        return solve(0,wt,val,W);
    }
};

//----------------------------------------------------------------//
//based on items startinf from n
class Solution {
  public:
    int t[1001][1001];
    int solve(int n,vector<int>&wt, vector<int>&val, int W){
        if(n<=0||W==0)return 0;
        if(t[n][W]!=-1)return t[n][W];
        int take=0, skip=0;
        if(wt[n-1]<=W){
            take=val[n-1]+solve(n-1,wt,val,W-wt[n-1]);
        }
        skip=solve(n-1,wt,val,W);
        return t[n][W]=max(take,skip);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        memset(t,-1,sizeof(t));
        return solve(n,wt,val,W);
    }
};

// -------------------------------------------------------------------------//
//bottom up using 2d dp table
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>t(n+1,vector<int>(W+1));
        for(int j=0; j<W+1; j++)t[0][j]=0;
        for(int i=0; i<n+1; i++)t[i][0]=0;
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<W+1; j++){
                int take=0;
                if(wt[i-1]<=j)take=val[i-1]+t[i-1][j-wt[i-1]];
                
                int skip=t[i-1][j];
                t[i][j]=max(take,skip);
            }
        }
        return t[n][W];
    }
};

// -------------------------------------------------------------------------------
//space optimised bootom up using 2 vectors curr and prev
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        
        for(int i=1; i<n+1; i++){//for every item
            for(int j=1; j<W+1; j++){
                int take=0;
                
                if(wt[i-1]<=j)take=val[i-1]+prev[j-wt[i-1]];
                
                int skip=prev[j];
                
                curr[j]=max(take,skip);
            }
            prev=curr; //after filling all j's in curr row(vector)
        }
        return prev[W];
    }
};
