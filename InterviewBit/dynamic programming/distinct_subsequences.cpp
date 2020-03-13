int Solution::numDistinct(string S, string T) {
    int row = S.length() , col =T.length() ; 
    if(col>row) return 0 ;
    int dp[row+1][col+1] ; 
    memset(dp,0,sizeof(dp)) ;
    for(int i =0 ;i <=row;i++) dp[i][0] = 1 ; 
    for(int i= 1 ;i<=row;i++){
        for(int j =1; j <=col;j++){
            if(S[i-1]==T[j-1]) dp[i][j] = dp[i-1][j-1]+dp[i-1][j] ;
            else dp[i][j] = dp[i-1][j] ;
        }
    }
    return dp[row][col] ;
}
