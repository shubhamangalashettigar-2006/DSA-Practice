class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum=1;
        for(int i=2;i<=num/i;i++){
            if(num%i==0){
                sum+=i;
                if(i!=num/i){
                    sum+=num/i;
                }
            }
        }
        return sum==num;
    }
};