using namespace std;

class Stack {
    int TOP;
    int* arr;
    int size;
public:
    
    Stack(int capacity) {
        arr = new int[capacity];
        TOP = -1;
        size = capacity;
    }

    void push(int num) {
        if(TOP != size-1){
            TOP++;
            arr[TOP] = num;
        }
        return;
    }

    int pop() {
        int data;
        if(TOP != -1){
            data = arr[TOP];
            TOP--;
        }
        else data = -1;
        return data;
    }
    
    int top() {
        if(TOP != -1) return arr[TOP];
        return TOP;
    }
    
    int isEmpty() {
        return TOP == -1;
    }
    
    int isFull() {
        return (TOP == size-1);
    }
    
};
