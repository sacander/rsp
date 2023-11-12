template <class T>
struct SingleNode {
    T data;
    SingleNode* next = nullptr;
    SingleNode(T data): data(data) {}
};

template <class T>
struct DoubleNode {
    T data;
    DoubleNode* prev = nullptr;
    DoubleNode* next = nullptr;
    DoubleNode(T data): data(data) {}
};