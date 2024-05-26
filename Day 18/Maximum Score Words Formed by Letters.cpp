// Hard (But Medium)
// https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/?envType=daily-question&envId=2024-05-24

// Aproach 1 using Bit Manioulatiin

class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        int n = words.size();
        unordered_map<char, int> lettersMap;
        vector<int> scoreMap(26, 0);

        // Fill lettersMap with frequencies of letters
        for (char ch : letters)
        {
            lettersMap[ch]++;
        }

        // Fill scoreMap with scores of each letter
        for (int i = 0; i < 26; i++)
        {
            scoreMap[i] = score[i];
        }

        int maxScore = 0;

        // Iterate over all possible subsets of words
        for (int mask = 0; mask < (1 << n); mask++)
        {
            unordered_map<char, int> curWordMap;
            int curScore = 0;
            bool isValid = true;

            // Construct the current subset of words and calculate score
            for (int i = 0; i < n; i++)
            {
                if (mask & (1 << i))
                {
                    for (char ch : words[i])
                    {
                        curWordMap[ch]++;
                    }
                }
            }

            // Check if current subset is valid
            for (auto &[ch, freq] : curWordMap)
            {
                if (lettersMap[ch] < freq)
                {
                    isValid = false;
                    break;
                }
            }

            // Calculate score for the current subset if valid
            if (isValid)
            {
                for (auto &[ch, freq] : curWordMap)
                {
                    curScore += freq * scoreMap[ch - 'a'];
                }
                maxScore = max(maxScore, curScore);
            }
        }

        return maxScore;
    }
};

// Approach using recursion
class Solution
{
public:
    int maxScore; // Move maxScore here as a member variable

    // Helper function to check if a word can be formed with the available letters
    bool isOk(string &word, unordered_map<char, int> &lettersMap,
              unordered_map<char, int> wordMap)
    {
        for (auto ch : word)
        {
            wordMap[ch]++;
            if (wordMap[ch] > lettersMap[ch])
                return false;
        }
        return true;
    }

    // Recursive function to explore all combinations of words
    void solve(int i, vector<string> &words, vector<int> &score,
               unordered_map<char, int> &lettersMap,
               unordered_map<char, int> &wordMap)
    {
        int n = words.size();
        if (i == n)
        { // Base case: if all words are processed
            int curScore = 0;
            for (auto &[ch, freq] : wordMap)
                curScore += freq * score[ch - 'a']; // Calculate current score
            maxScore = max(maxScore, curScore);     // Update maxScore
            return;
        }

        // Option 1: Include the current word if it is valid
        if (isOk(words[i], lettersMap, wordMap))
        {
            for (auto ch : words[i])
                wordMap[ch]++;
            solve(i + 1, words, score, lettersMap, wordMap); // Recurse with the next word
            for (auto ch : words[i])
                wordMap[ch]--; // Backtrack: remove current word from wordMap
        }

        // Option 2: Skip the current word
        solve(i + 1, words, score, lettersMap, wordMap);
        return;
    }

    // Main function to initiate the process and return the max score
    int maxScoreWords(vector<string> &words, vector<char> &letters,
                      vector<int> &score)
    {
        maxScore = 0; // Initialize maxScore here
        unordered_map<char, int> lettersMap, wordMap;
        for (auto ch : letters)
            lettersMap[ch]++;                        // Populate lettersMap with available letters
        solve(0, words, score, lettersMap, wordMap); // Start the recursion
        return maxScore;
    }
};

// https://www.youtube.com/watch?v=d3NaO9afZB0