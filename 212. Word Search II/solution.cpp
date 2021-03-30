struct TrieNode {
    TrieNode() {
        children = vector<TrieNode*>(26, NULL);
        word = "";
    };
    vector<TrieNode*> children;
    string word;
};

struct Trie {
    TrieNode* root;
    Trie(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++) {
            TrieNode* head = root;
            for (int j = 0; j < words[i].size(); j++) {
                if (head->children[words[i][j] - 'a'] == NULL) {
                    head->children[words[i][j] - 'a'] = new TrieNode();
                }
                head = head->children[words[i][j] - 'a']; 
            } 
            head->word = words[i];
        }
    };
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie(words);
        TrieNode* root = trie.root;
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {        
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string>& result) {
        char c = board[i][j];
        if (c == '#' || root->children[c - 'a'] == NULL) { return; }
        TrieNode* currentNode = root->children[c - 'a'];
        board[i][j] = '#';
        
        if (currentNode->word.size() != 0) { 
            result.push_back(currentNode->word); 
            board[i][j] = c; 
            currentNode->word = "";
        } 
        
        // left
        if (j - 1 >= 0) {
            dfs(board, i, j - 1, currentNode, result);
        }

        // right
        if (j + 1 < board[i].size()) {
            dfs(board, i, j + 1, currentNode, result);
        }

        // top
        if (i - 1 >= 0) {
            dfs(board, i - 1, j, currentNode, result);
        }

        // bottom
        if (i + 1 < board.size()) {
            dfs(board, i + 1, j, currentNode, result);
        }

        board[i][j] = c;
    }
};
