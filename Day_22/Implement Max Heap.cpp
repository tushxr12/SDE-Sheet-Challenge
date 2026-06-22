class Solution{
    private:

    vector<int> arr;
    int count;

    void heapifyDown(int index)
    {
        int n = arr.size();
        int largestIndex = index;

        int leftChildIndex = 2*index + 1, rightChildIndex = 2*index + 2;

        if(leftChildIndex < n && arr[leftChildIndex] > arr[largestIndex])
            largestIndex = leftChildIndex;
        
        if(rightChildIndex < n && arr[rightChildIndex] > arr[largestIndex])
            largestIndex = rightChildIndex;

        if(largestIndex != index)
        {
            swap(arr[largestIndex], arr[index]);
            heapifyDown(largestIndex);
        }
        return;
    }

    void heapifyUp(int index)
    {
        int parentIndex = (index - 1)/2;

        if(index > 0 && arr[index] > arr[parentIndex])
        {
            swap(arr[index], arr[parentIndex]);

            heapifyUp(parentIndex);
        }
        return;
    }

    public:

        void initializeHeap(){
            arr.clear();
            count = 0;
        }

        void insert(int key){
            arr.push_back(key);

            heapifyUp(count);
            count += 1;

            return;
        }

        void changeKey(int index, int new_val){
            if(arr[index] < new_val)
            {
                arr[index] = new_val;
                heapifyUp(index);
            }
            else
            {
                arr[index] = new_val;
                heapifyDown(index);
            }
            return;
        }

        void extractMax(){
            int maxEle = arr[0];

            swap(arr[0], arr[count - 1]);

            arr.pop_back();
            count -= 1;

            heapifyDown(0);
        }

        bool isEmpty(){
            return (count == 0);
        }

        int getMax(){
            return arr[0];
        }

        int heapSize(){
            return count;
        }
};
