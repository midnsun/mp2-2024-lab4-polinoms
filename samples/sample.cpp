#include "listMergeSort.h"
#include "myQueue.h"
#include <iostream>
#include <random>

using namespace std;

void testMerge() {
    ListNode<int>* current;
    ListNode<int>* head1 = new ListNode<int>{ 1, nullptr };
    head1->next = new ListNode<int>{ 3, nullptr };
    head1->next->next = new ListNode<int>{ 5, nullptr };
    ListNode<int>* head2 = new ListNode<int>{ 2, nullptr };
    head2->next = new ListNode<int>{ 4, nullptr };
    head2->next->next = new ListNode<int>{ 6, nullptr };

    current = head1;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    current = head2;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }

    cout << "myMerge started" << endl;
    ListNode<int>* res = myMerge(head2, head1);
    current = res;

    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl << "myMerge ended" << endl;



    current = res;
    ListNode<int>* tmp;
    while (current != nullptr) {
        tmp = current;
        current = current->next;
        delete tmp;
    }
}

void test_queue() {
    myQueue<int> q;
    int i;
    for (i = 0; i < 10; i++) {
        q.push(i);
    }

    for (int j = 0; j < 5; ++j) {
        cout << q.back() << " ";
    }
    cout << endl;

    for (i = 0; i < 15; i++) {
        q.push(i);
    }

    while (!q.isEmpty()) {
        cout << q.back() << " ";
    }
    cout << endl;
}

void testMergeSort() {
    ListNode<int>* head = new ListNode<int>{rand() % 100, nullptr};
    ListNode<int>* current = head;
    for (int i = 0; i < 100; ++i) {
        current->next = new ListNode<int>{ rand() % 100, nullptr };
        current = current->next;
    }

    current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    head = myMergeSort(myList<int>(head)).head;

    current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    current = head;
    ListNode<int>* tmp;
    while (current != nullptr) {
        tmp = current;
        current = current->next;
        delete tmp;
    }
}

int main() {
    testMergeSort();
	return 0;
}