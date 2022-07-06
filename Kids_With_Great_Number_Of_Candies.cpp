class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> extra=candies;
        vector<bool> v;
        int n=candies.size();
        
        sort(extra.begin(),extra.end());
        
        for(int i=0;i<n;i++)
        {
            if(candies[i]+extraCandies>=extra[n-1])
            {
                v.push_back(true);
                
            }
            else
                v.push_back(false);
        }
        return v;
    }
};