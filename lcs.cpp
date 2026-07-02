//1143 recur + memo
class Solution {
public:
    int n1,n2;
    int t[1001][1001];
    int solve(int i, int j,string &text1, string &text2){
        if(i>=n1||j>=n2)return t[i][j]=0;
        if(t[i][j]!=-1)return t[i][j];

        //if match
        int val;
        if(text1[i]==text2[j]){
            val=1+solve(i+1,j+1,text1,text2);
        }else{
            val=max(solve(i+1,j,text1,text2),solve(i,j+1,text1,text2));
        }
        return t[i][j]=val;
    }
    int longestCommonSubsequence(string text1, string text2) {
        n1=text1.size();
        n2=text2.size();

        memset(t,-1,sizeof(t));
        return solve(0,0,text1,text2);
    }
};
//-------------------------------------------------------------------//

//bottom up
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();

        vector<vector<int>>t(n1+1,vector<int>(n2+1,0));

        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j]=1+t[i-1][j-1];//diagnol
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n1][n2];
    }
};
