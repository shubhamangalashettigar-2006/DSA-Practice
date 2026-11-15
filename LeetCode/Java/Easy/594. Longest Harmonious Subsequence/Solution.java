class Solution {
    public int findLHS(int[] nums) {
        int ans=0;
        Arrays.sort(nums);
        int l=0;
        int n=nums.length;
        for(int r=0;r<n;r++){
            while(nums[r]-nums[l]>1){
                l++;
            }
            if(nums[r]-nums[l]==1){
                ans=Math.max(ans,r-l+1);
            }
        }
        return ans;
    }
}