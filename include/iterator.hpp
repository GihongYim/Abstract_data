#include <cstddef>

namespace ft
{
    template<
        class Category,
        class T,
        class Distance = std::ptrdiff_t,
        class Pointer = T*,
        class Reference = T&
    >
    struct iterator
    {
        typedef Category    iterator_category;
        typedef T           value_type;
        typedef _Distance   difference_type;
        typedef _Pointer    pointer;
        typedef _Reference  reference;
    };
}