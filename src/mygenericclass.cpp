#include <typeinfo>

#include<mygenericclass.hpp>

template class MyGenericClass<char>;
template class MyGenericClass<char*>;
template class MyGenericClass<const char*>;
template class MyGenericClass<MyGenericClass<char>>;
template class MyGenericClass<aaa::A>;
template class MyGenericClass<const char**>;
template class MyGenericClass<const char* const *>;
//template class MyGenericClass<char const * const *>;

template<class T>
const char* MyGenericClass<T>::GetTypeName() {
	return typeid(T).name();
};
