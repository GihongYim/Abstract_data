#include <memory>

namespace ft
{
template<class T, class Allocator>
class vector_alloc_base
{
public:
    typedef typename _Alloc_traits<T, Allocator>::allocator_type
        allocator_type;
    allocator_type  get_allocator() {return _allocator;}

    // vector_alloc_base() { }
    // vector_alloc_base(allocator_type& __a) _allocator(__a)

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
public:
typedef vector_alloc_base<T, Allocator> _base;
    vector_base(const allocator_type& __a) : _base(__a) {}
    vector_base(size_t __n, const allocator_type& __a) : _base(__a) {
        _start = _allocate(__n);
        _finish = _start;
        _end_of_storage = _start + __n;
    }

    ~vector_base() {
        _deallocate(_start, _end_of_storage - _start);
    }
};


template<class T, class Allocator=std::allocator<T>>
class vector : public vector_base<T, Allocator>
{
private:
    typedef vector_base<T, Allocator> _base;
    typedef vector<T, Allocator> vector_type;

public:
    typedef T                               value_type;
    typedef value_type*                     pointer;
    typedef const value_type*               const_pointer;
    typedef iterator<pointer, vector<T, Allocator> >    
                                            iterator;
    typedef iterator<const_pointer, vector<T, Allocator> >
                                            const_iterator;
    typedef value_type&                     reference;
    typedef const value_type&               const_reference;
    typedef std::size_t                     size_type;
    typedef std::ptrdiff_t                  difference_type;

    typedef typename _base::allocator_type allocator_type;
    allocator_type get_allocator() const { return _base::get_allocator();}

    typedef reverse_iterator<const iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;

protected:
    using _base::allocate;
    using _base::dallocate;
    using _base::_start;
    using _base::_finish;
    using _base::_end_of_storage;

public:
    vector() {

    }

    explicit vector(const Allocator& alloc) {

    }

    explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) {

    }

    explicit vector(size_type count) {

    }
    template<class InputIt>
    vector(InputIt first, InputIt last, const Allocator& alloc = Allocator()) {

    }

    vector(const vector& other ); {

    }

    vector(vector&& other) {

    }

    ~vector() {}


};

}