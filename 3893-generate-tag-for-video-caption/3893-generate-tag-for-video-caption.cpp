 class Solution {
public:
    string generateTag(string caption) {
        vector<string> words;
        string word, tag = "#";
        for (char c : caption) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else if (isalpha(c)) {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);

        for (int i = 0; i < words.size(); ++i) {
            string& w = words[i];
            for (char& c : w) c = tolower(c);
            if (i > 0 && !w.empty()) w[0] = toupper(w[0]);
            tag += w;
        }

        if (tag.length() > 100) tag = tag.substr(0, 100);
        return tag;
    }
};