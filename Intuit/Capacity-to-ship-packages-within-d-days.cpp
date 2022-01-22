class Solution {
public:
    int helper(vector<int>& weights,int cap)
    {
        int curr=0;
        int res=1;
        for(auto w:weights)
        {
            curr+=w;
            if(curr>cap)
            {
                ++res;
                curr=w;
            }
        }
        return res;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l=*max_element(weights.begin(),weights.end());
        int r = accumulate(weights.begin(),weights.end(),0);
        while(l<r)
        {
            int m = (l+r)/2;
            if(helper(weights,m)<=days)
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        return l;
    }
};
