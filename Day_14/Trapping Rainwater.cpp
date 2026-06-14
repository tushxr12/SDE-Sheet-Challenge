class Solution
{
public:
    vector<int> findLeftMax(vector<int> &nums,int n)
    {
        vector<int> leftMax(n);
        leftMax[0] = nums[0];

        for(int i = 1;i < n;i++)
            leftMax[i] = max(nums[i], leftMax[i-1]);
        
        return leftMax;
    }

    vector<int> findRightMax(vector<int> &nums, int n)
    {
        vector<int> rightMax(n);
        rightMax[n-1] = nums[n-1];

        for(int i = n-2;i >= 0;i--)
            rightMax[i] = max(nums[i], rightMax[i+1]);
        
        return rightMax;
    }

    int trap(vector<int> &height){
        int n = height.size();
        int total = 0;

        vector<int> leftMax = findLeftMax(height,n);
        vector<int> rightMax = findRightMax(height,n);

        for(int i = 0;i < n;i++)
        {
            if(leftMax[i] > height[i] && rightMax[i] > height[i])
                total += ((min(leftMax[i],rightMax[i])) - height[i]);
        }
        return total;
    }
};

// Optimal
class Solution
{
public:
    int trap(vector<int> &height){
        int n = height.size();
        int total = 0;
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n -1;

        while(left < right)
        {
            if(height[left] <= height[right])
            {
                if(leftMax > height[left])
                {
                    total += (leftMax - height[left]);
                }
                else
                {
                    leftMax = height[left];
                }
                left += 1;
            }
            else
            {
                if(rightMax > height[right])
                {
                    total += (rightMax - height[right]);
                }
                else
                {
                    rightMax = height[right];
                }
                right -= 1;
            }
        }
        return total;
    }
};
