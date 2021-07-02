class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int >ans;
        int num=0;
        ans.push_back(0);
        for(int k=0;k<n;k++)
        {
            int i=pow(2,k);
            if(ans.size()!=0)
            {
                int j=ans.size()-1;
               for(;j>=0;j--)
               {
                   ans.push_back(ans[j]+i);
               }
            }
        }
        
//         for(int i=0;i<n;i++)
//         {
//             if(i==0)
//             {
                
//                 num=num<<1;
//                 num=1<<0 | num;
//                 ans.push_back(num);
//             }
//             else
//             {
//                 num=num &(num<<1);
//                 ans.push_back(num);
//             }
//         }
        return ans;
    }
};