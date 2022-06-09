#include "hashmap.hpp"


template <typename K, typename M, typename H >
using value_type = std::pair<const K, M>;

template <typename K, typename M, typename H >
class HashMap<K,M,H>::iterator:public std::iterator<std::input_iterator_tag,value_type> {
    private:
        const HashMap*hashMap;
        bool is_end = true;
        int index = 0;
        node*curr_node = nullptr;
    public:
        iterator(const HashMap*mp,bool end){
			if(end){
				hashMap = mp;
				return;
			}
			hashMap = mp;
			is_end = false;
			for(int i=0;i<hashMap->bucket_count();++i){
				auto curr = hashMap->_buckets_array[i];
				if(curr != nullptr){
					curr_node = curr;
					index = i;
					break;
				}
			}
			if(curr_node == nullptr)
				is_end = true;
		}
        iterator(const iterator&it){
            hashMap = it.hashMap;
            index = it.index;
            is_end = it.is_end;
            curr_node = it.curr_node;
        }
        friend bool operator==(const iterator& lhs,const iterator& rhs){
			if (lhs.is_end && rhs.is_end)
				return true;
			if (lhs.curr_node == rhs.curr_node)
				return true;
			return false;
		}
        friend bool operator!=(const iterator& lhs,const iterator& rhs){
            return !(lhs == rhs);
        }
        value_type& operator*()const{
			return curr_node->value;
        }
        iterator&operator++(){
			if(is_end)
				return *this;
			if(curr_node->next != nullptr){
				curr_node = curr_node->next;
				return *this;
			}
			if(index == hashMap->bucket_count() - 1){
				curr_node = nullptr;
				is_end = true;
				index = 0;
				return *this;
			}
            for(int i=index+1;i<hashMap->bucket_count();++i){
                auto curr = hashMap->_buckets_array[i];
                if(curr != nullptr){
                    curr_node = curr;
                    index = i;
					return *this;
                }
            }
			curr_node = nullptr;
            is_end = true;
			index = 0;
            return *this;
		}
        iterator operator++(int){
			iterator prev(*this);
			++(*this);
			return prev;
		}
        iterator&operator=(iterator&other){
			if(other == *this)
				return *this;
            hashMap = other.hashMap;
            index = other.index;
            is_end = other.is_end;
            curr_node = other.curr_node;
			return *this;
		}
        iterator&operator=(const iterator&other){
            if(other == *this)
                return *this;
            hashMap = other.hashMap;
            index = other.index;
            is_end = other.is_end;
            curr_node = other.curr_node;
            return *this;
		}
        value_type*operator->() const{
            if(curr_node == nullptr)
                throw "error!";
            return &(curr_node->value);
        }
        bool key_equal(const K&key){
            if(is_end||curr_node== nullptr)
                return false;
            return curr_node->value.first == key;
        }
    };


