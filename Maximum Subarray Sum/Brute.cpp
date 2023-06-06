#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    long long maxi=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            long long sum=0;
            for(int k=i;k<=j;k++){
                sum+=arr[k];
            }
            maxi=max(maxi, sum);
        }
    }
    return maxi;
}