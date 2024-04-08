#pragma once

#include <memory>

namespace ft 
{

template <class _Tp, class _Allocator>
class _vector_alloc_base 
{
public:
    typedef typename alloc_trait<allocator<_Tp>>::allocator_type
        allocator_type;

    allocator_type  get_allocator() { return _data_allocator;}

    _vector_alloc_base(const allocator_type& __alloc)
    : _data_allocator(__alloc), _start(0), _finish(0), _end_of_storage(0)
    {}
    
protected:
    allocator_type  _data_allocator;
    _Tp*            _start;
    _Tp*            _finish;
    _Tp*            _end_of_storage;

    _Tp* allocate(size_t __n) {
        return data_allocator.allocate(__n);
    }

    void    _deallocate(_Tp* __p, size_t __n) {
        if (__p) {
            _data_allocator.deallocate(__p, __n);
        }
    }
};
template <class _Tp, class Allocator>
class _vector_base : public _vector_alloc_base<_Tp, Allocator>
{
    typedef _vector_alloc_base<_Tp, Allocator> _base;
    typedef _base::allocator_type allocator_type;

    _vector_base(const allocator_type& __alloc) : _base(__alloc) {}
    _vector_base(size_t __n, const allocator_type& __alloc) : _base(__alloc) {
        _start = allocate(__n);
        _finish = _start;
        _end_of_storage = _start + __n;
    }

    ~_vector_base() { _deallocate(_start, _end_of_storage - _start); }
};

template <class _Tp, class _Alloc=std::allocator<_Tp>>
class vector : protected _vector_base<_Tp, _Alloc>
{
private:
    typedef _vector_base<_Tp, _Alloc> _base;
    typedef vector<_Tp, _Alloc> vector_type;

public:
    typedef _Tp                             value_type;
    typedef value_type*                     pointer;
    typedef const value_type*               const_pointer;
    // typedef __gnu_cxx::__normal_iterator<pointer, vector_type> 	iterator;
    // typedef __gnu_cxx::__normal_iterator<const_pointer, vector_type>

    typedef value_type&                     reference;
    typedef const value_type&               const_reference;
    typedef size_t                          size_type;
    typedef ptrdiff_t                       difference_type;

    typedef typename _base::allcator_type   allocator_type;
    allocator_type  get_allocator() const { return _base::get_allocator();}

    typedef _base::allocator_type   allocator_type;

    typedef reverse_iterator<const_iterator>    const_reverse_iterator;
    typedef reverse_iterator<iterator>          reverse_iterator;

protected:
    using _base::_allocate;
    using _base::_deallocate;
    using _base::_start;
    using _base::_finish;
    using _base::_end_of_storage;

protected:
    void _insert_aux(iterator __position, const _Tp& __x);
    void _insert_aux(iterator __position); 

public:
    iterator    begin() { return iterator (_start); }
    iterator    begin() const { return iterator (_start); }
    iterator    finish() { return iterator(_finish)}
};

}
