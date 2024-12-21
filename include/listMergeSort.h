#pragma once
#include "myList.h"
#include "myQueue.h"

template<typename T>
ListNode<T>* myMerge(ListNode<T>* headl, ListNode<T>* headr) {
    ListNode<T>* head = nullptr;
    if (headl == nullptr) {
        return headr;
    }
    if (headr == nullptr) {
        return headl;
    }

    if (headl->val <= headr->val) {
        head = headl;
        headl = headl->next;
    }
    else {
        head = headr;
        headr = headr->next;
    }

    ListNode<T>* headres = head;
    while ((headl != nullptr) && (headr != nullptr)) {
        if (headl->val <= headr->val) {
            head->next = headl;
            headl = headl->next;
        }
        else if (headl->val > headr->val) {
            head->next = headr;
            headr = headr->next;
        }
        head = head->next;
    }
    if (headl != nullptr)
        head->next = headl;
    if (headr != nullptr)
        head->next = headr;

    return headres;
}

template <typename T>
myList<T> myMergeSort(myList<T> list) {
    myQueue<ListNode<T>*> q;
    ListNode<T>* head = list.head;
    ListNode<T>* node;

    while (head != nullptr) {
        node = head;
        head = head->next;
        node->next = nullptr;
        q.push(node);
    }

    ListNode<T>* first = nullptr;
    ListNode<T>* second = nullptr;
    if (!q.isEmpty())
        while (true) {
            first = q.back();
            if (q.isEmpty()) break;
            second = q.back();
            q.push(myMerge<T>(first, second));
        }

    return myList<T>(first);
}