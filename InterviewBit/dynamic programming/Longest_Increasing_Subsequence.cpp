int Solution::lis(const vector<int> &A) {
    int n = A.size() ;
    vector<int> llength(n,1) ; 
    int maxLen = 1 ; 
    for(int i =  1; i<n;i++){
        for(int  j= 0 ; j<i;j++){
            if(A[j] < A[i]){
                llength[i] = max(llength[i],1+llength[j]) ;

            }
                            maxLen = max(maxLen , llength[i]) ;
        }
    }
    return maxLen ;
}
