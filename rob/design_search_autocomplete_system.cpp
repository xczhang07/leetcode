class TrieNode {
public:
    unordered_map<char, TrieNode*> kids;
    int count;
    string sentence;
    vector<TrieNode*> hotNodes;

    TrieNode() {
        this->count = 0;
        this->sentence = "";
    }

        // Customize the node comparision.
    static bool compare(TrieNode*& node1, TrieNode*& node2) {
        if(node1->count == node2->count) {
            return node1->sentence < node2->sentence;
        } else {
            return node1->count > node2->count;
        }
    }

    // update the hotNodes vec.
    void updateHotNodes(TrieNode* node) {
        if(find(hotNodes.begin(), hotNodes.end(), node) == hotNodes.end()) {
            hotNodes.push_back(node);
        }
        sort(hotNodes.begin(), hotNodes.end(), compare);
        if(hotNodes.size() > 3) {
            hotNodes.pop_back();
        }
        return;
    }
};

class AutocompleteSystem { 
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        // Construct the auto-complete system.
       this->root = new TrieNode();
       this->currQuery = "";
       this->currNode = root;
       for(int i = 0; i < sentences.size(); ++i) {
            this->insert(sentences[i], times[i]);
       }
    }

    void insert(string sentence, int count) {
        TrieNode* travel = this->root;
        vector<TrieNode*> visited;
        for(char c: sentence) {
            if(!travel->kids.count(c)) {
                travel->kids[c] = new TrieNode();
            }
            travel = travel->kids[c];
            visited.push_back(travel);
        }
        travel->sentence = sentence;
        travel->count += count;
        for(TrieNode* node: visited) {  
            node->updateHotNodes(travel);
        }
    }
    
    vector<string> input(char ch) {
        // special charactor '#'.
        vector<string> hotQueries;
        if(ch == '#') {
            insert(currQuery, 1);
            this->currQuery = "";
            this->currNode = root;
            return hotQueries;
        }
        currQuery.push_back(ch);
        if(currNode != NULL) {
            if(currNode->kids.count(ch)) {
                currNode = currNode->kids[ch];
            } else {
                currNode = NULL;
            }
        }
        /*if(currNode != NULL) {
            currNode = currNode->kids[ch]; <--- Bug line, once using the subscript operator [], the map will automatically create the key even if it doesn't exist.
        }*/
        if(currNode == NULL) {
            return hotQueries;
        }
        for(TrieNode* hotNode: currNode->hotNodes) {
            hotQueries.push_back(hotNode->sentence);
        }
        return hotQueries;
    }

private:
    TrieNode* root;
    TrieNode* currNode;
    string currQuery;
};


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
