int Solution::isInterleave(string A, string B, string C) {
    int asize = A.length() , bsize = B.length() ,csize = C.length();    
     bool dp[asize + 1][bsize + 1]; 
  
    memset(dp, false, sizeof(dp));  
    if ((asize + bsize) != csize) 
        return false; 
    for (int i = 0; i <= asize; i++) { 
        for (int j = 0; j <= bsize; j++) { 
            if (i == 0 && j == 0) 
                dp[i][j] = true; 
            // A is empty 
            else if (i == 0) { 
                if (B[j - 1] == C[j - 1]) 
                    dp[i][j] = dp[i][j - 1]; 
            } 
  
            // B is empty 
            else if (j == 0) { 
                if (A[i - 1] == C[i - 1]) 
                    dp[i][j] = dp[i - 1][j]; 
            } 
            // C's current char matches with A's but not with B's
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) 
                dp[i][j] = dp[i - 1][j]; 
            // C's current char matches not with A's but with B's
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                dp[i][j] = dp[i][j - 1]; 
  
              // C's current char matches with A's but  with B's 
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]); 
        } 
    } 
  
    return dp[asize][bsize];
}
