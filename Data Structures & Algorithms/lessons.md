# Data Structures & Algorithms

In this exercices, mainly two [containers](https://en.cppreference.com/cpp/container) are used 

- vectors (`std::vectors`, `std::string`)
- Associative containers (`set` and `map` and their variation)

## Containers, high level properties

### `std::vector`

The `std::vector` is a straightforward contiguous storage of arbitrary objects. Accessing an element is fast (O(1)) but finding one is expensive `O(v.size())`. It should not be used to be parsed by it's element (Associative containers should !). It has a size and a capacity. The capacity is the size of the underlying allocated block for this vector, it's used to avoid reallocations which are really expensive. Here are the `vector's` methods I have used in these exercices:

- `reserve()`: increase the capacity without changing the size, avoid future reallocation while keeping code logic aboit size consistent.
- Iterators: `begin()`, `end` and their `c/r` variations: used a lot for algorithms. `c` variations: constant inputs. `r` variation: reversed, see `product-of-array-discluding-self`.
- `operator[]`: straightforward.
- `push_back(v)`: add an element the the end of the vector, initialized as a copy of v. Used in `anagram_group`.
- `emplace_back()`: constructs & add an element at the end of a vector. Used in `anagram_group` to create empty buckets. Otherwise pushing back into them is wrong.
- `size()`: straightforward
- `ctor/dtor`: straightforwatd

### `std::set`

The `std::set` is a collection of unique sorted Keys. Underlying implementation is usually red-black tree. Search, removal and insersion have logarithmic complexity, which make them more efficient than vector for these task. (vector: log(n) complexity). Construction cost from an iterator is `nlogn`, you pay the sort.

#### variations:

- `multiset`: Same but entries can be non unique.
- `unordered_(multi)set`: Same but unordred, implemented via hash-map. Lookup cost can vary, is usually cheaper (O(1)) but if hash map is "unbalanced" cost becomes linear. Build is cheaper, O(n), no sort.

- `ctor` building an `unordered_set` from a vector `unordered_set<int> set(nums.cbegin(), nums.cend());` efficiently allows to remove all double entries. used in duplicate-integer.
- `.contains()` in a `unordered_set`, quick lookup (O(1)), used in `longest-consecutive-sequence`

### `std::map`

Collection of unique sorted key-value pairs, sorted by keys. Usually implemented as red-black trees. Same variations than `set`.

- `auto [it,success] = hash_map.try_emplace(key,value);` in a `map`, if the pair exists already, no opt (success=false, it=end), else, build and emplace the key in the container. (anagram-group)
- `reserve` to avoid realloc (anagram-group)
- `==` quick comparison, used to compare histograms in  (is-anagram). I could have used unordred !
- `[key]` in unordered_map
- `find(Key)`: returns an iterator (pair key, value). O(1) best, n worst. Used in `two-integer-sum`
- `insert(pair)`: just like it sounds. no opt if double.