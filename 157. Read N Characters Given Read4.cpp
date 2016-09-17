// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int ret = 0, i = 0;
        do {
            // 此处传参为读取data首地址.
            ret = read4 (buf + i);
            i += ret;
        } while (ret == 4 && i < n); // 至少读一次，ret == 4表示buf没读完，i < n表示还没读到指定长度...
        // 返回n表示读到指定长度了，返回i表示buf读完了
        return min (n, i);
    }
};
