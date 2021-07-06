class Solution {
public:
    
    int SearchBinary(vector<int>v ,int s,int e,int x)
    {
        if(s>=e)
        {
            return s;
        }
        int mid=(s+e)/2;
        
        if(v[mid]==x)
        {
            return mid;
        }
        if(v[mid]<x)
        {
            int Ind=SearchBinary(v,mid+1,e,x);
                return Ind;
        }
        else
        {
            int Ind=SearchBinary(v,s,mid-1,x);
            return Ind;
        }
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>ans;
        int n=arr.size();
        int Index=SearchBinary(arr,0,n-1,x);
        cout<<Index<<endl;
        if(arr[Index]!=x)
        {
            if(Index!=0)
            {
                if(abs(arr[Index]-x)>abs(arr[Index-1]-x))
                {
                    Index--;
                }
                if(abs(arr[Index]-x)==abs(arr[Index-1]-x))
                {
                    if(arr[Index]>arr[Index-1])
                    {
                        Index--;
                    }
                }
            }
            else if(Index!=n-1)
            {
                if(abs(arr[Index]-x)>abs(arr[Index+1]-x))
                {
                    Index++;
                }
                if(abs(arr[Index]-x)==abs(arr[Index+1]-x))
                {
                    if(arr[Index]>arr[Index+1])
                    {
                        Index++;
                    }
                }
            }
        }
        int i=Index-1;
        int j=Index+1;
        
        //cout<<i<<" "<<j<<"\n";
        k--;
        //cout<<k<<"\n";
        
        while(k>0 && i>=0 && j<n)
        {
            if(abs(arr[i]-x)<abs(arr[j]-x))
            {
                i--;
                k--;
                continue;
            }
            else if( abs(arr[i]-x)>abs(arr[j]-x))
            {
                j++;
                k--;
                continue;
            }
            else if(abs(arr[i]-x)==abs(arr[j]-x))
            {
                if(arr[i]>arr[j])
                {
                    j++;
                    k--;
                }else
                {
                    i--;
                    k--;
                }
            }
            
        }
        //cout<<j<<endl;
        
        if(i<0 && k>0 && j<n)
        {
            while(k>0)
            {   j++;
                k--;
            }
        }
        
        
        if(j==n && k>0 && i>=0)
        {
            while(k>0)
            {    
                i--;
                k--;
            }
        }
        
        i++;
       
        for(;i<j;i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};