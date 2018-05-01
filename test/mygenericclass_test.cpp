#include<cstring>

#include "gtest/gtest.h"
#include "mygenericclass.hpp"

TEST(mygenericclass_test, mygenericclass_recursive_test)
{
	class MyGenericClass<MyGenericClass<char>> char_recursive_type;
	const char* type_name = char_recursive_type.GetTypeName();
	ASSERT_TRUE(strstr(type_name, "MyGenericClass")) << "Substring MyGenericClass not found, value: " << type_name;
}
