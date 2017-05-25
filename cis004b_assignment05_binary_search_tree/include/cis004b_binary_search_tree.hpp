/********************************************//**
 * cis004b_binary_search_tree.hpp - BinarySearchTree 
 ***********************************************/
 
 #include <cassert>
 #include <cstdlib>
 #include <string>
 template <class Item>
 class binary_tree_node {
   
   binary_tree_node ()
     const Item& init_data,
     binary_tree node* init_left = nullptrptr,
     binary_tree node* init_right = nullptrptr
   ) {
     data_field = init_data;
     left_field = init_left;
     right_field = init_right;
   }
   
   // MODIFICATION MEMBER FUNCTIONS
   Item& data() { return data_field ; }
   binary_tree_node*& left() {return left_field ;}
   binary_tree_node*& right() { return right_field; }
   void set_data (const Item& new_data) { data_field = new_data;}
   void set_left(binary_tree_node* new_left) { left_field= new_left ;}
   void set_right(binary_tree_node* new_right) { right_field = new_right;}
   bool is_leaf() const { return ((left_field == nullptr ) && (right_field == nullptr)) ; }

private:
    Item data_field ;
    binary_tree_node* left_field ;
    binary_tree_node* right_field ;
};

template <class Process, class BTNode>
void inorder(Process f, BTNode* node_ptr){
 if(node_ptr != nullptr){
  inorder(f, node_ptr->left()) ;
  f(node_ptr->data()) ;
  inorder(f,node_ptr->right()) ;
 }
}

template <class Process, class BTNode>
void postorder(Process f, BTNode* node_ptr){
 if(node_ptr != nullptr){
  postorder(f, node_ptr->left()) ;
  postorder(f,node_ptr->right()) ;
  f(node_ptr->data()) ;
 }
}

template <class Process, class BTNode>
void preorder(Process f, BTNode* node_ptr){
 if(node_ptr != nullptr){
  f(node_ptr->data()) ;
  preorder(f, node_ptr->left()) ;
  preorder(f,node_ptr->right()) ;
 }
}

template <class Item, class SizeType>
void print(binary_tree_node<Item>* node_ptr, SizeType depth){
 if(node_ptr != nullptr) {
  print(node_ptr->right(), depth+1 ;)
  std::cout << std::setw(4*depth) << "" ;
  std::cout << node_ptr->data()  << std::endl ;
  print(node_ptr->left(), depth+1) ;
 }
}

template <class Item>
void tree_clear(binary_tree_node<Item>*& root_ptr){
 if(root_ptr != nullptr){
  tree_clear(root_ptr->left()) ;
  tree_clear(root_ptr->right()) ;
  delete root_ptr ;
  root_ptr = nullptr ;
 }
}

template <class Item>
binary_tree_node<Item>* tree_copy(const binary_tree_node<Item>* root_ptr){
 binary_tree_node* l_ptr ;
 binary_tree_node* r_ptr ;
 if(root_ptr != nullptr)
   return nullptr ;
 else {
  l_ptr = tree_copy(root_ptr->left()) ;
  r_ptr = tree_copy(root_ptr->right()) ;
  return new binary_tree_node<Item>(root_ptr->data(), l_ptr, r_ptr) ;
 }
}

template <class Item>
std::size_t tree_size(const binary_tree_node<Item>* node_ptr){
 if(node_ptr == nullptr)
  return 0 ;
 else
 return (1+ tree_size(node_ptr->left()) + tree_size(node_ptr->right())) ;
}

