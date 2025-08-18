class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;

        for(int c : cards){
            nums.push_back((double)c);
        }

        return recursive(nums);
    }
 
    bool recursive(vector<double>& nums){
        int n=nums.size();
        
        if(n==1){
            return abs(nums[0] - 24) < 1e-6;
        }
 
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j){
                    continue;
                }
 
                vector<double> next;
    
                for(int k=0; k<n; k++) {
                    if(k!=i && k!=j) {
                        next.push_back(nums[k]);
                    }
                }
    
                for(int l=0; l<4; l++) {
                    
                    if((l==0 || l==1) && i>j){
                        continue;
                    }
    
                    double ans;
                    if(l==0){
                        ans=nums[i]+nums[j];
                    }
                    else if(l==1){
                        ans=nums[i]*nums[j];
                    }
                    else if(l==2){
                        ans=nums[i]-nums[j];
                    }
                    else{
                        ans=nums[i]/nums[j];
                    }
        
                    next.push_back(ans);
                    
                    if(recursive(next)){
                        return true;
                    }
        
                    next.pop_back();
                }      
            }
        }  
        return false;
    }
 };