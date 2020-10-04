class Solution {
public:
    int numTrees(int n) {
        // its nth catalan number problems
        int i,j;
        int dp[n+5];
        dp[0]=dp[1]=1;
        for(i=2;i<=n;i++){
            dp[i]=0;
            for(j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};