#include <stdexcept>
#include <vector>

template<class T, class Compare = std::less<T>>
class fibonacci_queue {
private:
  struct node {
    T value;
    node* parent;
    node* child;
    node* left;
    node* right;
    bool marked;
    int rank;
  };
  size_t num_nodes = 0;
  size_t num_freed = 0;
  node* freed = NULL;
  node* min = NULL;
  
  int block_size = 1000;
  
  std::vector<node*> allocations;
  void reserve_more() {
    // Get a block of nodes
    node* alloc = new node[block_size];
    allocations.push_back(alloc);
    for( int i = 0; i < block_size; ++i ) {
      // Add to free list
      free_node(&alloc[i]);
    }
  }
  void free_node(node* n) {
    if( num_freed == 0 ) {
      // Create freed list
      freed = n;
      freed->left = freed->right = freed;
      freed->parent = freed->child = NULL;
      freed->rank = 0;
    } else {
      // Add to freed list
      insert_child_list(n, freed);
      n->rank = 0;
      n->child = NULL;
    }
    // Update counter
    num_freed++;
  }
  
  void insert_child_list(node* n, node* sibling) {
    // Connect to left of sibling
    sibling->left->right = n;
    n->left = sibling->left;
    sibling->left = n;
    n->right = sibling;
    
    // Update parent pointer
    n->parent = sibling->parent;
    if( n->parent != NULL ) {
      // Update children counter
      n->parent->rank++;
    }
  }
  void remove_child_list(node* n) {
    // Connect neighbors
    n->left->right = n->right;
    n->right->left = n->left;
    
    if( n->parent != NULL ) {
      // Reduce children count
      n->parent->rank--;
      // Update child pointer
      if( n->parent->child == n ) {
        if( n == n->right ) {
          n->parent->child = NULL;
        } else {
          n->parent->child = n->right;
        }
      }
    }
  }
  void insert_root_list(node* n) {
    n->marked = false;
    if( min == NULL ) {
      // Create root list
      min = n;
      n->left = n;
      n->right = n;
      n->parent = NULL;
    } else {
      // Add to root list
      insert_child_list(n, min);
      if( Compare()(n->value, min->value) ) {
        min = n;
      }
    }
  }
public:
  size_t size() {
    return num_nodes;
  }
  
  // O(1)
  T find_min() {
    if( num_nodes == 0 ) {
      throw std::runtime_error("No min");
    }
    return min->value;
  }
  
  // O(logn)
  void remove_min() {
    if( num_nodes == 0 ) {
      throw std::runtime_error("No min");
    }
    // Save previous min, take random root list node
    node* prev_min = min;
    if( min->right == min ) {
      min = NULL;
    } else {
      min = min->right;
      remove_child_list(prev_min);
    }
    
    // Put previous min's children on root list
    if( prev_min->rank != 0 ) {
      node* prev_min_child = prev_min->child;
      node* cur_child = prev_min_child->right;
      while( cur_child != prev_min_child ) {
        node* next_child = cur_child->right;
        insert_root_list(cur_child);
        cur_child = next_child;
      }
      insert_root_list(prev_min_child);
    }
    
    // Create ranks array
    int lg2 = 0;
    while( (1 << lg2) <= num_nodes ) {
      lg2++;
    }
    std::vector<node*> ranks(4 * lg2, NULL);
    
    // Consolidate root list if it exists
    if( min != NULL ) {
      // Iterate over root list
      node* cur_root = min;
      do {
        // Consider processing node, and move cur
        node* process = cur_root;
        cur_root = cur_root->right;
        
        // While two trees with the same rank exist
        while( ranks[process->rank] != NULL ) {
          int rank = process->rank;
          // Make ranks[rank] <= process
          if( Compare()(process->value, ranks[rank]->value) ) {
            node* temp = ranks[rank];
            ranks[rank] = process;
            process = temp;
          }
          // Make process a child of ranks[rank]
          if( rank == 0 ) {
            process->parent = ranks[rank];
            ranks[rank]->child = process;
            ranks[rank]->rank++;
            process->left = process->right = process;
          } else {
            insert_child_list(process, ranks[rank]->child);
          }
          // process next rank
          process = ranks[rank];
          // no more trees of that rank
          ranks[rank] = NULL;
        }
        // Save process's rank
        ranks[process->rank] = process;
      } while( cur_root != min );
    }
    
    // Populate root list
    min = NULL;
    for( node* n : ranks ) {
      if( n != NULL ) {
        insert_root_list(n);
      }
    }
    
    // Update counter, and free prev_min
    remove_mins++;
    num_nodes--;
    free_node(prev_min);
    //std::cout << "REMOVEMIN" << std::flush;
    //print();
  }
  
