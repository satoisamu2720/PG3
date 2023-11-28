#pragma once
template <typename Type1, typename Type2>

class Pair
{
public:

	Pair(Type1 type1, Type2 type2) : num1(type1), num2(type2) {}

	template<typename Type>
	Type Min()
	{
		Type type1 = static_cast<Type>(num1);
		Type type2 = static_cast<Type>(num2);
		return type1 < type2 ? type1 : type2;
	}

	Type1 num1;
	Type2 num2;
};