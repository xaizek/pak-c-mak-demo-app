#ifndef PLUGIN_MYGENERICCLASS_HPP
#define PLUGIN_MYGENERICCLASS_HPP

namespace aaa{
	class A {};
}

template<class T>
class MyGenericClass {
	public: 
		const char* GetTypeName();
};

#endif /* PLUGIN_MYGENERICCLASS_HPP */