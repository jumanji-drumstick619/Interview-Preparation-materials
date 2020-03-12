int Solution::adjacent(vector<vector<int> > &A) {
     if(A.size() == 0){
        return 0;
    }
    int incl = max(A[0][0], A[1][0]), excl = 0;
    for(int i = 1; i < A[0].size(); i++){
        int num = max(A[0][i], A[1][i]);
        int temp = incl;
        incl = max(excl + num,temp);
        excl = temp;
    }
    return incl;
}
