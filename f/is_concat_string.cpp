Onsite the 1st round 2nd question of this post : https://www.1point3acres.com/bbs/thread-1065729-1-1.html
// Meta
bool isConcatHelper(string sentence, unordered_set<string> words) {
    if(sentence.size() == 0 && words.size() == 0) {
        return true;
    }
    string word;
    for(int i = 0; i < sentence.size(); ++i) {
        word.push_back(sentence[i]);
        if(words.count(word)) {
            words.erase(word);
            if(isConcatHelper(sentence.substr(i+1), words)) {
                return true;
            }
        }
    }
    return false;
}

bool isConcat(string sentence, vector<string>& words) {
    unordered_set<string> wordSet(words.begin(), words.end());
    return isConcatHelper(sentence, wordSet);
}
