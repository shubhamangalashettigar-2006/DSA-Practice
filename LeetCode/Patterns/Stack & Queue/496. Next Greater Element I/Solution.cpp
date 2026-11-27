class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       int n=nums2.size();
       vector<int> ans(n,-1);
       vector<int> res(nums1.size(),-1);
       stack<int> st;
       for(int i=n-1;i>=0;i--){
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top();
            }
            st.push(nums2[i]);
       }
       for(int i=0;i<nums1.size();i++){
        int j=0;
        while(nums1[i]!=nums2[j]){
            j++;
        }
        res[i]=ans[j];
       }
       return res;
    }
};