class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int i, j, k, plen = 0;
        for (i = 0; needle[i]; i++) plen++;
        int *nextval = new int[plen+1];
        fill(nextval, nextval+plen+1, -1);
        for (i = 1; needle[i]; i++) {
            for (k=nextval[i-1]; k>=0 && needle[i]!=needle[k+1]; k=nextval[k]);
            if (needle[k+1] == needle[i]) nextval[i] = k+1;
        }
        i = j = 0;
        while (haystack[i] && needle[j]) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else if (j == 0) i++;
            else j = nextval[j-1]+1;
        }
        if (needle[j]) return NULL;
        else return haystack+i-j;
    }
};
