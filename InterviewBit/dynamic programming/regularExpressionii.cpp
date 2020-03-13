int Solution::isMatch(const string A, const string B) {
    int len1=A.size();
    int len2=B.size();
    bool arr[len1+1][len2+1];
    arr[0][0]=true;
    arr[0][1]=false;
    for(int i=2;i<=len2;i++){
        if(B[i-1]=='*'){
            arr[0][i]=arr[0][i-2];
        }
    }
    for(int i=1;i<=len1;i++){
        arr[i][0]=false;
    }
    
    for(int i=1;i<=len1;i++){
        for(int j=1;j<=len2;j++){
            if(B[j-1]=='.' or A[i-1]==B[j-1]){
                arr[i][j]=arr[i-1][j-1];
            }
            else if(B[j-1]=='*'){
                arr[i][j]=arr[i][j-2];
                if(A[i-1]==B[j-2] or B[j-2]=='.'){
                    arr[i][j]=arr[i][j] || arr[i-1][j];
                }
            }
            else arr[i][j]=false;
        }
    }
    return arr[len1][len2];
}
