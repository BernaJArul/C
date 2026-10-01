int binaryGap(int n) {
    int max = 0, last = -1;
    for (int p = 0; n; n >>= 1, p++) {
        if (n & 1) {
            if (last != -1 && (p - last) > max) {
                max = p - last;
            }
            last = p;
        }
    }
    return max;
}
