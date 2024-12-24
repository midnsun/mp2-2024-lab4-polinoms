#pragma once
#include <iostream> // 

template <typename T>
struct ListNode {
	T val;
	ListNode* next;
	ListNode() {}
	ListNode(const T& val, ListNode* next = nullptr) : val(val), next(next) {}
};

template <typename T>
struct myList { // no new-deletes or no ascess to ptrs or smart ptrs
	ListNode<T>* head;
	ListNode<T>* lastUsed;
	myList(ListNode<T>* node = nullptr) : head(node), lastUsed(node) {}
//	myList(const myList<T>& rhs) {
//		std::cout << "copy c-tor" << std::endl; //
//		if (rhs.head != nullptr) {
//			ListNode<T>* rhshead = rhs.head;
//			head = new ListNode{ rhshead->val, rhshead->next };
//			ListNode<T>* lhshead = head;
//			lastUsed = rhs.lastUsed;
//			while (rhshead != nullptr) {
//				rhshead = rhshead->next;
//				lhshead->next = new ListNode{ rhshead->val, rhshead->next };
//				lhshead = lhshead->next;
//			}
//		}
//	}
//	myList(myList<T>&& rhs) {
//		std::cout << "moved c-tor" << std::endl; // 
//		head = rhs.head;
//		rhs.head = nullptr;
//		lastUsed = rhs.head;
//	}
//	myList<T>& operator=(const myList<T>& rhs) {
//		ListNode<int>* tmp = nullptr;
//		while (head != nullptr) {
//			tmp = head;
//			head = head->next;
//			delete tmp;
//		}
//
//		if (rhs.head != nullptr) {
//			ListNode<T>* rhshead = rhs.head;
//			head = new ListNode{ rhshead->val, rhshead->next };
//			ListNode<T>* lhshead = head;
//			lastUsed = rhs.lastUsed;
//			while (rhshead != nullptr) {
//				rhshead = rhshead->next;
//				lhshead->next = ListNode{ rhshead->val, rhshead->next };
//				lhshead = lhshead->next;
//			}
//		}
//
//		return this;
//	}
//	// append to last used
//	// del last used
//	// set/get last used
//	// constructor (assign/moded) - destructor
//	// SMART ptrs ??
//	
//	~myList(){
//		ListNode<int>* tmp = nullptr;
//		while (head != nullptr) {
//			tmp = head;
//			head = head->next;
//			delete tmp;
//		}
//	}
};