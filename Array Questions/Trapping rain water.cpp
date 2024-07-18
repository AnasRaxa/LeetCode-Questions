class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int water = 0,maxHeight = height[0],leftMax = 0,rightMax = 0,index = 0;

        for(int i = 1; i<n; i++){
            if(height[i]>maxHeight){
                maxHeight = height[i];
                index = i;
            }
        }


        for(int i = 0; i<index; i++){
            if(leftMax>height[i]){
                water += leftMax - height[i];
            }else{
                leftMax = height[i];
            }
        }

        for(int i = n-1; i>index; i--){
            if(rightMax>height[i]){
                water += rightMax - height[i];
            }else{
                rightMax = height[i];
            }
        }

    return water;
        
    }
};

























class Solution {
public:
    vector<int> getLeftMax(vector<int>& height, int n) {
        vector<int> leftMax(n);
        leftMax[0] = height[0];
        for(int i = 1; i<n; i++) {
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        return leftMax;
    }
    vector<int> getRightMax(vector<int>& height, int n) {
        vector<int> rightMax(n);
        rightMax[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--) {
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        return rightMax;
    } 
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 1 || n == 0)
            return 0;
        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += min(leftMax[i], rightMax[i]) - height[i];
        }
        return sum;
    }
};