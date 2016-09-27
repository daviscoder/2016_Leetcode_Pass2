/**
 * O (n), O(1).
 * 
 */
// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int offset = 0, bufSize = 0;
    char buf4[4] = {0};
    
    int read(char *buf, int n) {
        int cnt = 0; // 当前已读多少字符
        while (cnt < n) {
            if (offset == 0) // 如果buf 为空先把buf读满
                bufSize = read4 (buf4);
            if (bufSize == 0)
                break;
            while (cnt < n && offset < bufSize) { // 将buf4字符转运到buf中
                buf[cnt] = buf4[offset];
                offset++;
                cnt++;
            }
            if (offset == bufSize)
                offset = 0;
        }
        return min (cnt, n);
    }
};
