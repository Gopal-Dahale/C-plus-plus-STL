// header files
#include <ext/pb_ds/assoc_container.hpp> // common file
#include <ext/pb_ds/tree_policy.hpp>
// including tree_order_statistics_node_update

using namespace __gnu_pbds;

// declaration of tree based container

template <

    // key type
    typename Key,

    // mapped policy
    // null type policy => set
    // null map type policy => map
    typename Mapped,

    // key comparison functor
    typename Cmp_Fn = std::less<Key>,

    // specifies which underlying data structure to use
    typename Tag = rb_tree_tag,

    template <
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn,
        typename Allocator_>

    // a policy for updating the node invariants
    class Node_Update = null_node_update,

    // an allocator type
    typename Allocator = std::allocator<char>>

class exampleTree; // this is actually class tree but written exampleTree to avoid ambiguity

// a new data structure defined.
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

/*
    tree structures

    rb_tree_tag             (red black tree)
    splay_tree_tag          (splay tree)
    ov_tree_tag             (ordered vector tree)

*/
