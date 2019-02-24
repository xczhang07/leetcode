struct ListNode
{
    ListNode(int size = 5)
    {
        capacity = size;
        this->next = NULL;
    }
    
    int add(int num)
    {
        if(nums.size() == this->capacity)
            return -1;
        nums.push_back(num);
        return 0;
    }
    
    void remove()
    {
        if(nums.size() == 0)
            return;
        auto top = nums.begin();
        nums.erase(top);
        return;
    }
    
    vector<int> nums;
    int capacity;
    ListNode* next;
};

class LimitedSizeQueue
{
public:
    LimitedSizeQueue(int limitedSize)
    {
        this->head = NULL;
        this->tail = NULL;
        this->size = limitedSize;
        this->cnt = 0;
    }
    
    void push(int val)
    {
        if(this->head == NULL)
        {
            ListNode* newNode = new ListNode(this->size);
            head = newNode;
            tail = newNode;
            tail->add(val);
            cnt++;
            return;
        }
        else
        {
            if(tail->add(val) == -1)
            {
                ListNode* newNode = new ListNode(this->size);
                newNode->add(val);
                tail->next = newNode;
                tail = tail->next;
            }
            cnt++;
            return;
        }
    }

    int front()
    {
        if(head == NULL && tail == NULL)
            return -1;
        return *head->nums.begin();
    }
    
    int pop()
    {
        if(head == NULL && tail == NULL)
            return -1;
        int top = *head->nums.begin();
        head->remove();
        if(head->nums.size() == 0)
        {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        --cnt;
        return top;
    }
    
    int getSize()
    {
        return this->cnt;
    }
    
    bool empty()
    {
        return cnt == 0;
    }
    
private:
    ListNode* head;
    ListNode* tail;
    int size;
    int cnt;
};


int main()
{
    cout<<"myQueue's size is: "<<myQueue.getSize()<<endl;
    
    while(!myQueue.empty())
    {
        cout<<myQueue.front()<<" ";
        myQueue.pop();
    }
    cout<<endl;
  return 0;
}
