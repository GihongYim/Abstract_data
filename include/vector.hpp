#include <vector>
#include <memory>
#include <iostream> //for debugging

namespace ft {

template <class _Tp, class Allocator=std::allocator<_Tp>>
class vector 
{
public :
    typedef _Tp                     v
    alue_type;
    typedef size_t                  size_type;
    typedef value_type&             reference;
    typedef typename _Alloc_trait<_Tp, Allocator>::allocator_type   allocator_type

protected:
    allocator_type  _data_allocator;
    _Tp*            _start;
    _Tp*            _finish;
    _Tp*            _end_of_storage;

public:
    vector() : _data(NULL), _size(0), _capacity(0) { }
    vector(int _n) : _size(0), _capacity(_n) {
        _data = new _Tp[_n];
    }

    void    push_back(reference element) {
        if (_size == _capacity) {
            // capacity is full
            _capacity *= 2;
            _Tp * newData = new _Tp[_capacity];
            for (int i = 0; i < _size; i++) {
                newData[i] = _data[i];
            }
            delete _data;
            _data = newData;
        }
        _data[_size++] = element;
    }

    void    push_back(const _Tp& element) {
        if (_size == _capacity) {
            // capacity is full
            _capacity *= 2;
            _Tp * newData = new _Tp[_capacity];
            for (size_t i = 0; i < _size; i++) {
                newData[i] = _data[i];
            }
            delete _data;
            _data = newData;
        }
        _data[_size++] = element;
    }

    void    pop_back() {
        if (_size == 0)
            return;
        _size--;
    }

    size_type   size() const {
        return _size;
    }
    reference  operator[](size_type __n) {
        if (__n >= _size) {
            std::cerr << "out of index" << std::endl;
            return _data[__n];
        }
        return _data[__n];
    }

};

};