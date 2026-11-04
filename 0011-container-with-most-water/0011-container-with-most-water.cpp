class Solution {
public:
    int maxArea(vector<int>& height) {
        int area=0;
        int left=0;
        int right=height.size()-1;
        while(left<right){
            int width=right-left;
            int h=min(height[left],height[right]);
            area=max(area,width*h);
            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return area;
    }
};