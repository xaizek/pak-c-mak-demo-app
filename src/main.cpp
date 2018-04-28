#include<iostream>
#include<mygenericclass.hpp>

//class A{};

template <class T>
void print_type_info() {
	MyGenericClass<T> generic_class;
	std::cout << generic_class.GetTypeName() << std::endl;
}

int main(int argc, char* argv[]) {
	
	class MyGenericClass<char> char_type;
	class MyGenericClass<MyGenericClass<char>> char_recursive_type;
	class MyGenericClass<aaa::A> a_type;
	
	std::cout << char_type.GetTypeName() << std::endl;
	std::cout << a_type.GetTypeName() << std::endl;
	std::cout << char_recursive_type.GetTypeName() << std::endl;
	std::cout << std::endl;
	
	print_type_info<char>();
	print_type_info<char*>();
	print_type_info<const char*>();
	print_type_info<MyGenericClass<char>>();
	print_type_info<aaa::A>();
	print_type_info<const char**>();
	print_type_info<const char* const *>();
	print_type_info<char const * const *>();
	
	return 0;
}