#include <iostream>

using namespace std;

template<typename T>
class set {
public:
  set(size_t (*hash)(const T&), double load_factor = 0.75) {
    m_hash = hash;
    m_elems = 0;
    m_capacity = 0;
    m_buckets = nullptr;
    m_load_factor = load_factor;
  }
  ~set() {
    clear();
  }
  size_t size() {
    return m_elems;
  }
  void insert(T elem) {
    if( m_capacity == 0 )
      ensure(1/m_load_factor + 1);
    int h = m_hash(elem) % m_capacity;
    node* start = m_buckets[h];
    if( start == nullptr ) {
      m_buckets[h] = new node;
      m_buckets[h]->value = elem;
      m_buckets[h]->next = nullptr;
    } else {
      while( start->next != nullptr ) {
        if( start->value == elem )
          return;
        start = start->next;
      }
      if( start->value == elem )
        return;
      start->next = new node;
      start = start->next;
      start->value = elem;
      start->next = nullptr;
    }
    m_elems++;
    cout << "Inserting " << m_elems << "th element: " << elem << " (hash: " << h << ")" << endl;
    if( m_elems > m_load_factor * m_capacity ) {
      ensure(m_capacity << 1);
    }
  }
  bool contains(T elem) {
    int h = m_hash(elem) % m_capacity;
    node* start = m_buckets[h];
    while( start != nullptr ) {
      if( start->value == elem ) {
        cout << "Contains " << elem << endl;
        return true;
      }
      start = start->next;
    }
    cout << "Does not contain " << elem << endl;
    return false;
  }
  void erase(T elem) {
    int h = m_hash(elem) % m_capacity;
    node* prev = m_buckets[h];
    node* start = m_buckets[h];
    while( start != nullptr ) {
      if( start->value == elem ) {
        if( prev == start ) {
          m_buckets[h] = start->next;
        } else {
          prev->next = start->next;
        }
        delete start;
        cout << "Removing " << m_elems << "th element: " << elem << " (hash: " << h << ")" << endl;
        m_elems--;
        return;
      }
      prev = start;
      start = start->next;
    }
  }
  void clear() {
    m_elems = 0;
    m_capacity = 0;
    if( m_buckets != nullptr ) {
      for( size_t i = 0; i < m_capacity; ++i ) {
        node* start = m_buckets[i];
        while( start != nullptr ) {
          node* del = start;
          start = start->next;
          delete del;
        }
      }
      delete[] m_buckets;
      m_buckets = nullptr;
    }
  }
private:
  struct node {
    T value;
    node* next;
  };

  node** m_buckets;
  size_t m_capacity;
  size_t m_elems;
  double m_load_factor;
  
  size_t (*m_hash)(const T&);
  
  void ensure(size_t size) {
    if( size <= m_capacity )
      return;
    cout << "Resize to: " << size << endl;
    node** old_buckets = m_buckets;
    int old_capacity = m_capacity;
    
    m_elems = 0;
    m_capacity = size;
    m_buckets = new node*[m_capacity];
    for( size_t i = 0; i < m_capacity; ++i ) {
      m_buckets[i] = nullptr;
    }
    for( size_t i = 0; i < old_capacity; ++i ) {
      node* start = old_buckets[i];
      while( start != nullptr ) {
        insert(start->value);
        start = start->next;
      }
    }
    if( old_buckets != nullptr ) {
      for( size_t i = 0; i < old_capacity; ++i ) {
        node* start = old_buckets[i];
        while( start != nullptr ) {
          node* del = start;
          start = start->next;
          delete del;
        }
      }
      delete[] old_buckets;
    }
  }
};

int main() {
  set<int> vals([](const int& a) -> size_t {
    return a;
  } );
  
  vals.insert(5);
  vals.insert(5);
  vals.insert(2);
  vals.insert(102);
  vals.insert(2);
  vals.insert(102);
  
  vals.contains(2);
  vals.contains(23);
  vals.contains(5);
  vals.contains(102);
  vals.contains(202);
  
  vals.erase(102);
  vals.erase(5);
  
  vals.contains(2);
  vals.contains(5);
  vals.contains(102);
  vals.contains(202);
  
  vals.clear();
  
  vals.insert(1);
  vals.contains(1);
  vals.contains(2);
}