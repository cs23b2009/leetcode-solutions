class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b)
    {

        if(a[0]!=b[0]) return a[0]<b[0];
        if(a[1]!=b[1]) return a[1]<b[1];
         
        return a[2]<b[2];
    }

    int findub(vector<int> &nums, int target)
    {
        int lo=0;
        int hi = nums.size()-1;
        int ans= nums.size();
        while(lo<=hi)
        {
            int mid = (lo+hi)/2;
            if(nums[mid]>target)
            {
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin(),events.end(),comp);
        int n = events.size();


        vector<pair<int,int>> v(n,{0,0});
        vector<int> bin(n,0);
        int mxval =0;
        for(int i=n-1;i>=0;i--)
        {
            v[i].first = events[i][0];
            bin[i]=events[i][0];
            mxval = max(events[i][2],mxval);
            v[i].second = mxval;
        }


        int ans=0;
        for(int i=0;i<n;i++)
        {
            int val1 = events[i][2];
            int st = events[i][0]; int end = events[i][1];

            int lb = findub(bin,end);
            if(lb==n){ //no valid interval found on right side
                ans = max(ans,val1);
            }else{
                ans = max(ans,val1+v[lb].second);
            }
        }

        return ans;
    }
};