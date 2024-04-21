#ifndef __VECTOR_HPP__
#include "iterator.hpp"
#include <memory>
namespace ft
{

template<class T, class Allocator = std::allocator<T> >
class vector
{
public:
    typedef T                               value_type;
    typedef Allocator                       allocator_type;
    typedef std::size_t                     size_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef T&                              reference;
    typedef const T&                        const_reference;
    typedef T*                              pointer;
    typedef const T*                        const_pointer;
    typedef ft::iterator<T>                 iterator;
    typedef const ft::iterator<T>           const_iterator;
    typedef ft::reverse_iterator<T>         reverse_iterator;
    typedef const ft::reverse_iterator<T>   const_reverse_iterator;
private:
    allocator_type      _allocator;
    pointer             _start;
    pointer             _finish;
    pointer             _end_of_storage;
public:

    allocator_type get_allocator() 
    {
        return _allocator;
    }
    vector(const allocator_type& alloc=Allocator())
        : _allocator(alloc), _start(0), _finish(0), _end_of_storage(0) { }
    
    explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
        : _allocator(alloc) 
    {
        _start = _allocator.allocate(count);
        _end_of_storage = _start + count;
        for (size_type i = 0; i < count; i++)
            *(_start + i) = value;
    }

    // template< class InputIt >
    // vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() )
    //     : _allocator(alloc)
    // {
    //     size_type _n = InputIt.distance(first, last);
    //     size_type index = 0;
    
    //     _start = _allocator.allocate(_n);
    //     while (first != last) {
    //         *(_start + index) = *first;
    //         index++;
    //         first++;
    //     }
    //     _finish = _start + _n;
    //     _end_of_storage = _finish;
    // }

    vector(const vector& other)
        : _allocator(other.get_allocator())
    {
        size_type size = other.size();
        _start = _allocator.allocate(other.size());
        _finish;
        for (size_type i = 0; i < size; i++) {
            *_finish = other[i];
            _finish++;
        }
        _end_of_storage = _finish;
    }
};
}

#endif