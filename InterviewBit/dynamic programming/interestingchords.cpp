
int Solution::chordCnt(int A) {
    int dp[A+1]     ; 
    dp[0] = dp[1] =1 ; 
    long max = 1000000007 ;
    for(int i = 2 ;i <=A;i++){
        dp[i] = 0 ;
        for(int j =0 ; j<i;j++){
            dp[i] = (dp[i]+(dp[j]%max* dp[i-j-1]%max )%max)%(max);
        }
    }
    return dp[A]%max ;
}
