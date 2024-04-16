#include <memory>

namespace ft
{
template<class T, class Allocator = std::allocator<T> >
class vector
{
public:
    typedef T                           value_type;
    typedef typename Allocator          allocator_type;
    typedef std::size_t                 size_type;
    typedef std::ptrdiff_t              difference_type;
    typedef T&                          reference;
    typedef const T&                    const_reference;
    typedef T*                          pointer;
    typedef const T*                    const_pointer;
    typedef iterator<T>                 iterator;
    typedef const iterator<T>           const_iterator;
    typedef reverse_iterator<T>         reverse_iterator;
    typedef const reverse_iterator<T>   const_reverse_iterator;
private:
    allocator_type      _allocator;
    pointer             _start;
    pointer             _finish;
    pointer             _end_of_storage;
public:

    vector() 
    : _allocator(Allocator), _start(0), _finish(0), _end_of_storage(0)
    { }

    vector(allocator_type alloc=Allocator) 
    : _allocator(alloc), _start(0), _finish(0), _end_of_storage(0)
    { }

    vector(const allocator_type alloc=Allocator) 
    : _allocator(alloc), _start(0), _finish(0), _end_of_storage(0)
    { }
    
    vector(size_type count, const T& value = T(), const Allocator&alloc = Allocator());


};
}