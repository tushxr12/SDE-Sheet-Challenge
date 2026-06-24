class ArrayStack {
private:
    int* stackArray;
    int capacity;
    int topIndex;
public:
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack()
    {
        delete[] stackArray;
    }
    
    void push(int x) {
        if(topIndex >= capacity - 1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        topIndex++;
        stackArray[topIndex] = x;
    }
    
    int pop() {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return stackArray[topIndex--];
    }
    
    int top() {
        if(isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return stackArray[topIndex];
    }
    
    bool isEmpty() {
        return (topIndex == -1);
    }
};
