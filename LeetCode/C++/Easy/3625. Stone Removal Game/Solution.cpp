// class Solution {
// public:
//     bool canAliceWin(int n) {
//         if(n<10){
//             return false;
//         }
//         int step=1;
//         int A=10;
//         n=n-A;
//         A--;
//         while(n>=A){
//             n=n-A;
//             step++;
//             A--;
//         }
//         if(step%2==0){
//             return false;
//         }
//         return true;
//     }
// };
class Solution {
public:
    bool canAliceWin(int n) {
        bool alice=true;
        int stones=10;
        while(n>=stones){
            n-=stones;
            stones--;
            alice=!alice;
        }
        return !alice;
    }
};