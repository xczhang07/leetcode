struct Node {
    Node* prev;
    Node* next;
    string val;
    Node(string str):val(str), prev(NULL), next(NULL) {}
};

class BrowserHistory {
public:
    Node* history_list = NULL;
    Node* curr;

    BrowserHistory(string homepage) {
        history_list = new Node(homepage);
        curr = history_list;
    }
    
    void visit(string url) {
        Node* newPage = new Node(url);
        newPage->prev = curr;
        curr->next = newPage;
        curr = newPage;
    }
    
    string back(int steps) {
        while(curr->prev && steps > 0) {
            curr = curr->prev;
            --steps;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next && steps > 0) {
            curr = curr->next;
            --steps;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
