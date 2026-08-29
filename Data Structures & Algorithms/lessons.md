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

# C++ Container Complexity Reference (claude)

## Ordered associative containers (red-black tree)

| Operation | `set` | `multiset` | `map` | `multimap` |
|---|---|---|---|---|
| Range ctor `C(first, last)` | O(n log n) | O(n log n) | O(n log n) | O(n log n) |
| ↳ if range already sorted | **O(n)** | **O(n)** | **O(n)** | **O(n)** |
| Range `insert(first, last)` | O(n log(s+n)) | O(n log(s+n)) | O(n log(s+n)) | O(n log(s+n)) |
| Copy ctor | O(n) | O(n) | O(n) | O(n) |
| Move ctor | O(1) | O(1) | O(1) | O(1) |
| `find` | O(log n) | O(log n) | O(log n) | O(log n) |
| `insert` | O(log n) | O(log n) | O(log n) | O(log n) |
| `insert` w/ correct hint | O(1) amort. | O(1) amort. | O(1) amort. | O(1) amort. |
| `erase(key)` | O(log n) | O(log n + k) | O(log n) | O(log n + k) |
| `erase(iterator)` | O(1) amort. | O(1) amort. | O(1) amort. | O(1) amort. |
| `count(key)` | O(log n) | O(log n + k) | O(log n) | O(log n + k) |
| `equal_range` / `lower_bound` / `upper_bound` | O(log n) | O(log n) | O(log n) | O(log n) |
| `operator[]` / `at` | — | — | O(log n) | — (no `[]`) |
| Iteration | O(n), sorted | O(n), sorted | O(n), sorted | O(n), sorted |
| `size` / `empty` | O(1) | O(1) | O(1) | O(1) |
| `clear` | O(n) | O(n) | O(n) | O(n) |

`k` = number of elements matching the key. `s` = container size before a range insert.

## Unordered associative containers (hash table)

| Operation | `unordered_set` | `unordered_multiset` | `unordered_map` | `unordered_multimap` |
|---|---|---|---|---|
| Range ctor `C(first, last)` | O(n) / O(n²) | O(n) / O(n²) | O(n) / O(n²) | O(n) / O(n²) |
| Range `insert(first, last)` | O(n) / O(n²) | O(n) / O(n²) | O(n) / O(n²) | O(n) / O(n²) |
| Copy ctor | O(n) / O(n²) | O(n) / O(n²) | O(n) / O(n²) | O(n) / O(n²) |
| Move ctor | O(1) | O(1) | O(1) | O(1) |
| `find` | O(1) / O(n) | O(1) / O(n) | O(1) / O(n) | O(1) / O(n) |
| `insert` | O(1) / O(n) | O(1) / O(n) | O(1) / O(n) | O(1) / O(n) |
| `erase(key)` | O(1) / O(n) | O(k) / O(n) | O(1) / O(n) | O(k) / O(n) |
| `erase(iterator)` | O(1) | O(1) | O(1) | O(1) |
| `count(key)` | O(1) / O(n) | O(k) / O(n) | O(1) / O(n) | O(k) / O(n) |
| `equal_range` | O(1) / O(n) | O(k) / O(n) | O(1) / O(n) | O(k) / O(n) |
| `operator[]` / `at` | — | — | O(1) / O(n) | — (no `[]`) |
| `lower_bound` / range queries | — | — | — | — |
| Iteration | O(n + buckets) | O(n + buckets) | O(n + buckets) | O(n + buckets) |
| `rehash` / `reserve` | O(n) | O(n) | O(n) | O(n) |
| `size` / `empty` | O(1) | O(1) | O(1) | O(1) |
| `clear` | O(n) | O(n) | O(n) | O(n) |

Format is **average / worst case**. No ordering, so no `lower_bound` or range queries.

## `vector`

| Operation | Complexity |
|---|---|
| Range ctor `vector(first, last)` | O(n) |
| ↳ input iterators only | O(n) amortized (reallocates) |
| Range `insert(pos, first, last)` | O(n + m), `m` = elements after `pos` |
| Copy ctor | O(n) |
| Move ctor | O(1) |
| `operator[]` / `at` / `front` / `back` | O(1) |
| `push_back` / `pop_back` | O(1) amortized |
| `insert` / `erase` (middle) | O(n) |
| `find` (unsorted, linear scan) | O(n) |
| `lower_bound` (sorted) | O(log n) |
| `size` / `empty` / `capacity` | O(1) |
| `clear` | O(n) |
| `reserve` / `resize` | O(n) |


