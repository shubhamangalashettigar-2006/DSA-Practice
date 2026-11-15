class Solution {
    public int minimumDifference(int[] nums, int k) {
        int res=Integer.MAX_VALUE;
        int left=0;
        int n=nums.length;
        Arrays.sort(nums);
        for(int right=0;right<=n-k;right++){
            int diff=nums[right+k-1]-nums[left];
            res=Math.min(res,diff);
            left++;
        }
        return res;
    }
}