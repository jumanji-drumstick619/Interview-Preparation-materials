
int Solution::minDistance(string A, string B) {
    int a_size = A.length() ; 
    int b_size = B.length() ; 
    int dp[a_size+1][b_size+1]  ; 
   memset(dp,0,sizeof(dp)) ; 
   for(int i =0 ;i <=b_size ; i++) dp[0][i] = i ; 
   for(int i =0 ; i<=a_size ; i++) dp[i][0] = i ; 
   for(int i= 1 ;i <=a_size; i++){
       for(int  j =1 ; j<=b_size ;j++){
            if(A[i-1]==B[j-1])
                dp[i][j] = dp[i-1][j-1] ;
            else {
                dp[i][j] = 1+min(dp[i-1][j] , min(dp[i][j-1] , dp[i-1][j-1])) ; 
            }
       }
   }
   return dp[a_size][b_size] ;
}
