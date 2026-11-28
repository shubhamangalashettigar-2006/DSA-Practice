class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        long sum=0;
        int ans=0;
        sort(nums.begin(),nums.end());
        int right=0;
        int left=0;
        while(right<n){
            sum+=nums[right];
            long opr=nums[right]*(right-left+1)-sum;
            while(opr>k){
                sum-=nums[left];
                left++;
                opr=nums[right]*(right-left+1)-sum;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};