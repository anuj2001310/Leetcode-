class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
     sort(potions.begin(),potions.end());
     int n=potions.size();

     vector<int>ans;
     for(int num:spells){
        int l=0,r=n;
        while(l<r){
            int mid=l+(r-l)/2;

            if((long long)num*(long long)potions[mid]>=success){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans.push_back(n-l);
     }   
     return ans;
    }
};