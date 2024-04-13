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
    using _base::_allocate;
    using _base::_dallocate;
    using _base::_start;
    using _base::_finish;
    using _base::_end_of_storage;

public:

    iterator begin() {
         return iterator(_start);
    }
    const_iterator begin() const {
         return const_iterator(_start);
    }
    iterator end() {
        return iterator(_finish);
    }
    const_iterator end() const {
        return const_iterator(_finish);
    }
    reverse_iterator rbegin() {
        return reverse_iterator(end());
    }
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(end());
    }
    iterator rend() {
        return iterator(begin());
    }
    const_iterator rend() const {
        return const_iterator(begin());
    }
    size_type size() const {
        return size_type(end() - begin());
    }

    size_type capacity() const {
        return size_type(const_iterator(_end_of_storage) - begin());
    }

    bool empty() const {
        return begin() == end();
    }

    reference   operator[](size_type __n) {
        return *(begin() + __n);
    }

    const_reference   operator[](size_type __n) const {
        return *(begin() + __n);
    }

    reference at(size_type __n) {
        if (__n >= this->size())
            throw "vector: out of range";
        return (*this)[__n];
    }

    const_reference at(size_type __n) const {
        if (__n >= this->size())
            throw "vector: out of range";
        return (*this)[__n];
    }

    explicit vector(const Allocator& alloc=allcator_type()) 
        : _base(alloc) { }
    
    explicit vector(size_type count, const T& value = T(), const Allocator& alloc = Allocator()) 
        : _base(alloc)
    {
        _start = _allocate(count);
        _finish = _start;
        _end_of_storage = _start + count;
    }

    explicit vector(size_type count) {
        _start = _allocate(count);
        _finish = _start;
        _end_of_storage = _start + count;
    }
    template<class InputIt>
        vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
            :_base(alloc) {

    }

    vector(const vector& other); {
        //iterator needed
    }

    vector(vector&& other) {
        //iterator needed
    }

    ~vector() {
        _deallocate(_start, _end_of_storage - _start);
    }

    vector& operator=(const vector& other) {
        vector newVector = vector(other);
        return newVector;
    }

    

};

}