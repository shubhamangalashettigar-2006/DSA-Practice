class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        
        int maxLen=0;
        for(int i=0;i<n;i++){
            long long prod=1;
            int g=0;
            long long lcm=1;
            for(int j=i;j<n;j++){
                if (prod > 25200LL / nums[j])
                    break;
                prod*=nums[j];
                g=gcd(g,nums[j]);
                lcm=lcm*nums[j]/gcd(lcm,nums[j]);
                if(prod==g*lcm){
                    maxLen=max(maxLen,j-i+1);
                } 
            }
        }
        return maxLen;
    }
};