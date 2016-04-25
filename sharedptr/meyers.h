/*
 * meyers.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: fullstack
 */
template<class T>
class auto_ptr
{
public:
	auto_ptr(T* ptr = 0);

	auto_ptr(T& other_); // no const, other_ gets changed
	T& operator=(T& other_);

	T& operator*();
	T* operator->();

	~auto_ptr();
private:
	T* pointee;
};

template<class T>
auto_ptr<T>::auto_ptr(const auto_ptr<T>& other_)
{
	pointee = other_.pointee;

}


template<class T>
T& auto_ptr<T>::operator *()
{
	// perform smart pointer processing

	return *pointee;
}


// pt->displaySomething() - translate to the compiler as
// (pt.operator->())->displaySomething()
template<class T>
T* auto_ptr<T>::operator ->()
{
//	perform smart pointer processing

	return pointee;
}

