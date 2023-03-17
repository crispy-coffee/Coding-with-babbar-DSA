#include <iostream>
using namespace std;

class Linkedlist {
public:
    int data;
    Linkedlist* next = NULL;

    Linkedlist(int d) {
        this->data = d;
        this->next = NULL;
    }
};

class MedianFinder {
public:
    int count;
    Linkedlist* head;
    Linkedlist* median;
    MedianFinder() {
        head = NULL;
        median = head;
        count = 0;
    }

    void addNum(int num) {
        count++;
        Linkedlist* temp = new Linkedlist(num);
        if (head == NULL) {
            head = temp;
            median = temp;
            head->next = NULL;
            return;
        }
        else {
            Linkedlist* prev = NULL;
            Linkedlist* cur = head;
            while (cur != NULL && cur->data <= num) {
                prev = cur;
                cur = cur->next;
            }
            if (prev == NULL) {
                temp->next = head;
                head = temp;
            }
            else {
                temp->next = prev->next;
                prev->next = temp;
            }

        }

        if (count != 1 && count % 2 == 1) {
            median = median->next;
        }
    }

    double findMedian() {
        if (count % 2 == 0 && median != NULL && median->next != NULL) {
            return (median->data + median->next->data) / 2.0;
        }
        else if (median != NULL) {
            return median->data;
        }
        else {
            return 0;
        }
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(-1);
    cout << mf.findMedian() << endl; // Output: -1.000000
    mf.addNum(-2);
    cout << mf.findMedian() << endl; // Output: -1.500000
    mf.addNum(-3);
    cout << mf.findMedian() << endl; // Output: -2.000000
    mf.addNum(-4);
    cout << mf.findMedian() << endl; // Output: -2.500000
    mf.addNum(-5);
    cout << mf.findMedian() << endl; // Output: -3.000000
    return 0;
}
