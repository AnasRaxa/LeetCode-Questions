class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         
         int k = l;
         int i = l;
         int j = m+1;
         
         int temp[l+r];
         
         while(i<=m && j<=r){
             
             if(arr[i]<arr[j]){
                 temp[k++] = arr[i++];
             }else{
                 temp[k++] = arr[j++];
                 
             }
             
         }
         
         while(i<=m){
             temp[k++] = arr[i++];
         }
         while(j<=r){
             temp[k++] = arr[j++];
         }
         
         for(int i = l; i<=r; i++){
             
             arr[i] = temp[i];
             
         }
         
         
    }
    public:
    
    
    
    
    
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        
        if(l>=r) return;
        
        
        int mid = (l+r)/2;
        
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        
        merge(arr,l,mid,r);
        
        
    }
};