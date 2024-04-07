#include <memory>

namespace ft 
{

template <class _Tp, class _Allocator>
class _vector_alloc_base {
public:
    typedef typename alloc_trait<allocator<_Tp>>::allocator_type
        allocator_type;
    
protected:

}

};