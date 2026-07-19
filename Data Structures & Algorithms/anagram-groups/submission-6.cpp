class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        // for every word, make a key for it and add it to the corresponding list of anagrams
        for (auto str : strs) {
            vector<int> count(26, 0);
            
            // for each character in the word, make a distinct key
            for (char c : str) {
                count[c - 'a']++;
            }
            string key = "";

            for (int c : count) {
                (key.append(to_string(c))).append(",");
            }

            // add the string to the corresponding list in the hashmap
            groups[key].push_back(str);
        }
        
        // combine all anagram pairs into a list of grouped anagrams
        vector<vector<string>> result;
        for (auto pair : groups) {
            result.push_back(pair.second);
        }
        return result;
    }
};