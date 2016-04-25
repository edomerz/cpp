/****************************************************************************
	sharedptr
AUTHOR: omer ido                                                  
CREATE DATE: 13/04/16                                              			
DESCRIPTION: 
2 methods:
1- cctor and op= templated
2 - member template function
**************************************************************************/
#ifndef __SHAREDPTR_H__
#define __SHAREDPTR_H__

#include <iostream> 

namespace ilrd
{
template<class T>
class SharedPtr
{
public:
	explicit SharedPtr(T* ptr = 0);
	SharedPtr(const SharedPtr& other_);
	SharedPtr& operator=(const SharedPtr& other_);
	~SharedPtr();

	T* operator->();
	T& operator*();

	template<typename NewType> 		// member function template
	operator SharedPtr<NewType>();	// implicit conversion op

/*  overloading
 *  templata<typename NewType>
 *  SharedPtr(const SharedPtr<NewType>& other_);
 *
 *  template<typename NewType>
 *  SharedPtr<T>& operator=(const SharedPtr<NewType>& other_);
 */

private:
	T* m_ptr;
	size_t* m_ref_cnt;

	template <typename NewType>
	friend class SharedPtr;

	// Ctor - for conversion
	SharedPtr(T* ptr, size_t* ref_count); // non explicit
};

template<class T>
SharedPtr<T>::SharedPtr(T* ptr): m_ptr(ptr), m_ref_cnt(new size_t(1))
{}

template<class T>
SharedPtr<T>::SharedPtr(const SharedPtr& other_):
						m_ptr(other_.m_ptr), m_ref_cnt(other_.m_ref_cnt)
{
	++(*m_ref_cnt);
}
template<class T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other_)
{
	++(*other_.m_ref_cnt);
	this->~SharedPtr();
	m_ptr = other_.m_ptr;
	m_ref_cnt = other_.m_ref_cnt;

	return(*this);
}

template<class T>
SharedPtr<T>::~SharedPtr()
{
	if(!(--(*m_ref_cnt)))
	{
		delete m_ptr;
		delete m_ref_cnt;
	}
}

template<class T>
template<class NewType>
SharedPtr<T>::operator SharedPtr<NewType>()
{
	return(*this);
}

// overloading
/*
template<typename T>
template<typename derivedT>
SharedPtr<T>::operator SharedPtr<derivedT>()
{
	SharedPtr<T> temp(m_ptr,ref_count);
	return(temp);
	return(SharedPtr<derivedT>(m_ptr, ref_count));
}
*/

//template<class T>
//SharedPtr<T>::
//
//template<class T>
//SharedPtr<T>::
//
//template<class T>
//SharedPtr<T>::
//
//template<class T>
//SharedPtr<T>::
//
//template<class T>
//SharedPtr<T>::

}
	
#endif /* ifndef __SHAREDPTR_H__*/
