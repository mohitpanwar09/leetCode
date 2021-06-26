
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

class Solution {
public:
    
#define ll long long int
#define bb "\n"

// *** this orderset store duplicate value *** //
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>rev;
        ordered_set fre;
        vector<int>ans;
        for(int i=nums.size()-1;i>=0;i--)
        {
            fre.insert(nums[i]);
            rev.push_back(fre.order_of_key(nums[i]));
        }
        for(int i=rev.size()-1;i>=0;i--)
        {
            ans.push_back(rev[i]);
        }
        return ans;
    }
};