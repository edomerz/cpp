/****************************************
*
*	shared_ptr Project Header file:	shared_ptr.h
*	04-13-2016
*	
*	Production : Elran Sarusi
*	Reviewed by :
*
****************************************/

#ifndef __SHARED_PTR_H__
#define __SHARED_PTR_H__

#include<iostream>


namespace ilrd
{
template<typename T>
class SharedPtr
{
public:
	explicit SharedPtr(T* ptr_=NULL);
	SharedPtr(const SharedPtr& other_);
	~SharedPtr();

	SharedPtr& operator=(const SharedPtr& other_);

	T* operator->();
	T& operator*();

/*OVERLOADING commented *&*&*&
	template<typename derivedT>
	operator SharedPtr<derivedT>();
*/

	//overloading implementation
	template<typename derivedT>
	SharedPtr(const SharedPtr<derivedT>& other_);
	template<typename derivedT>
	SharedPtr<T>& operator=(const SharedPtr<derivedT>& other_);

	private:
		T* m_ptr;
		size_t* ref_count;

		template<typename ALL>
		friend class SharedPtr; //friend to all
		//CTOR for inheritance conversion purposes
		SharedPtr(T* ptr_ , size_t* ref_init_);
};


//OVERLOADING commented *&*&*&
/*template<typename T>
template<typename derivedT>
SharedPtr<T>::operator SharedPtr<derivedT>()
{
	//give the new base instance the members necessary for init
	SharedPtr<T> temp(m_ptr,ref_count);
	return(temp);
	return(SharedPtr<derivedT>(m_ptr, ref_count));
}*/


//OVERLOADING commented *&*&*&
template<typename T>
template<typename derivedT>
SharedPtr<T>::SharedPtr(const SharedPtr<derivedT>& other_)
:m_ptr(other_.m_ptr), ref_count(other_.ref_count)
{
	++*ref_count;
}

template<typename T>
template<typename derivedT>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<derivedT>& other_)
{
	++*other_.ref_count;
	this->~SharedPtr();
	m_ptr = other_.m_ptr;
	ref_count = other_.ref_count;
	return *this;
}
//OVERLOADING DONE


template<typename T>
SharedPtr<T>::SharedPtr(T* ptr_)
:m_ptr(ptr_), ref_count(new size_t(1))
{}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other_)
:m_ptr(other_.m_ptr), ref_count(other_.ref_count)
{
	++*ref_count;
}


template<typename T>
SharedPtr<T>::~SharedPtr()
{
	if (!(--(*ref_count)))
	{
		delete ref_count;
		delete m_ptr;
	}
}


template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other_)
{
	++*other_.ref_count;
	this->~SharedPtr();
	m_ptr = other_.m_ptr;
	ref_count = other_.ref_count;
	return *this;
}

template<typename T>
T* SharedPtr<T>::operator->()
{
	return m_ptr;
}

template<typename T>
T& SharedPtr<T>::operator*()
{
	return *m_ptr;
}

//CTOR for inheritance conversion purposes
template<typename T>
SharedPtr<T>::SharedPtr(T* ptr_ , size_t* ref_init_)
:m_ptr(ptr_), ref_count(&(++*ref_init_))
{

}

}



#endif  /******** these are function declarations for __SHARED_PTR_H__ ************/
