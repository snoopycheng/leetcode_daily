class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long sum=0;
        int notzeroindex=-1;

        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                sum += i-notzeroindex;
            }
            else{
                notzeroindex=i;
            }
        }
        return sum;
    }
};