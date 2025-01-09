#include "myQueue.h"
#include "myList.h"
#include <iostream>
#include <random>

using namespace std;

/*
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
*/

void testLis1t() { // get, append, copy, modify
    myList<int> l1;

    auto lambda = [](myList<int> &_l) { while (!_l.isEnd()) { std::cout << _l.value() << " "; _l.next(); } std::cout << std::endl; _l.toBegin(); };
    lambda(l1);

    srand(5);
    for (int i = 0; i < 10; ++i) {
        int v = rand() % 100;
        cout << v << " ";
        l1.append(v);
    }
    cout << endl;
    l1.toBegin();

    lambda(l1);

    myList<int> l2 = l1;
    cout << "modify" << " " << l1.value() << endl;
    l2.value() = 5;
    lambda(l1);
    lambda(l2);
}

void testList2() { // assign copy
    myList<int> l1;

    auto lambda = [](myList<int>& _l) { while (!_l.isEnd()) { std::cout << _l.value() << " "; _l.next(); } std::cout << std::endl; _l.toBegin(); };

    srand(5);
    for (int i = 0; i < 10; ++i) {
        int v = rand() % 100;
        l1.append(v);
    }
    l1.toBegin();
    lambda(l1);

    myList<int> l2;
    for (int i = 0; i < 5; ++i) {
        int v = rand() % 100;
        l2.append(v);
    }
    l2.toBegin();
    lambda(l2);
    cout << endl;

    l2 = l1;
    lambda(l2);

    cout << "modify" << endl;
    l2.value() = 5;
    lambda(l1);
    lambda(l2);
}

myList<int> testfoo() {
    myList<int> l;
    for (int i = 0; i < 11; ++i) {
        int v = rand() % 100;
        l.append(v);
    }
    l.toBegin();
    return l;
}

void testList3() { // strange behaviour, i mean testfoo creates List just implace into l3
    myList<int> l1;

    auto lambda = [](myList<int>& _l) { while (!_l.isEnd()) { std::cout << _l.value() << " "; _l.next(); } std::cout << std::endl; _l.toBegin(); };

    srand(5);
    for (int i = 0; i < 10; ++i) {
        int v = rand() % 100;
        l1.append(v);
    }
    l1.toBegin();
    lambda(l1);

    myList<int> l2;
    l2 = testfoo();
    lambda(l2);

    myList<int> l3(testfoo());
    lambda(l3);
}

void testMerge() {
    myList<int> l1;

    auto lambda = [](myList<int>& _l) { while (!_l.isEnd()) { std::cout << _l.value() << " "; _l.next(); } std::cout << std::endl; _l.toBegin(); };

    srand(7);
    for (int i = 0; i < 10; ++i) {
        int v = rand() % 100;
        l1.append(v);
    }
    l1.toBegin();
    lambda(l1);

    l1.mergeSort();
    lambda(l1);
}

int main() {
    testMerge();
	return 0;
}