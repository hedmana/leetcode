#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (!strs || strsSize == 0) return 0;
    const char *min = strs[0];
    const char *max = strs[0];

    if (!min) return "";

    for (int i = 1; i < strsSize; i++) {
        if (strcmp(strs[i], min) < 0) min = strs[i];
        if (strcmp(strs[i], max) > 0) max = strs[i];    
    }

    int k = 0;
    while (min[k] && min[k] == max[k]) k++;

    char *out = malloc((size_t)k + 1);
    memcpy(out, min, (size_t)k);
    out[k] = '\0';
    return out;
}

int main () {
    char *test[] = {"flower", "flow", "flight"};
    int size = 3;

    char *testAns = longestCommonPrefix(test, size);
    printf("%s\n", testAns);
    return 0;
}