  int inserts = 0;
  int remove_mins = 0;
  
  // O(1)
  void* insert(T value) {
    inserts++;
    node* n;
    // Allocate nodes if necessary
    if( num_freed < 2 ) {
      reserve_more();
    }
    // Get free node from free list
    remove_child_list(freed);
    n = freed;
    freed = freed->right;
    num_freed--;
    
    // Initialize and insert new node into root list
    n->child = NULL;
    n->rank = 0;
    n->value = value;
    insert_root_list(n);
    
    // Update counter, and return handle
    num_nodes++;
    //std::cout << "INSERT" << std::flush;
    //print();
    return (void*)n;
  }
  
  // O(1)
  void decrease_key(void* n_void, T value) {
    node* n = (node*)n_void;
    // Make sure node decreases
    if( Compare()(n->value, value) ) {
      throw std::runtime_error("Increased key");
    }
    // Update value
    n->value = value;
    
    // If heap property breaks (or is equal to parent, for remove to work on multiple min entries)
    if( n->parent != NULL && !Compare()(n->parent->value, n->value) ) {  
      // Cut node
      node* ancestor = n->parent;    
      remove_child_list(n);
      insert_root_list(n);
      
      // While ancestor is marked, keep cutting
      while( ancestor != NULL && ancestor->parent != NULL && ancestor->marked ) {
        node* next_ancestor = ancestor->parent;
        remove_child_list(ancestor);
        insert_root_list(ancestor);
        ancestor = next_ancestor;
      }
      // Make the unmarked ancestor
      if( ancestor != NULL ) {
        ancestor->marked = true;
      }
    }
    
    //std::cout << "DECKEY" << std::flush;
    //print();
  }
  
  // O(logn)
  void remove(void* n_void) {
    // Make the node min, then remove it
    decrease_key(n_void, min->value); // Will put on root list even if tied
    min = (node*)n_void;
    remove_min();
  }
  
  ~fibonacci_queue() {
    // Free allocated memory
    for( node* alloc : allocations ) {
      delete[] alloc;
    }
  }
  
  /*
  void print() {
    std::cout << "START FIB OUTPUT\n";
    std::cout << "FREE NODE: " << freed << "\n";
    std::cout << "ROOT LIST: " << min << std::flush;
    if( min != NULL ) {
      for( node* cur = min->right; cur != min; cur = cur->right ) {
        std::cout << " -- " << cur << std::flush;
      }
    }
    std::set<node*> freed_nodes;
    if( freed != NULL ) {
      freed_nodes.insert(freed);
      node* cur = freed->right;
      while( cur != freed ) {
        freed_nodes.insert(cur);
        cur = cur->right;
      }
    }
    std::cout << "\n";
    std::cout << "CONNECIONS:\n";
    for( node* alloc : allocations ) {
      for( int i = 0; i < block_size; i++ ) {
        node n = alloc[i];
        if( !freed_nodes.count(&alloc[i]) )
          std::cout << "id = " << &alloc[i] << ", value = (" << n.value.first << ", " << n.value.second << "), parent = " << n.parent << ", child = " << n.child
        << ", left = " << n.left << ", right = " << n.right << ", marked = " << n.marked << ", rank = " << n.rank << "\n";
      }
    }
    std::cout << std::endl;
  }
  */
};
