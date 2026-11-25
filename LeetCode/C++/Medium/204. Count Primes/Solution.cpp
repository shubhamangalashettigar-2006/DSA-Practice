class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        int cnt=0;
        for(int i=2;i<n;i++){
            bool prime=true;
            for(int j=2;j<=i/j;j++){
                if(i%j==0){
                    prime=false;
                    break;
                }
                if(prime){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};