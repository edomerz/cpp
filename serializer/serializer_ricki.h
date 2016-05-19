/****************************************************************************
	serializer
AUTHOR: omer ido                                                  
CREATE DATE: 08/05/16                                              			
DESCRIPTION: 
**************************************************************************/
#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include <iostream> 

#include <boost/shared_ptr.hpp>

#include "factory.h"

using namespace ilrd
{

template <typename T>
class Serializer
{
public:
	void Serializer(const T& obj_, std::ostream& out_);
	
	template <typename D> // derived
	void Add();

	boost::shared_ptr<T> Create(std::istream& in_);

private:
	template <typename D>
	static boost::shared_ptr<T> CreateIMP(std::istream& in_);

	Factory<std::string, T, std::istream> m_factory;
};

template<typename T>
void Serializer<T>::Serializer(const T& obj_, std::ostream& ???)
{
	// add key to beginnig of string
	out << '\n' << typeid(obj_).name() << " " << obj_;

}

template<typename T>
boost::shared_ptr<T> Serializer<T>::Create(std::istream& ??)
{
	std::string class_key;
	in >> class_key;
	return(m_factory.Create(class_key, in_));
}

template<typename T>
template<typename D>
boost::shared_ptr<T> Serializer<T>::CreateIMP(std::istream???)
{
	boost::shared_ptr???
}

}
#endif /* ifndef __SERIALIZER_H__*/
