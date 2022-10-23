struct trie{
    trie *word[26];
    bool endofword;
    trie(){
        endofword = false;
        for(int i=0; i<26; i++){
            word[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    trie *root = new trie();
    WordDictionary() {
        
    }
    
    void addWord(string s) {
        trie *node = root;
        for(int i=0; i<s.size(); i++){
            int idx = s[i] - 'a';
            if(!node->word[idx]){
                node->word[idx] = new trie();
            }
            node = node->word[idx];
        }
        node->endofword = true;
    }
    
    bool search(string s) 
    {
       return search(s.c_str(), root);
    }
    
    bool search(const char* s, trie* node) {
        for (int i = 0; s[i] && node; i++) {
            if (s[i] != '.') {
                node = node -> word[s[i] - 'a'];
            } else {
                trie* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> word[j];
                    if (search(s + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> endofword;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */