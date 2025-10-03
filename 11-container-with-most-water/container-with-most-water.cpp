class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int b = 0;
        int h = INT_MAX;
        int area = 0;
        while(l <= r)
        {
            h = min(height[l],height[r]);
            b = r - l;
            area = max(area,h*b);

            if(height[l] < height[r]) l++;
            else r--;
        }
        return area;
    }
};