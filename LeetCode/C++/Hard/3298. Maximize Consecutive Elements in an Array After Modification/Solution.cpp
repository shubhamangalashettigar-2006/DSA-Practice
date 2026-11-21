class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int res=0;
        unordered_map<int,int> seq;
        sort(nums.begin(),nums.end());
        for(int x:nums){
            seq[x+1]=max(seq[x+1],seq[x]+1);
            seq[x]=max(seq[x],seq[x-1]+1);
            res=max({res,seq[x],seq[x+1]});
        }
        return res;
    }
    
};