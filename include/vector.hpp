#include <memory>

namespace ft
{
template<class T, class Allocator>
class vector_alloc_base
{
protected:
    typedef Allocator   allocator_type;
public:
    allocator_type _alloc;

    vector_alloc_base() { }

    vector_alloc_base(allocator_type& __a) _alloc(__a)

};


template<class T, class Allocator>
class vector_base : public vector_alloc_base<T, Allocator>
{
protected:
    typedef T                               value_type;
    typedef std::size_t                     size_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef value_type&                     reference;
    typedef const value_type&               const_reference;
    typedef Allocator::pointer              pointer;
    typedef Allocator::const_pointer        const_pointer;
    typedef 

public:

};
template<class T, class Allocator=std::allocator<T>>
class vector : public vecto_base<T, Allocator>
{
protected:

public:

};

}