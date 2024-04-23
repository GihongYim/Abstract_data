#ifndef __VECTOR_HPP__
#include "iterator.hpp"
#include <memory>
namespace ft
{

template<class T, class Allocator>
class vector_base 
{
private:
    typedef Allocator    allocator_type;
public:

protected:
    allocator_type  _allocator;
    T*              _start;
    T*              _finish;
    T*              _end_of_storage;

    vector_base(const allocator_type& alloc) 
        : _allocator(alloc), _start(0), _finish(0), _end_of_storage(0)
    { }


};

template<class T, class Allocator = std::allocator<T> >
class vector : protected vector_base<T, Allocator>
{
private:
    typedef vector_base<T, Allocator>       _base;
public:
    typedef T                               value_type;
    typedef Allocator                       allocator_type;
    typedef std::size_t                     size_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef T&                              reference;
    typedef const T&                        const_reference;
    typedef T*                              pointer;
    typedef const T*                        const_pointer;
    // typedef ft::iterator<T>                 iterator;
    // typedef const ft::iterator<T>           const_iterator;
    typedef ft::reverse_iterator<T>         reverse_iterator;
    typedef const ft::reverse_iterator<T>   const_reverse_iterator;
    
protected:
    using _base::_allocator;
    using _base::_start;
    using _base::_finish;
    using _base::_end_of_storage;
public:
    vector(const allocator_type& alloc=Allocator())
        : _base(alloc)
    { }
    
    explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator())
        : _base(alloc) 
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

    // vector(const vector<T, Allocator>& other)
    // {
    //     _allocator = other.get_allocator();
    //     size_type size = other.size();
    //     _start = _allocator.allocate(size);
    //     _finish = _start;
    //     for (size_type i = 0; i < size; i++) {
    //         *_finish = other[i];
    //         _finish++;
    //     }
    //     _end_of_storage = _finish;
    // }
    size_type size() const
    {
        return static_cast<size_type>(_finish - _start);
    }


    // iterator begin() {
    //     return iterator(_start);
    // }

    // reference operator[] (size_type __n) {
    //     return *(begin() + __n);
    // }
    
    // const_reference operator[] (size_type __n) const {
    //     return *(begin() + __n);
    // }

    // reference front() {
    //     return *begin();
    // }

};
}

#endif