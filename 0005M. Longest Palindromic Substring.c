// Runtime: 12 ms, faster than 88.10% of C online submissions for Longest Palindromic Substring.
// Memory Usage: 6 MB, less than 94.76% of C online submissions for Longest Palindromic Substring.

typedef struct word {
    char *s;
    int len;
} word;

char * longestPalindrome(char * s){
    int n = strlen(s);
    if (n == 1)
        return s;
    int i, j;
    word longest;
    longest.s = s;
    longest.len = 0;
    int temp_max = 0;
    for (i = 0; i < n-1; i++) {
        int short_side = (i > (n-1-i)) ? (n-1-i) : i;
        for (j = 1; j <= short_side; j++) {
            if (s[i-j] != s[i+j]) {
                if (j*2-1 > temp_max) {
                    temp_max = j*2-1;
                    longest.s = &s[i-j+1];
                    longest.len = j*2 - 1;
                }
                break;
            }
            if (j == short_side) {
                if (j*2+1 > temp_max) {
                    temp_max = j*2+1;
                    longest.s = &s[i-j];
                    longest.len = j*2 + 1;
                }
                break;
            }
        }
        for (j = 0; j <= short_side; j++) {
            if (s[i-j] != s[i+1+j]) {
                if (j*2 > temp_max) {
                    temp_max = j*2;
                    longest.s = &s[i-j+1];
                    longest.len = j*2;
                }
                break;
            }
            if (j == short_side) {
                if ((j+1)*2 > temp_max) {
                    temp_max = (j+1)*2;
                    longest.s = &s[i-j];
                    longest.len = (j+1)*2;
                }
                break;
            }
        }
    }
    if (longest.len == 0) {
        longest.s = &s[0];
        longest.s[1] = '\0';
        return longest.s;
    }
    if (longest.len < n)
        longest.s[longest.len] = '\0';
    return longest.s;
}
