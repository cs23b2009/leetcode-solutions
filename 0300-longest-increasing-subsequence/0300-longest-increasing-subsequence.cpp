#define ll long long
#define pb push_back
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        ll n = a.size();
        vector<ll> seq;
        vector<ll> ans;
        for (ll i = 0; i < n; i++) {
            auto it = lower_bound(seq.begin(), seq.end(), a[i]);
            ll idx = it - seq.begin();
            if (it == seq.end()) {
                seq.pb(a[i]);
                ans.pb(i);
            } else {
                seq[idx] = a[i];
                ans[idx] = i;
            }
        }
        return ans.size();
    }
};