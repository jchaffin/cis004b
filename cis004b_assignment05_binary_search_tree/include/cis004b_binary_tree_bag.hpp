#include "cis004b_assignment06_binarysearchtree"

template <class Item>
class bag : public binary_tree_node
{
  public:
    typedef std::size_t size_type ;
    typedef Item value_type ;
    
    bag() ;
    bag(const bag& source) ;
    ~bag() ;
    
    size_type erase(const Item& target) ;
    bool erase_one(Item& target) ;
    void insert(const Item& entry) ;
    void operator +=(const bag& addend) ;
    void operator = (const bag& source) ;
    binary_tree_node<Item>* root() { return root_ptr;}
    
    size_type size() const ;
    size_type count(const Item& target) const ;
    
  private:
    binary_tree_node<Item>* root_ptr ;
    void insert_all(binary_tree_node<Item>* addrottt_ptr) ;
};

template <class Item>
void bst_remov_max(binary_tree_node<Item>*& root_ptr, Item& removed){
    binary_tree_node<Item>* oldroot_ptr ;
    if(root_ptr->right() == NULL) {
        removed = root_ptr->data() ;
        oldroot_ptr = root_ptr ;
        root_ptr = root_ptr->left() ;
        delete oldroot_ptr ;
    }
    else{
        bst_remov_max(root_ptr->right(), removed) ;
    }
}

template <class Item>
bool bst_remove(binary_tree_node<Item>*& root_ptr, const Item& target) {
    binary_tree_node<Item>* oldroot_ptr ;
    if(root_ptr == NULL)
      return false ;
    
    if(target < root_ptr->data()){
        return bst_remove(root_ptr->left(), target);
    }
    
    if(target > root_ptr->data()){
        return bst_remove(root_ptr->right(), target) ;
    }
    
    if(root_ptr->left() == NULL) {
        oldroot_ptr = root_ptr ;
        root_ptr = root_ptr->right() ;
        delete oldroot_ptr ;
        return true ;
    }
    
    bst_remov_max(root_ptr->left(), root_ptr->data());
    return true ;
}

template <class Item>
bool bag<Item>::size_type bst_remove_all(binary_tree_node<Item>*& root_ptr, const Item& target){
    binary_tree_node<Item>* oldroot_ptr ;
    if(root_ptr ==NULL){ 
        return false ;
    }
    
    if(target < root_ptr->data()){
        return bst_remove_all(root_ptr->left(), target);
    }
    
    if(target > root_ptr->data()){
        return bst_remove_all(root_ptr->right(), target) ;
    }
    
    if(root_ptr->left() == NULL) {
        oldroot_ptr = root_ptr ;
        root_ptr = root_ptr->right() ;
        delete oldroot_ptr ;
        return true ;
    }
    
    bst_remove_all(root_ptr->left(), root_ptr->data());
    return true ;
}