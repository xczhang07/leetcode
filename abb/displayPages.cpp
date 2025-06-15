https://www.1point3acres.com/bbs/forum.php?mod=viewthread&tid=290914

vector<string> displayPages(vector<string> input, int num)
{
    vector<string> pages;
    if(input.size() == 0)
        return pages;
    vector<string>::iterator iter = input.begin();
    unordered_set<int> s;
    int cnt = 0;
    while(iter != input.end())
    {
        string log = *iter;
        int idx = 0;
        int host_id = 0;
        while(idx < log.size() && isdigit(log[idx]))
        {
            host_id = host_id * 10 + (log[idx]-'0');
            ++idx;
        }
        if(cnt < num && !s.count(host_id))
        {
            pages.push_back(*iter);
            cnt++;
            s.insert(host_id);
            iter = input.erase(iter);
        }
        else if(cnt < num && s.count(host_id))
            iter++;
        
        if(cnt == num)
        {
            cnt = 0;
            s.clear();
            if(input.size() != 0)
                pages.push_back(" ");
            iter = input.begin();
        }
        
        if(iter == input.end())
        {
            iter = input.begin();
            s.clear();
        }
    }
    
    return pages;
}

// test code
int main()
{
     vector<string> input = {
        "1,28,310.6,SF",
        "4,5,204.1,SF",
        "20,7,203.2,Oakland",
        "6,8,202.2,SF",
        "6,10,199.1,SF",
        "1,16,190.4,SF",
        "6,29,185.2,SF",
        "7,20,180.1,SF",
        "6,21,162.1,SF",
        "2,18,161.2,SF",
        "2,30,149.1,SF",
        "3,76,146.2,SF",
        "2,14,141.1,San Jose"
    };
    
    vector<string> pages = displayPages(input, 4);
    
    for(int i = 0; i < pages.size(); ++i)
    {
        if(pages[i] != " ")
            cout<<pages[i]<<endl;
        else
            cout<<endl;
    }
    cout<<endl;
    return 0;
}

// Solution 2, using linkedlist to iterate 
//
//  display_pages.h
//  AirbnbCodingChallenge
//
//  Created by Xiaochong Zhang on 6/14/25.
//

#ifndef display_pages_h
#define display_pages_h
#include<string>
#include<vector>
#include<iostream>
#include<unordered_set>
using namespace std;

class ListNode {
public:
    ListNode(string val) {
        this->val = val;
        this->next = NULL;
    }
    string val;
    ListNode* next;
};

class LinkedList {
public:
    LinkedList() {
        this->head = NULL;
    }
    // insert a new node from tail.
    void pushBack(string val) {
        if(head == NULL) {
            ListNode* newHead = new ListNode(val);
            head = newHead;
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* travel = head;
        while(travel->next) {
            travel = travel->next;
        }
        travel->next = newNode;
    }
    // get the length of the linkedlist
    int getLen() {
        ListNode* travel = head;
        if(!travel) {
            return 0;
        }
        int len = 0;
        while(travel) {
            len += 1;
            travel = travel->next;
        }
        return len;
    }
    
    bool empty() {
        if(getLen() == 0) {
            return true;
        }
        return false;
    }
    
    // delete a node from the linked list
    void remove(string val) {
        if(getLen() == 0) {
            return;
        }
        if(head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
            return;
        }
        ListNode* travel = head->next;
        ListNode* prev = head;
        while(travel and travel->val != val) {
            travel = travel->next;
            prev = prev->next;
        }
        if(travel == NULL) {
            return;
        }
        prev->next = travel->next;
        delete travel;
        return;
    }
    
    ListNode* getHead() {
        return this->head;
    }
    
private:
    ListNode* head;
};

vector<vector<string>> page(vector<string>& input, int num) {
    if(input.size() == 0) {
        return {};
    }
    // build a linked list based on the input.
    LinkedList myList;
    for(string log: input) {
        myList.pushBack(log);
    }
    unordered_set<int> host_ids;
    vector<vector<string>> ret;
    int cnt = 0;
    while(!myList.empty()) {
        ListNode* tmp = myList.getHead();
        vector<string> singlePage;
        cnt = 0;
        while(tmp) {
            string log = tmp->val;
            int host_id = 0;
            int idx = 0;
            while(idx < log.size() and isdigit(log[idx])) {
                host_id = host_id*10 + (log[idx]-'0');
                idx += 1;
            }
            if(!host_ids.count(host_id)) {
                singlePage.push_back(log);
                tmp = tmp->next;
                myList.remove(log);
                cnt += 1;
                host_ids.insert(host_id);
            } else {
                tmp = tmp->next;
            }
            if(cnt == num) {
                ret.push_back(singlePage);
                host_ids.clear();
                break;
            }
            if(tmp == NULL) {
                host_ids.clear();
                tmp = myList.getHead();
            }
        }
        if(cnt < num) {
            ret.push_back(singlePage);
        }
    }
    return ret;
}


#endif /* display_pages_h */

