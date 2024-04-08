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
    iterator    begin() 
        { return iterator (_start); }

    const_iterator    begin() const
        { return const_iterator (_start); }

    iterator    end() 
        { return iterator (_finish); }

    const_iterator    end() const
    { return const_iterator(_finish)}


    reverse_iterator    rbegin()
        { return reverse_iterator(end())};

    const_reverse_iterator    rbegin() const
        { return const_reverse_iterator(end())};

    reverse_iterator    rend()
        { return reverse_iterator(begin())};

    const_reverse_iterator    rend() const
        { return const_reverse_iterator(begin())};


    size_type   size() const 
        { return size_type(end() - begin());}
    
    size_type   max_size() const
        { return size_type(-1) / sizeof(_Tp); }
    
    size_type   capacity() const
        { return size_type(const_iterator(_end_of_storage) - begin()); }
    

    bool empty() const
        { return begin() == end();}

    reference   operator[] (size_type __n) { return *(begin() + __n); }

    const_reference   operator[] (size_type __n) const { return *(begin() + __n); }

    void    _range_check(size_type __n) const {
        if (__n >= this->size()) 
            _throw_out_of_range("vector");
    }

    reference   at(size_type __n)
        {_range_check(__n) return (*this)[__n];}

    const_reference   at(size_type __n) const
        {_range_check(__n) return (*this)[__n];}

    
    explicit vector(const allocator_type& __a = allocator_type()) 
        : _base(__a){ }

    vector(size_type __n, const _Tp& __value,
        const allocator_type& __a = allocator_type())
        : _base(__n, __a)
        { _finish = uninitialized_fill_n(_start, __n, __value); }
    
    explicit    vector(size_type __n)
        : _base(__n, allocator_type())
        { _finish = uninitialized_fill_n(_start, __n, _Tp()); }

    vector(const vector<_Tp, Alloc>& __x)
        : _base(__x.size(), __x.get_allocator())
        { _finish = uninitialized_copy(__x.begin(), __x.end(), _start); }
    
    template <class _InputIterator>
        vector(_InputIterator __first, _InputIterator __last,
            const allocator_type& __a = allocator_type())
            : _base(_a)
            {
                typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
                _initialize_aux(__first, __last, _Integral());
            }
    
    template <class _Integer>
        void _initialize_aux(_Integer __n, _Integer __value, __true_type)
        {
            _start = _allocate(__n);
            _end_of_storage = _start + __n;
            _finish = uninitialized_fill_n(_start, __n, __value);
        }

    template<class _InputIterator>
        void _initialize_aux(_InputIterator __first, _InputIterator __last, __false_type)
        {
            typedef typename iterator_trait<_InputIterator>::iterator_category  _IterCategory;
            _range_initialize(__first, __last, _IterCategory());
        }
    
    ~vector()
    { _Destroy(_start, _finish); }
    
    vector<_Tp, _Alloc>& operator=(const vector<_Tp, _Alloc>& __x);

    void reverse(size_type __n) {
        
    }

};

}
