namespace ft
{
 
template<class Iter>
struct iterator_traits
{

};

template <class T>
struct reverse_iterator
{

};

template <class Category, class T, class Distance = std::ptrdiff_t,
            class Pointer = T*, class Reference = T&>
struct iterator
{
private:

public:
    typedef Category    iterator_category;
    typedef T           value_type;
    typedef Distance    difference_type;
    typedef Pointer     pointer;
    typedef Reference   reference;

};
}