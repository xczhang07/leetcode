class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
       if(croakOfFrogs.size()%5 != 0) {
           return -1;
       }
       const string kCroak = "croak";
       vector<int> count(5,0);
       int frog_num = 0;
       int ret = 0;
       for(const char& c : croakOfFrogs) {
           ++count[kCroak.find(c)];
           for(int i = 1; i < 5; ++i) {
               if(count[i] > count[i-1]) {
                   return -1;
               }
           }
           if(c == 'c') {
               frog_num++;
           }
           if(c == 'k'){
               frog_num--;
           }
           ret = max(ret, frog_num);
       }
       return frog_num == 0? ret: -1;
    }
};


Below is the solution to resolve the repeated charactors with backtracking 
bool valid(map<int, int>& progress) {
  int i = 0;
  int preFreq = 0;
  for (auto entry : progress) {
    if (i == 0) {
      preFreq = entry.second;
    } else {
      if (entry.second > preFreq) {
        return false;
      } else {
        preFreq = entry.second;
      }
    }
    ++i;
  }
  return true;
}

void dfs(const string& sounds, const string& oneWord, int i,
         map<int, int>& progress, int currCount, int currMax,
         int& ret, bool& isValid, unordered_map<char, vector<int>>& idxMap) {
  if (i == sounds.size()) {
    ret = min(ret, currMax);
    return;
  }
  if(!isValid) {
    return;
  }
  if(!idxMap.count(sounds[i])) {
    isValid = false;
    return;
  }
  vector<int> idx = idxMap[sounds[i]];
  for(int j : idx) {
    progress[j] += 1;
    int tmp = currMax;
    if(valid(progress)) {
      if(j == 0) {
        currCount++;
      } else if (j == oneWord.size()-1) {
        currCount--;
      }
        currMax = max(currMax, currCount);
      dfs(sounds, oneWord, i + 1, progress, currCount, currMax, ret,
          isValid, idxMap);
        
    } else {
        currMax = tmp;
    }
    progress[j] -= 1;
  }
}

int minNumberOfFrogs(string soundOfFrogs) {
    string kCroak = "roblox";
    // Perform some quick check.
    if(soundOfFrogs.size() % kCroak.size() != 0) {
        return -1;
    }
    int rep = soundOfFrogs.size()/kCroak.size();
    vector<int> freqAll(26,0);
    vector<int> freqOne(26,0);
    for(char c: soundOfFrogs) {
        freqAll[c-'a']++;
    }
    for(char c: kCroak) {
        freqOne[c-'a']++;
    }
    for(int i = 0; i < 26; ++i) {
        if(freqOne[i]*rep != freqAll[i]) {
            return -1;
        }
    }
    // create idx map.
    unordered_map<char, vector<int>> idxMap;
    map<int, int> progress;
    for(int i = 0; i < kCroak.size(); ++i) {
        idxMap[kCroak[i]].push_back(i);
        progress[i] = 0;
    }
    int currMax = 0;
    int ret = INT_MAX;
    bool valid  =true;
    dfs(soundOfFrogs, kCroak, 0, progress, 0, currMax, ret, valid, idxMap);
    if (!valid || ret == INT_MAX) {
        return -1;
    }
    return ret;
  }
