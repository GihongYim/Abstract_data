#include <memory>

namespace ft
{
template<class T, class Allocator>
class vector_alloc_base
{
public:
    typedef typename _Alloc_traits<T, Allocator>::allocator_type
        allocator_type;
    vector_alloc_base() { }
    vector_alloc_base(allocator_type& __a) _allocator(__a)

    allocator_type  get_allocator() {return _allocator;}
    vector_alloc_base(const allocator_type& __a)
        : _allocator(__a), _start(0), _finish(0), _end_of_storage(0)
    {}

protected:
    allocator_type _allocator;
    T*  _start;
    T*  _finish;
    T*  _end_of_storage;

    T*  _allocate(size_t __n) {
        return _allocator.allocate(__n);
    }

    void _deallocate(T* __p, size_t __n) {
        if (__p)
            _allocator.deallocate(p, __n);
    }

};


template<class T, class Allocator>
class vector_base : public vector_alloc_base<T, Allocator>
{
protected:
    

public:

};
template<class T, class Allocator=std::allocator<T>>
class vector : public vecto_base<T, Allocator>
{
protected:

public:
    typedef T                               value_type;
    typedef std::size_t                     size_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef value_type&                     reference;
    typedef const value_type&               const_reference;
    typedef Allocator::pointer              pointer;
    typedef Allocator::const_pointer        const_pointer;
    typedef iterator
};

}