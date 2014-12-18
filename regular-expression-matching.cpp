class Solution {
    public: bool isMatch(const char * s, const char * p) {
        if ('\0' == *p && '\0' == *s) {
            return true;
        }
        if ('\0' == *p && '\0' != *s) {
            return false;
        }
        if ('*' == *p) {
            return false; //start with '*' is invalid pattern
        }

        if ( * (p + 1) != '*') {
            if ('\0' == *s) {
                return false;
            }
            return ( * p == '.' || *p == *s) && isMatch(++s, ++p);
        } else {
            const char * ptrString = s;
            const char * ptrPattern = p;
            const char * ptrPatternNext = p + 2;
            if ('\0' == *ptrString) {
                return isMatch(ptrString, ptrPatternNext);
            }
            if (isMatch(ptrString, ptrPatternNext)) {
                return true;
            }
            while ( * ptrPattern == '.' || *ptrPattern == *ptrString) {
                if (isMatch(++ptrString, ptrPatternNext)) {
                    return true;
                }
                if ('\0' == *ptrString) {
                    break;
                }
            };
            return isMatch(ptrString, ptrPatternNext);

        }
    }
};