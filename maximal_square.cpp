class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //very imp dp+grid maximal asked in interviews
        int m=matrix.size(), n=matrix[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        int maxside=0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0||j==0)t[i][j]=matrix[i][j]-'0';
                else if(matrix[i][j]=='1'){
                    t[i][j]=1+min({t[i-1][j-1],t[i-1][j],t[i][j-1]});
                }//it will denote the side length at i,j

                maxside=max(maxside,t[i][j]);
            }
        }

        
        return maxside*maxside;//area
    }
};


//follow up
// count square matrices
class Solution {
public:                           
    //     [0,1,1,1],   [0,1,1,1]  
    //     [1,1,1,1], ->[1,1,2,2]->cnt=3+6+6=15
    //     [0,1,1,1]    [0,1,2,3]
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        int res=0;
        vector<vector<int>> t(m,vector<int>(n));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0||j==0){
                    t[i][j]=matrix[i][j];
                }
                else if(matrix[i][j]==1){
                    t[i][j]=1+min({t[i-1][j],t[i-1][j-1],t[i][j-1]});
                }
                res+=t[i][j];//it will include all the count of square at i,j bottom right with that side
            }
        }
        return res;
    }
};
