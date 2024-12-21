#pragma once

template <typename T>
struct ListNode {
	T val;
	ListNode* next;
	ListNode() {}
	ListNode(const T& val, ListNode* next = nullptr) : val(val), next(next) {}
};

template <typename T>
struct myList {
	ListNode<T>* head;
	myList(ListNode<T>* node) : head(node) {}
};