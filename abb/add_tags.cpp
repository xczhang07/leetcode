#include <unordered_map>
using namespace std;


// https://www.1point3acres.com/bbs/thread-1110506-1-1.html

就一道coding，我看其他帖子也有重复的原题： tag一段review所有中的关键词


/** 给一个 key word to tag的mapping, 比如
{
"san": "person",
"francisco": "person",
"san francisco": "city",
"Airbnb": "business",

"city": "location",
}
然后给一段Review:
"I travelled to San Francisco for work and stayed at Airbnb.
I really loved the city and the home where I stayed.
I stayed with San and Francisco.
They both were really good and san's hospitality was outstanding."
要求把所有关键词替换成 [<tag>]{<key word>}, 这个例子就返回
"I travelled to [city]{San Francisco} for work and stayed at [business]{Airbnb}.
I really loved the [location]{city} and the home where I stayed.
I stayed with [person]{San} and [person]{Francisco}.
They both were really good and [person]{san}'s hospitality was outstanding."


对于run time 没有特别的要求，但是45分钟 code要能run 并且pass test cases时间还是有点紧张的。我写的是用trie来存所有的key word,然后一边扫review 一边作prefix matching **/

class TrieNode {
public:
    TrieNode() {
        this->isWord = false;
    }
    
    bool checkWord() {
        return this->isWord;
    }
    
    unordered_map<char, TrieNode*>& getChildren() {
        return this->children;
    }
    
    void setWord() {
        this->isWord = true;
    }
    
private:
    bool isWord;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // insert a word into the trie
    void insertWord(const string& word) {
        if(word.size() == 0) {
            return;
        }
        TrieNode* travel = this->root;
        for(char w: word) {
            if(!travel->getChildren().count(w)) {
                travel->getChildren()[w] = new TrieNode();
            }
            travel = travel->getChildren()[w];
        }
        travel->setWord();
    }
    
    // check whether or not an input is a prefix in the trie.
    bool searchPrefix(string& prefix) {
        if(prefix.size() == 0) {
            return false;
        }
        TrieNode* travel = this->root;
        for(char p: prefix) {
            if(!travel->getChildren().count(p)) {
                return false;
            } else {
                travel = travel->getChildren()[p];
            }
        }
        return true;
    }
    
    // check whether or not an input word is a word in the trie.
    bool searchWord(string& word) {
        if(word.size() == 0) {
            return false;
        }
        TrieNode* travel = this->root;
        for(char w: word) {
            if(!travel->getChildren().count(w)) {
                return false;
            } else {
                travel = travel->getChildren()[w];
            }
        }
        return travel->checkWord();
    }
    
private:
    TrieNode* root;
};

string addTags(string review, unordered_map<string, string>& keywordToTag) {
    string ret;
    Trie t;
    // insert all keyword into the trie.
    for(auto [key, _]: keywordToTag) {
        t.insertWord(key);
    }
    // iterate the review and build the new review.
    int start = 0, len = 1;
    while(start < review.size()) {
        string substr = review.substr(start, len);
        if(!t.searchPrefix(substr)) {
            ret += substr;
            start += len;
            len = 1;
        } else {
            while(start+len < review.size() && t.searchPrefix(substr)) {
                len += 1;
                substr = review.substr(start, len);
            }
            string word = review.substr(start, len-1);
            if(start+len >= review.size()) {
                if(t.searchWord(word)) {
                    ret += "["+ keywordToTag[word] +"]"+"{"+ word +"}";
                } else {
                    ret += word;
                }
            } else {
                if(t.searchWord(word)) {
                    ret += "["+ keywordToTag[word] +"]"+"{"+ word +"}";
                } else {
                    ret += word;
                }
                start += (len-1);
                len = 1;
            }
        }
    }
    return ret;
}

#endif /* add_tags_h */
