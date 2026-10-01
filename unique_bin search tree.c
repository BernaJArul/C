int numTrees(int n) {
    long long c = 1;
    
    for (int i = 0; i < n; i++) {
        // Direct implementation of the Catalan number recurrence formula
        c = c * 2 * (2 * i + 1) / (i + 2);
    }
    
    return (int)c;
}
