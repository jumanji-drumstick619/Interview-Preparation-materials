int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    const vector<int> &friends_cap = A;
    const vector<int> &dishes_fill = B;
    const vector<int> &dishes_cost = C;

    int max_cap = *max_element(A.begin(), A.end());
    vector<vector<int>> dp(B.size() + 1, vector<int>(max_cap+1, 0));
    for(int i= 1 ; i<=max_cap ;i++){
        dp[0][i] = 100000000;
    }
    for(int i =1 ;i <=B.size();i++){
        for(int j =1 ;j <=max_cap ;j++){
            if(dishes_fill[i-1]>j) dp[i][j] = dp[i-1][j] ; 
            else{
                dp[i][j]  = min(dp[i][j-B[i-1]]+C[i-1],dp[i-1][j]) ; 
            }
        }
    }
     int result =0 ; 
    for(int j:A){
        result+=dp[B.size()][j] ;
    }
    return result;
}