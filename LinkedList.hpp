template <class T>
struct SingleNode {
    T data;
    SingleNode* next = nullptr;
    SingleNode(T data): data(data) {}
    static SingleNode* search(SingleNode* node, T data) {
        while (node != nullptr && node->data != data) {
            node = node->next;
        }
        return node;
    }
    static SingleNode* searchPrev(SingleNode* node, T data) {
        SingleNode* prev = nullptr;
        while (node != nullptr && node->data != data) {
            prev = node;
            node = node->next;
        }
        return prev;
    }
    static void insert(SingleNode* node, T data, T newData) {
        node = search(node, data);
        SingleNode* temp = node->next;
        node->next = new SingleNode(newData);
        node->next->next = temp;
    }
    static SingleNode* deleteNode(SingleNode* node, T data) {
        SingleNode* prev = searchPrev(node, data);
        if (prev == nullptr) {
            SingleNode* next = node->next;
            delete node;
            return next;
        }
        SingleNode* temp = prev->next->next;
        delete prev->next;
        prev->next = temp;
        return node;
    }
};

template <class T>
struct DoubleNode {
    T data;
    DoubleNode* prev = nullptr;
    DoubleNode* next = nullptr;
    DoubleNode(T data): data(data) {}
};