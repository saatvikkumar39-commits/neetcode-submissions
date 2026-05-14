class LRUCache {
public:
    class Node{
        public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int x,int y){
            key=x;value=y;
            next=nullptr;
            prev=nullptr;
        }
    };
    Node* head;
    Node* tail;
    int size;
    int cap;
    unordered_map<int, Node*> hash;
    LRUCache(int capacity) {
        cap=capacity;
        size=0;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(hash.find(key)==hash.end()) return -1;
        Node* node=hash[key];
        node->prev->next=node->next;
        node->next->prev=node->prev;
        insertFront(node);
        return node->value;
    }
    void insertFront(Node* node){
        node->next=head->next;
        node->prev=head;
        head->next=node;
        node->next->prev=node;
    }
    void deleteBack(){
        tail->prev=tail->prev->prev;
        tail->prev->next=tail;
    }
    void put(int key, int value) {
        if(hash.find(key)==hash.end()){
            Node* node=new Node(key,value);
            hash[key]=node;
            insertFront(node);
            if(size>=cap){
                hash.erase(tail->prev->key);
                deleteBack();
            }
            else size++;
        }
        else{
            Node* node=hash[key];
            node->prev->next=node->next;
            node->next->prev=node->prev;
            insertFront(node);
            node->value=value;
        }
    }
};
