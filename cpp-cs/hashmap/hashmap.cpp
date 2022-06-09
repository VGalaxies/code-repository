// please learn to reuse your code, especially some basic functions, that's to say if you have implemented == operator, 
// you can just use == to implement != and some other cases. Please be careful about memory allocation.
// you need only need to implement the functions labled with to do.
// copy this file directy to .hpp file(remove the line : #include "hashmap.hpp") if you are using ide like visual studio, otherwise your code will not compile.
// still you don't need to worry about concurrency.
// you can directly submit this file to oj and you can pass the compile phase.


// if you cannot decide the type of a variable, please use `auto` keyword.(especially when you override the == operator)

// you may copy a lot of code from copy construtor and know how to throw a std::out_of_range exception
// from function at

// please carefully read related descriptions from .hpp when you implement a function.

#include "hashmap.hpp"

// In fact these functions are for you, but a lot of people are stuck here, so I implement it for you.

size_t buckets = 10;

template <typename K, typename M, typename H>
HashMap<K, M, H>::HashMap() : HashMap(kDefaultBuckets) { }

template <typename K, typename M, typename H>
HashMap<K, M, H>::HashMap(size_t bucket_count, const H& hash) :
    _size(0),
    _hash_function(hash),
    _buckets_array(bucket_count, nullptr) {
		generate(_buckets_array.begin(), _buckets_array.end(), []() { return new node(); });
	}

template <typename K, typename M, typename H>
HashMap<K, M, H>::~HashMap() {
    clear();
}

template <typename K, typename M, typename H>
inline size_t HashMap<K, M, H>::size() const noexcept {
    return _size;
}

template <typename K, typename M, typename H>
inline bool HashMap<K, M, H>::empty() const noexcept {
    return _size == 0;
}

template <typename K, typename M, typename H>
inline float HashMap<K, M, H>::load_factor() const noexcept {
    return static_cast<float>(size())/bucket_count();
};

template <typename K, typename M, typename H>
size_t HashMap<K, M, H>::bucket_count() const noexcept {
    return _buckets_array.size();
};

template <typename K, typename M, typename H>
bool HashMap<K, M, H>::contains(const K& key) const noexcept {
    return find_node(key).second != nullptr;
}

template <typename K, typename M, typename H>
M& HashMap<K, M, H>::at(const K& key)const {
    auto [prev, node_found] = find_node(key);
    if (node_found == nullptr) {
        throw std::out_of_range("HashMap<K, M, H>::at: key not found");
    }
    return node_found->value.second;
}

template <typename K, typename M, typename H>
HashMap<K, M, H>::HashMap(HashMap const& other) {
    this->_hash_function = other._hash_function;
    this->_buckets_array = std::vector<node*>(other.bucket_count(), nullptr);

	generate(_buckets_array.begin(), _buckets_array.end(), []() { return new node(); });
    this->_size = 0;

    for (size_t i = 0; i < other.bucket_count(); ++i) {
        auto curr = other._buckets_array[i];

		curr = curr->next;

        while (curr != nullptr) {
            auto value = curr->value;
            auto node = std::make_pair(value.first,value.second);
            insert(node);
            curr = curr->next;
        }
    }
}


template <typename K, typename M, typename H>
void HashMap<K, M, H>::debug() const {
    std::cout << std::setw(30) << std::setfill('-') << '\n' << std::setfill(' ')
        << "Printing debug information for your HashMap implementation\n"
        << "Size: " << size() << std::setw(15) << std::right
        << "Buckets: " << bucket_count() << std::setw(20) << std::right
        << "(load factor: " << std::setprecision(2) << load_factor() << ") \n\n";

    for (size_t i = 0; i < bucket_count(); ++i) {
        std::cout << "[" << std::setw(3) << i << "]:";
        auto curr = _buckets_array[i];
        while (curr != nullptr) {
            const auto& [key, mapped] = curr->value;
            // next line will not compile if << not supported for K or M
            std::cout << " -> " << key << ":" << mapped;
            curr = curr->next;
        }
        std::cout << " /" << '\n';
    }
    std::cout << std::setw(30) << std::setfill('-') << '\n';
}

template <typename K, typename M, typename H>
M& HashMap<K, M, H>::operator[](const K& key) {
    if(!contains(key)) {
        auto res = new value_type(key, M());
        insert(*res);
    }
    return at(key);
}

template <typename K, typename M, typename H>
std::ostream& operator<<(std::ostream& os, const HashMap<K, M, H>& map){
    os<<"{";
    std::string str = "";
    for (size_t i = 0; i < map.bucket_count(); ++i) {
        auto curr = map._buckets_array[i];

		curr = curr->next;

        while (curr != nullptr) {
            auto node = curr;
            auto value = node->value;
            os<<str<<value.first<<":"<<value.second;
            str = ", ";
            curr = curr->next;
        }
    }
    os<<"}";
    return os;
}

