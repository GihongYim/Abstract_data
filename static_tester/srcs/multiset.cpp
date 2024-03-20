#include "templates/associative_container.tpp"
#include "templates/container.tpp"
#include "templates/reversible_container.tpp"
#include "templates/bidirectional_iterator.tpp"
#include "utils/basic_type.hpp"
#include <set>
#include "set.hpp"

void test_map()
{
	using Key = basic_type;
	using ValueType = basic_type;
	using Compare = basic_type::compare;
	using Allocator = std::allocator <ValueType>;
	using X = NAMESPACE::multiset<ValueType, Compare>;
	Key k;
	ValueType t;

	container<NAMESPACE::multiset<int>, int>();

	reversible_container<X, ValueType>();

	bidirectional_iterator<typename X::iterator, ValueType>(t);
	bidirectional_iterator<typename X::reverse_iterator, ValueType>(t);

	associative_containers<
			X,
			Key,
			ValueType,
			Compare,
			Allocator,
			false
	>(t, k);

}