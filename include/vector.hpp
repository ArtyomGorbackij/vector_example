#include <iostream>
#include <algorithm>
#include <cassert>
template <typename T> 
class vector_t
{
	private:
		int * elements_;
		std::size_t size_;
		std::size_t capacity_;
	public:
		vector_t();
		vector_t(vector_t const & other);
		vector_t & operator =(vector_t const & other);
		~vector_t();

		std::size_t size() const;
		std::size_t capacity() const;

		void push_back(int value);
		void pop_back();

		int & operator [](std::size_t index);
		int operator [](std::size_t index) const;

		bool operator ==(vector_t const & other) const;
};
template <typename T>
bool operator !=(vector_t const & lhs, vector_t const & rhs);
template <typename T>
vector_t<T>::vector_t()
{
	elements_ = nullptr;
	size_ = 0;
	capacity_ = 0;
}
template <typename T>
vector_t<T>::vector_t(vector_t const & other)
{
	elements_= new T [other.capacity_];
	for (std::size_t i=0; i<other.capacity_; i++) {
		elements_[i] = other.elements_[i];
	}
	size_=other.size_;
	capaciry_=other.capacity_;
}
template <typename T>
vector_t<T> & vector_t<T>::operator =(vector_t const & other)
{
	if (elements_ != nellptr){
		delete [] elements_;
	}
	elements_ = new T [other.capacity_];
	for (std::size_t i=0;i<other.capacity_;i++){
		elements_[i]=other.elements_[i];
	}
	size_=other.size_;
	capacity_=other.capacity_;
	return *this;
}
template <typename T>
bool vector_t<T>::operator ==(vector_t const & other) const
{
	if (size_ != other.size_){
		return false;		
	}
	else 
	{
		for (std::size_t i = 0; i < other.size_; i++){
			if (elements_[i] != other.elements_[i]){
			return false;
			}
		}
		return true;
	}
}
template <typename T>
vector_t<T>::~vector_t()
{
	if (elements_ != nullptr){
		delete[] elements_;
	}
}
template <typename T>
std::size_t vector_t<T>::size() const
{
    return size_;
}
template <typename T>
std::size_t vector_t<T>::capacity() const
{
    return capacity_;
}
template <typename T>
void vector_t<T>::push_back(T value)
{
	if (elements_ == nullptr){
		size_ = 1;
		capacity_ = 1;
		elements_ = new T [capacity_];
		elements_[size_-1] = value;
	}else
	{
		size_++;
		if (size_ > capacity_){
			capacity_ *= 2;
			T * elements = new T [size_];
			for (std::size_t i = 0; i < size_ - 1; i++){
				elements[i] = elements_[i];
			}
			elements[size_-1] = value;
			delete[] elements_;
			elements_ = new T [capacity_];
			for (std::size_t i = 0; i < size_ - 1; i++){
				elements_[i] = elements[i];
			}
			delete[] elements;
		}else elements_[size_-1] = value;
	}
}
template <typename T>
void vector_t<T>::pop_back()
{
	if (elements_ == nullptr){
		return;
	}else
	{
		size_--;
		if (size_ <= capacity_/4){
			capacity_ /= 2;
		}
		
		T * elements = new T [size_];
		for (std::size_t i = 0; i < size_; i++){
			elements[i] = elements_[i];
		}
		delete[] elements_;
		elements_ = new T [capacity_];
		for (std::size_t i = 0; i < size_; i++){
			elements_[i] = elements[i];
		}
		delete[] elements;
	}
}
template <typename T>
T & vector_t<T>::operator [](std::size_t index)
{
	return elements_[index];
}
template <typename T>
T vector_t<T>::operator [](std::size_t index) const
{
	return elements_[index];
}
template <typename T>
bool operator !=(vector_t<T> const & lhs, vector_t<T> const & rhs)
{
	if (lhs==rhs){
	return false;
	}else return true;
}
