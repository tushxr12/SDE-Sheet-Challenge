 class Solution {
public:
    int countStudents(vector<int> &nums, int pages)
    {
        int n = nums.size();

        int students = 1;
        int pagesStudent = 0;

        for(int i = 0;i < n;i++)
        {
            if(pagesStudent + nums[i] <= pages)
            {
                pagesStudent += nums[i];
            }
            else
            {
                students += 1;
                pagesStudent = nums[i];
            }
        }
        return students;
    }

    int findPages(vector<int> &nums, int m)  {
        int n = nums.size();

        if(m > n)
            return -1;
        
        int low = *max_element(begin(nums), end(nums));
        int high = accumulate(begin(nums), end(nums), 0);

        for(int pages = low; pages <= high;pages++)
        {
            if(countStudents(nums, pages) <= m)
                return pages;
        }
        return low;
    }
};
