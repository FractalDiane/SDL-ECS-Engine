#pragma once

#include <initializer_list>
#include <stdexcept>
#include <iterator>
#include <algorithm>

template <typename T>
class Vocter {
private:
	struct Cell {
		bool occupied;
		T item;

		Cell() : occupied{false} {}
	};

public:
	/*typedef size_t size_type;

	class iterator {
	public:
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef Cell* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef size_t difference_type;
		iterator(pointer ptr) : ptr_{ptr} {}
		self_type operator++() { self_type i = *this; ptr_++; return i; }
		self_type operator++(size_t junk) { ptr_++; return *this; }
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type* rvalue) { return ptr_ == rvalue.ptr_; }
		bool operator!=(const self_type* rvalue) { return ptr_ != rvalue.ptr_; }
	private:
		pointer ptr_;
	};

	class const_iterator {
	public:
		typedef const_iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef Cell* pointer;
		typedef std::forward_iterator_tag iterator_category;
		typedef size_t difference_type;
		const_iterator(pointer ptr) : ptr_{ptr} {}
		self_type operator++() { self_type i = *this; ptr_++; return i; }
		self_type operator++(size_t junk) { ptr_++; return *this; }
		reference operator*() { return *ptr_; }
		pointer operator->() { return ptr_; }
		bool operator==(const self_type* rvalue) { return ptr_ == rvalue.ptr_; }
		bool operator!=(const self_type* rvalue) { return ptr_ != rvalue.ptr_; }
	private:
		pointer ptr_;
	};*/

private:
	Cell* array;
	size_t size_;
	size_t capacity;
	size_t open_slot_index;

	constexpr static size_t InitialCapacity = 10;

public:
	Vocter();
	Vocter(std::initializer_list<T> items);
	Vocter(const Vocter& rvalue) = delete;
	~Vocter();

	Vocter& operator=(const Vocter& rvalue) = delete;

	void push_back(const T& item);
	void erase(const T& item);
	void erase_at(const size_t& index);

	size_t size() const noexcept;
	bool empty() const noexcept;

	const T& operator[](const size_t& index) const noexcept;
	const T& at(const size_t& index) const;

	/*iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;*/
	
private:
	void reallocate_array();
	void update_slot_index();
};

template <typename T>
Vocter<T>::Vocter() : array{new Cell[InitialCapacity]}, size_{0}, capacity{InitialCapacity}, open_slot_index{0} {}


template <typename T>
Vocter<T>::Vocter(std::initializer_list<T> items) : array{new Cell[InitialCapacity]}, open_slot_index{0}, size_{0}, capacity{InitialCapacity} {
	for (const T& item : items)
		push_back(item);
}


template <typename T>
Vocter<T>::~Vocter() {
	delete[] array;
}






template <typename T>
void Vocter<T>::push_back(const T& item) {
	array[open_slot_index].item = item;
	array[open_slot_index].occupied = true;
	update_slot_index();

	size_++;
	if (size_ == capacity)
		reallocate_array();
}


template <typename T>
void Vocter<T>::erase(const T& item) {
	for (size_t i = 0; i < size_; i++) {
		if (array[i].item == item) {
			array[i].occupied = false;
			open_slot_index = i;
			size_--;
			return;
		}
	}
}


template <typename T>
void Vocter<T>::erase_at(const size_t& index) {
	if (index >= size_ || index < 0)
		throw std::out_of_range{"Vocter index out of range"};

	array[index].occupied = false;
	open_slot_index = index;
	size_--;
}


template <typename T>
size_t Vocter<T>::size() const noexcept {
	return size_;
}


template <typename T>
bool Vocter<T>::empty() const noexcept {
	return size_ == 0;
}


template <typename T>
const T& Vocter<T>::operator[](const size_t& index) const noexcept {
	return array[index].item;
}


template <typename T>
const T& Vocter<T>::at(const size_t& index) const {
	if (index >= size_ || index < 0 || !array[index].occupied)
		throw std::out_of_range{"Vocter index out of range"};
	
	return array[index].item;
}


/*template <typename T>
typename Vocter<T>::iterator Vocter<T>::begin() {
	return iterator(array);
}


template <typename T>
typename Vocter<T>::iterator Vocter<T>::end() {
	return iterator(array + size_);
}


template <typename T>
typename Vocter<T>::const_iterator Vocter<T>::begin() const {
	return const_iterator(array);
}


template <typename T>
typename Vocter<T>::const_iterator Vocter<T>::end() const {
	return const_iterator(array + size_);
}*/


template <typename T>
void Vocter<T>::reallocate_array() {
	capacity = capacity * 2 + 1;
	Cell* new_array = new Cell[capacity];
	for (size_t i = 0; i < size_; i++)
		new_array[i] = array[i];

	delete[] array;
	array = new_array;
}


template <typename T>
void Vocter<T>::update_slot_index() {
	while (array[open_slot_index].occupied)
		open_slot_index++;
}
