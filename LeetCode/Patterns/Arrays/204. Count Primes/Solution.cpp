class Solution {
public:
    int countPrimes(int n) {
        int cnt=0;
        for(int i=2;i<n;i++){
            for(int j=2;j<i;j++){
                if(i%j==0){
                    break;
                }
                if(j==i){
                cnt++;
            }
            }
            

        }
        return cnt;
    }
};