class Solution {
public:
    string compressedString(string word) {
        stringstream comp;
        int i=0;
        char currentChar;
        int n=word.length();

        while(i<n){
            currentChar=word[i];
            int charCount=0;

            while(i<n && word[i]==currentChar && charCount<9){
                charCount++;
                i++;
            }

            comp<<charCount;
            comp<<currentChar;
        }
        return comp.str();
    }
};

// 1. Using std::stringstream:

// Reduces the cost of repeated string concatenation by building the result incrementally in a buffer.

// 2. Efficient Memory Usage:

// Avoids repeated memory allocation during comp += ... operations.