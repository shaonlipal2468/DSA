int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==1)
            return 0;
        int kn=k+1;

        int dp[kn][n];

        //first row initialization
        for(int t=0;t<k+1;t++)
            dp[t][0]=0;

        //first column initialization
        for(int d=0;d<n;d++)
            dp[0][d]=0;
        for(int t=1;t<=k;t++)
        {
            int max_before = INT_MIN;
            for(int d=1;d<n;d++)
            {
                max_before= max(max_before,dp[t-1][d-1]-prices[d-1]);
                dp[t][d]= max(dp[t][d-1], max_before+prices[d]);
            }
        }
        return dp[k][n-1];

    }
