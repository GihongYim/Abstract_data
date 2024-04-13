#include <cstddef>

namespace ft
{
template<class Iter>
    struct iterator_traits {
        typedef Iter::difference_type   difference_type;
        typedef Iter::value_type        value_type;
        typedef Iter::pointer           pointer;
        typedef Iter::reference         reference;
        typedef Iter::iterator_category iterator_category;
    };

template<class T>
    struct iterator_traits<T*> {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };
template<class T>
    struct iterator_traits<const T*> {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef ft::random_access_iterator_tag  iterator_category;
    };

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