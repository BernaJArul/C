int minAddToMakeValid(char* s) {
    int open_needed = 0;  // Tracks unmatched '('
    int close_needed = 0; // Tracks unmatched ')'

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            open_needed++;
        } else { // s[i] == ')'
            if (open_needed > 0) {
                // If there's an available opening bracket, pair it up
                open_needed--;
            } else {
                // No opening bracket available, so we must add one
                close_needed++;
            }
        }
    }
    // Total additions required is the sum of all remaining unmatched brackets
    return open_needed + close_needed;
}
