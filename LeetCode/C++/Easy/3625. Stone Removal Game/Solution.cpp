class Solution {
public:
    bool canAliceWin(int n) {
        int step=0;
        int stones=10;
        while(n>=stones){
            n-=stones;
            step++;
            stones--;
        }
        if(step%2==0){
            return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool canAliceWin(int n) {
//         bool alice=true;
//         int stones=10;
//         while(n>=stones){
//             n-=stones;
//             stones--;
//             alice=!alice;
//         }
//         return !alice;
//     }
// };