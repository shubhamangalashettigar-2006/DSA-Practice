// class Solution {
// public:
//     int countPrimes(int n) {
//         if(n<=2){
//             return 0;
//         }
//         int cnt=0;
//         for(int i=2;i<n;i++){
//             bool prime=true;
//             for(int j=2;j<=i/j;j++){
//                 if(i%j==0){
//                     prime=false;
//                     break;
//                 }
//             }
//             if(prime){
//                 cnt++;
//             }
//         }
//         return cnt;
//     }
// };
//This won't get submit becuase time limit will  exceed for big nubers

//************
//Sieve of Eratosthenes this algorithm we have to use

class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }
        vector<bool> prime(n,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=(n-1)/i;i++){
            if(prime[i]){
                for(int j=i*i;j<n;j+=i){
                    prime[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(prime[i]){
                cnt++;
            }
        }
        return cnt;
    }
};
