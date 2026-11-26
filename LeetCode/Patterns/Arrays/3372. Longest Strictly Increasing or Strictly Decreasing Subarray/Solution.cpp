class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc=1;
        int dec=1;
        int ans=1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                inc++;
            }
            else{
                inc=1;
            }
            ans=max(ans,inc);
            
            //decrement
            if(nums[i]<nums[i-1]){
                dec++;
            }
            else{
                dec=1;
            }
            ans=max(ans,dec);
            
        }
        return ans ;
    }
};