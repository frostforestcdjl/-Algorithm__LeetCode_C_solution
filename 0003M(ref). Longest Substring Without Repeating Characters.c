// Runtime: 3 ms, faster than 85.67% of C online submissions for Longest Substring Without Repeating Characters.
// Memory Usage: 5.7 MB, less than 95.56% of C online submissions for Longest Substring Without Repeating Characters.

int lengthOfLongestSubstring(char * s){
    int maxLen = 0, prevMaxLen = 0, prevIndexOf[128];
    
    bzero(prevIndexOf, sizeof(prevIndexOf));    
    for (char *c = s; *c; c++) {
        int idx = c - s + 1;
        int candidateLen = idx - prevIndexOf[*c];
        int curMaxLen = (++prevMaxLen < candidateLen) ? prevMaxLen : candidateLen;
        prevIndexOf[*c] = idx;
        if (curMaxLen > maxLen) {
            maxLen = curMaxLen;
        }
        prevMaxLen = curMaxLen;
    }    
    return maxLen;
}
