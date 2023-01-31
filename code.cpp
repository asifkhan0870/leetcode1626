class Solution {
public:
    int bestTeamScore(vector<int>& s, vector<int>& a) {
        

        vector<vector<int>>res;

        for(int i=0;i<s.size();i++){

            res.push_back({-a[i],-s[i]});
        }

        sort(res.begin(),res.end());

        int dp[s.size()];

        memset(dp,0,sizeof(dp));

        int ans=0;


        for(int i=0;i<s.size();i++){


            for(int j=i;j>=0;j--){

                if(-res[i][1]<=-res[j][1]){

                    dp[i]=max(dp[i],dp[j]-res[i][1]);
                }
            }

            ans=max(ans,dp[i]);
        }

        return ans;
    }
};