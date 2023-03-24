#pragma once

#include <vector>
#include <iostream>
// TODO

#define LIST_EXCEPTION_CHECK

#ifdef LIST_EXCEPTION_CHECK
#include <stdexcept>
#endif

template <class T>
class List {
public:
	struct Node {
	public:
		T val_;
		Node* prev_;
		Node* next_;
	};
private:
	Node* head_;
	Node* tail_;
	std::vector<Node*> ledger_;

	std::size_t size_;
	std::size_t increment_;

	Node* GetNode(std::size_t index) const {
		std::size_t ledger_index = index / increment_;
		std::size_t ledger_increment = index % increment_;

#ifdef LIST_EXCEPTION_CHECK
		if (index >= 0 && index < size_) {
#endif
			Node* cursor = ledger_[ledger_index];
			for (std::size_t i = 0; i < ledger_increment; ++i) {
				cursor = cursor->next_;
			}
			return cursor;
#ifdef LIST_EXCEPTION_CHECK
		}
		else {
			throw std::out_of_range("Index out of range!");
		}
#endif
	}
public:
	List()
		: ledger_(), size_(0), increment_(5), head_(nullptr), tail_(nullptr)
	{

	}

	List(std::size_t increment)
		: ledger_(), size_(0), increment_(increment == 0 ? 1 : increment), head_(nullptr), tail_(nullptr)
	{

	}

	~List()
	{
		Node* cursor = head_;
		for (std::size_t i = 0; i < size_; ++i) {
			Node* last_cursor = cursor;
			cursor = cursor->next_;
			delete last_cursor;
		}
	}

	T& Get(std::size_t index) {
		return GetNode(index)->val_;
	}

	void Insert(const T& value, std::size_t index)
	{
		std::size_t ledger_index = index / increment_;
		std::size_t ledger_increment = index % increment_;

#ifdef LIST_EXCEPTION_CHECK
		if (index > 0 && index < size_) {
#endif
			Node* cursor = ledger_[ledger_index];
			for (std::size_t i = 0; i < ledger_increment; ++i) {
				cursor = cursor->next_;
			}

			Node* inserted_value = new Node();
			inserted_value->prev_ = cursor->prev_;
			cursor->prev_ = inserted_value;
			inserted_value->next_ = cursor;

			++size_;

#ifdef LIST_EXCEPTION_CHECK
		}
		else {
			throw std::out_of_range("Index out of range!");
		}
#endif
	}

	void PushBack(const T& value)
	{
		Node* prev_head = head_;
		head_ = new Node();
		head_->next_ = prev_head;
		head_->val_ = value;

		++size_;
		if (size_ % increment_ == 0) {

		}
	}

	void PushFront(const T& value)
	{
		Node* prev_head = head_;
		head_ = new Node();
		head_->next_ = prev_head;
		head_->val_ = value;

		if (prev_head != nullptr) {
			prev_head->prev_ = head_;
		}
		else {
			tail_ = head_;
		}

		for (std::size_t i = 0; i < ledger_.size(); ++i) {
			ledger_[i] = ledger_[i]->prev_;
		}
		if (size_ % increment_ == 0) {
			ledger_.push_back(tail_);
		}

		++size_;
	}

	void Print() {
		Node* cursor = head_;
		std::cout << "Data:" << std::endl;
		std::cout << "[" << std::endl;
		for (std::size_t i = 0; i < size_; ++i) {
			std::cout << i << ": " << cursor << " - " << cursor->val_ << std::endl;
			cursor = cursor->next_;
		}
		std::cout << "]" << std::endl;

		std::cout << std::endl;

		std::cout << "Ledger:" << std::endl;
		std::cout << "[" << std::endl;
		for (std::size_t i = 0; i < ledger_.size(); ++i) {
			std::cout << i << ": " << ledger_[i] << " - " << ledger_[i]->val_ << std::endl;
		}
		std::cout << "]" << std::endl;
	}
};
