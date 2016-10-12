/**
使用两个堆来实现以上的功能：大根堆存储小于中值的数据，小根堆存储大于中值的数据。这样，当数字个数为偶数时，中值为两个堆顶元素的平均值；当数字个数为奇数时，中值为大根堆或者小根堆堆顶元素。具体描述如下：
建立两个堆：大根堆和小根堆；
执行addNum函数时，向堆中添加元素，并保证：
两个堆的大小尽可能相等(两堆大小相等，或者小根堆比大根堆多出一个元素)；
大根堆的堆顶元素 ≤≤ 小根堆的堆顶元素；
执行findMedian函数时：
如果两堆中元素为偶数个，则返回两个堆顶元素的平均值；
如果两堆中元素为奇数个，则返回小根堆的堆顶元素。
 */

class MedianFinder {
private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxHeap.size() == 0 || maxHeap.top() >= num) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
