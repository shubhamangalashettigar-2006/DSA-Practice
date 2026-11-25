class Solution {
    public boolean isPalindrome(int x) {
        int rev=0;
        int t=x;
        if(x<0){
            return false;
        }
        while(t!=0){
            int dig=t%10;
            rev=rev*10+dig;
            t=t/10;
        }
        if(x==rev){
            return true;
        }
    return false;
    }
}