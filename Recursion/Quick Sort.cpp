class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        
        if(low>high) return;
        
        // 1-	We have to find a pivot and sort it in that way that all elements on left side are smaller than it and all the elements on right side are larger than it – for example assembly line
        
        int p = partition(arr,low,high);  // partition will return pivot fater sorting 
        
        // after finding pivot we have to sort its left and right side
        
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
        
        
        
        
        
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       
       int pivot = arr[low];
       
       int i = low+1;
       int j = high;
       
       
       while(true){
           
           while(arr[i]<=pivot && i<=j)i++;
           while(arr[j]>=pivot && j>=i)j--;
           
           
           if(i>j) break;
           else{
               swap(arr[i],arr[j]);
           }

       }
       
       
       swap(arr[low],arr[j]);
       
       return j;
       
       
       
       
    }
};

















class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        
        if(low>high) return;
        
        // 1-	We have to find a pivot and sort it in that way that all elements on left side are smaller than it and all the elements on right side are larger than it – for example assembly line
        
        int p = partition(arr,low,high);  // partition will return pivot fater sorting 
        
        // after finding pivot we have to sort its left and right side
        
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
        
        
        
        
        
        
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
       // Your code here
       
       
       int pivot = arr[high];
       
       
       int pi = low; // consider low as pivot
       
       
       for(int j = low; j<high; j++){
           
           if(arr[j]<pivot){
               swap(arr[j],arr[pi]);
               pi++;
           }
           
       }
       
       
       swap(arr[high],arr[pi]);
       
       return pi;
       
       
       
       
       
       
       
       
       
       
    }
};