// you work starts from here

template <typename K, typename M, typename H>
void HashMap<K, M, H>::clear() noexcept {
    for (unsigned int i = 0; i < bucket_count(); ++i) {
        auto target_node = _buckets_array.at(i);

		while (target_node) {
			node* prev = target_node;
			target_node = target_node->next;
			delete prev;
		}
    }

	buckets = _buckets_array.size();
	_buckets_array.clear();

	_size = 0;

}

template <typename K, typename M, typename H>
std::pair<typename HashMap<K, M, H>::value_type*, bool>
HashMap<K, M, H>::insert(const value_type& value) {
    if (bucket_count() == 0) { 
        _buckets_array = std::vector<node*>(buckets, nullptr);
        generate(_buckets_array.begin(), _buckets_array.end(), []() { return new node(); });
    }

	if (contains(value.first))
		return { nullptr, false };

    size_t index = _hash_function(value.first) % bucket_count();
    node* target_node = _buckets_array.at(index);

	while (target_node->next)
		target_node = target_node->next;
	target_node->next = new node(value);
	_size++;
    return { new value_type(value), true };
}


template <typename K, typename M, typename H>
bool HashMap<K, M, H>::erase(const K& key) {
    if (bucket_count() == 0) { 
        _buckets_array = std::vector<node*>(buckets, nullptr);
        generate(_buckets_array.begin(), _buckets_array.end(), []() { return new node(); });
    }

	if (!contains(key))
		return false;

	const auto& [prev, curr] = find_node(key);
	prev->next = curr->next;
	delete curr;
	_size--;

    return true;
}


template <typename K, typename M, typename H>
typename HashMap<K, M, H>::node_pair HashMap<K, M, H>::find_node(const K& key) const {
    size_t index = _hash_function(key) % bucket_count();
	node* target_node = _buckets_array.at(index);

	while (target_node->next) {
		if (target_node->next->value.first == key) {
			return { target_node, target_node->next };
		}
		target_node = target_node->next;
	}
    return { nullptr, nullptr };
}


// 
template <typename K, typename M, typename H>
void HashMap<K, M, H>::rehash(size_t new_bucket_count) {
	if (new_bucket_count == 0)
		throw std::out_of_range("new_bucket_count must be greater than 0");

	auto prev_buckets_array = this->_buckets_array;

	this->_buckets_array = std::vector<node*>(new_bucket_count, nullptr);
	this->_size = 0;
    generate(_buckets_array.begin(), _buckets_array.end(), []() { return new node(); });

	for (unsigned int i = 0; i < prev_buckets_array.size(); ++i) {
        auto target_node = prev_buckets_array.at(i);
        while (target_node->next) {
            target_node = target_node->next;
			this->insert(target_node->value);
        }
    }

    for (unsigned int i = 0; i < prev_buckets_array.size(); ++i) {
        auto target_node = prev_buckets_array.at(i);
        while (target_node) {
            node* prev = target_node;
            target_node = target_node->next;
            delete prev;
        }
    }

    prev_buckets_array.clear();
}


template <typename K, typename M, typename H>
bool operator==(const HashMap<K, M, H>& lhs,
    const HashMap<K,M,H>& rhs)
{
    if (lhs.empty() != rhs.empty() || lhs.size() != rhs.size()) return false;

    for (unsigned int i = 0; i < rhs.bucket_count(); ++i) {
		auto target_node = rhs._buckets_array.at(i);
		while (target_node->next) {
			target_node = target_node->next;
			const auto& [key, mapped] = target_node->value;
			if (lhs.contains(key) == false || lhs.at(key) != mapped) 
				return false;
		}
    }
    return true;

}

template <typename K, typename M, typename H>
bool operator!=(const HashMap<K, M, H>& lhs,
    const HashMap<K, M, H>& rhs) {
    return !operator==(lhs, rhs);
}


// copy some codes above
template<typename K, typename M, typename H>
HashMap<K, M, H>& HashMap<K, M, H>::operator=(const HashMap& other) {
    if (this == &other)
		return *this;

	this->clear();

	this->_hash_function = other._hash_function;
    this->_buckets_array = std::vector<node*>(other.bucket_count(), nullptr);

	generate(_buckets_array.begin(), _buckets_array.end(), []() { return new node(); });
    
	this->_size = 0;
    for (size_t i = 0; i < other.bucket_count(); ++i) {
        auto curr = other._buckets_array[i];

		curr = curr->next;

        while (curr != nullptr) {
            auto value = curr->value;
            auto node = std::make_pair(value.first,value.second);
            insert(node);
            curr = curr->next;
        }
    }

    return *this;
}


