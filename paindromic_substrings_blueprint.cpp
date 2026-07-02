//lc 5: lc: 647 recur+memo
class Solution {
public:
    int t[1001][1001];
    bool solve(string &s, int i, int j){
        if(i>=j)return t[i][j]=true;
        
        if(t[i][j]!=-1)return t[i][j];
        if(s[i]!=s[j])return t[i][j]=false;
        return t[i][j]=solve(s, i+1, j-1);
    }   
    string longestPalindrome(string s) {
        int n=s.length();
        string res="";
        int maxlen=-1;
        //if we found a string more than maxlen update res

        memset(t,-1,sizeof(t));


        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
               if(solve(s,i,j)&&j-i+1>maxlen){
                    maxlen=j-i+1;
                    res=s.substr(i, j-i+1);
               }         
            }
        }
        return res;
    }
};

//--------------------------------------------------------------------//
class Solution {
public:
    int t[1001][1001];
    bool solve(string &s, int i, int j){
        if(i>=j)return true;
        
        if(t[i][j]!=-1)return t[i][j];
        if(s[i]!=s[j])return t[i][j]=false;
        return t[i][j]=solve(s, i+1, j-1);
    }
    int countSubstrings(string s) {
        int n=s.length();
        int cnt=0;
        memset(t,-1,sizeof(t));


        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
               if(solve(s,i,j)){
                    cnt++;
               }         
            }
        }
        return cnt;
    }
};

//-------------------------------------------------------------//
// bottom up BLUEPRINT
//647
class Solution {
public:
    int countSubstrings(string s) {
        //bottom up blueprint
        int n=s.length();
        //bool 2d array
        //state t[i][j]: [i to j] inclusive substring
        vector<vector<bool>>t(n,vector<bool>(n,false));
        int cnt=0;


        for(int L=1; L<=n; L++){
            for(int i=0; i+L-1<n; i++){
                    int j=i+L-1;
                    if(i==j){
                        t[i][i]=1;//true length 1
                    }else if(i+1==j){
                        //length 2
                        t[i][j]=(s[i]==s[j]);//if both equal then true
                    }else{
                        t[i][j]=((s[i]==s[j])&&(t[i+1][j-1]));
                    }

                    if(t[i][j])cnt++;
            }
        }

        return cnt;
    }
};

//---------------------------------------------------------------//
// bottom up- lc 5

