//recur+memo to find length
class Solution {
  public:
    int t[501][501];
    int n1,n2;
    int solve(int i, int j,string &s1, string &s2){
        if(i==n1||j==n2)return (n1-i)+(n2-j);
        
        if(t[i][j]!=-1)return t[i][j];
        
        //if they match
        if(s1[i]==s2[j])return t[i][j]=1+solve(i+1,j+1,s1,s2);//take 1 time
        
        return t[i][j]=min(1+solve(i+1,j,s1,s2),1+solve(i,j+1,s1,s2));//take either time 2 options
    }
    int minSuperSeq(string &s1, string &s2) {
        // code here
        n1=s1.length();
        n2=s2.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,s1,s2);
    }
};

//using lcs to find length
class Solution {
  public:
    int minSuperSeq(string &s1, string &s2) {
        // code here
        int n1=s1.length();
        int n2=s2.length();
        
        vector<vector<int>>t(n1+1,vector<int>(n2+1,0));
        
        for(int i=1; i<=n1; i++){
            for(int j=1; j<=n2; j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        return n1+n2-t[n1][n2];
    }
};

//bottom up
class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        
        vector<vector<int>> t(n1 + 1, vector<int>(n2 + 1, 0));

        // Base cases
        for (int i = 0; i <= n1; i++) t[i][0] = i;
        for (int j = 0; j <= n2; j++) t[0][j] = j;

        // Fill table iteratively
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) { 
              
                if (s1[i - 1] == s2[j - 1]) {
                    t[i][j] = 1 + t[i - 1][j - 1];
                } 
                else {
                    t[i][j] = 1 + min(t[i - 1][j], t[i][j - 1]);
                }
            }
        }

        return t[n1][n2];
    }
};


//leetcode 1092
//printing it
