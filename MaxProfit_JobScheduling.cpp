class Solution {//dp + binary search + 1d memo
public:
    int n;
    typedef pair<pair<int,int>,int> p;
    int t[50001];//max jobs starting form ith job 1D memo

    int findindex(vector<p>&vec,int start, int target){
        int end=n;
        while(start<end){
            int mid=start+(end-start)/2;
            if(vec[mid].first.first>=target)end=mid;
            else start=mid+1;
        }
        return end;
    }
    int solve(int i, vector<p>&vec){
        if(i>=n)return 0;
        if(t[i]!=-1)return t[i];

        int idx=findindex(vec,i+1,vec[i].first.second);

        int take = vec[i].second+solve(idx, vec);
        int skip=solve(i+1, vec);

        return t[i]=max(skip,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        memset(t,-1,sizeof(t));

        vector<p>vec(n);
        for(int i=0; i<n; i++){
            vec[i]={{startTime[i],endTime[i]},profit[i]};
        }
        sort(vec.begin(),vec.end());

        return solve(0,vec);
    }
};
