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

    allocator_type get_allocator() 
    {
        return _allocator;
    }
    vector() 
    : _allocator(Allocator), _start(0), _finish(0), _end_of_storage(0)
    { }

    vector(allocator_type alloc=Allocator) 
    : _allocator(alloc), _start(0), _finish(0), _end_of_storage(0)
    { }

    vector(const allocator_type alloc=Allocator) 
    : _allocator(alloc), _start(0), _finish(0), _end_of_storage(0)
    { }
    
    vector(size_type count, const T& value = T(), const Allocator&alloc = Allocator())
    : _allocator(alloc)
    {
        _allocator = alloc;
        _start = _alloc.allocate(count);
        _finish = _start;
        _end_of_storage = _start + count;
        for (int i = 0; i < count; i++) {
            *(_start + i) = value;
        }
    }
    vector(size_type count)
    : _allocator(alloc)
    {
        _start = _alloc.allocate(count);
        _finish = _start;
        _end_of_storage = _start + count;
        for (int i = 0; i < count; i++) {
            *(_start + i) = value;
        }
    }
    template< class InputIt >
    vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ) 
    {

    }

    vector(const vector& other) 
    {

    }
    
    ~vector()
    {
        _alloc.deallocate(_start, _end_of_storage - _start);
    }

    vector& operator=(const vector& other)
    {
        _new_vector = vector(other.size());
        for (int i = 0; i < other.size(); i++) {
            _new_vector[i] = other[i];
        }
    }
    void assign(size_type count, count T& value)
    {
        if (_start) {
            _alloc.deallocate(_start, _end_of_storage - _start);
        }
        _start = _alloc.allocate(count);
        _finish = _start;
        _end_of_storage = _start + count;
        for (int i = 0; i < count; i++) {
            *(_start + i) = value;
        }
    }

    template<class InputIt>
    void assign(InputIt first, InputIt last) 
    {

    }

    reference at(size_type pos) {
        if (pos >= this->size()) 
            throw out_of_index;
        return *(_start + pos);
    }

    const_reference at(size_type pos) const{
        if (pos >= this->size()) 
            throw out_of_index;
        return *(_start + pos);
    }
    reference operator[](size_type pos) {
        if (pos >= this->size()) 
            throw "out_of_index";
        return *(_start + pos);
    }

    reference front() {
        if (_start) {
            return *(_start);
        } else {
            throw "vector is empty";
        }
    }

    const_reference front() {
        if (_start) {
            return *(_start);
        } else {
            throw "vector is empty";
        }   
    }
    const_reference operator[](size_type pos) const {
        if (pos >= this->size()) 
            throw out_of_index;
        return *(_start + pos);
    }


    size_t  size() {
        return (_end_of_storage - _start);
    }
    
};
}