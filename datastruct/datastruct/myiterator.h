#ifndef __MYITERATOR_H__
#define __MYITERATOR_H__
#include <xmemory0>

template<class T>
class myiterator : public std::_Iterator_base
{
	using difference_type = int;
public:
	myiterator(T* _Parg);

	~myiterator();

	const T& operator*() const;

	T* operator->() const;

	myiterator& operator++();

	myiterator operator++(int);

	myiterator& operator--();

	myiterator operator--(int);

	myiterator& operator+=(const difference_type _Off);

	myiterator operator+(const difference_type _Off) const;

	myiterator& operator-=(const difference_type _Off);

	myiterator operator-(const difference_type _Off) const;

	const T& operator[](const difference_type _Off) const;

	_NODISCARD bool operator==(const myiterator& _Right) const;

	_NODISCARD bool operator!=(const myiterator& _Right) const;

	_NODISCARD bool operator<(const myiterator& _Right) const;

	_NODISCARD bool operator>(const myiterator& _Right) const;

	_NODISCARD bool operator<=(const myiterator& _Right) const;

	_NODISCARD bool operator>=(const myiterator& _Right) const;

	void _Seek_to(T* _It);

	T* _Unwrapped() const;

private:
	T* _Ptr;	// pointer to element in vector
};

template <class T>
myiterator<T>::myiterator(T* _Parg): _Ptr(_Parg)
{
}

template <class T>
myiterator<T>::~myiterator()
{
}

template <class T>
const T& myiterator<T>::operator*() const
{
	return *_Ptr;
}

template <class T>
T* myiterator<T>::operator->() const
{
	return _Ptr;
}

template <class T>
myiterator<T>& myiterator<T>::operator++()
{
	++_Ptr;
	return (*this);
}

template <class T>
myiterator<T> myiterator<T>::operator++(int)
{
	auto _Tmp = *this;
	++*this;
	return (_Tmp);
}

template <class T>
myiterator<T>& myiterator<T>::operator--()
{
	--_Ptr;
	return (*this);
}

template <class T>
myiterator<T> myiterator<T>::operator--(int)
{
	auto _Tmp = *this;
	--*this;
	return (_Tmp);
}

template <class T>
myiterator<T>& myiterator<T>::operator+=(const difference_type _Off)
{
	// increment by integer
	_Ptr += _Off;
	return (*this);
}

template <class T>
myiterator<T> myiterator<T>::operator+(const difference_type _Off) const
{
	// return this + integer
	myiterator _Tmp = *this;
	return (_Tmp += _Off);
}

template <class T>
myiterator<T>& myiterator<T>::operator-=(const difference_type _Off)
{
	// decrement by integer
	return (*this += -_Off);
}

template <class T>
myiterator<T> myiterator<T>::operator-(const difference_type _Off) const
{
	// return this - integer
	myiterator _Tmp = *this;
	return (_Tmp -= _Off);
}

template <class T>
const T& myiterator<T>::operator[](const difference_type _Off) const
{
	// subscript
	return (*(*this + _Off));
}

template <class T>
bool myiterator<T>::operator==(const myiterator& _Right) const
{
	// test for iterator equality
	return (_Ptr == _Right._Ptr);
}

template <class T>
bool myiterator<T>::operator!=(const myiterator& _Right) const
{
	// test for iterator inequality
	return (!(*this == _Right));
}

template <class T>
bool myiterator<T>::operator<(const myiterator& _Right) const
{
	// test if this < _Right
	return (_Ptr < _Right._Ptr);
}

template <class T>
bool myiterator<T>::operator>(const myiterator& _Right) const
{
	// test if this > _Right
	return (_Right < *this);
}

template <class T>
bool myiterator<T>::operator<=(const myiterator& _Right) const
{
	// test if this <= _Right
	return (!(_Right < *this));
}

template <class T>
bool myiterator<T>::operator>=(const myiterator& _Right) const
{
	// test if this >= _Right
	return (!(*this < _Right));
}

template <class T>
void myiterator<T>::_Seek_to(T* _It)
{
	_Ptr += _It;
}

template <class T>
T* myiterator<T>::_Unwrapped() const
{
	return (this->_Ptr);
}
#endif
