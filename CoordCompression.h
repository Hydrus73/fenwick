/**
 * The Compressor class provides a way to compress a range of numbers that is too large into a much smaller range.
 * Each unique number in the original list will be represented by a new unique integer identifier.
 * The relative order of numbers is preserved with the new identifiers.
 * 
 * This can be useful when the input size is much smaller than the potential input range.
 * 
 * The Extra version has constant time individual index compression as opposed to log time compression in the OnTheFly version. However, this has more overhead, which might be unwanted.
 */
#include <bits/stdc++.h>
template <typename Number>
class Compressor {
   public:
    class OnTheFly {
       public:
        std::vector<Number> numbers;
        OnTheFly(std::vector<Number>& numbers) {
            this->numbers = numbers;
            std::sort(this->numbers.begin(), this->numbers.end());
            this->numbers.erase(unique(this->numbers.begin(), this->numbers.end()), this->numbers.end());
        }
        // O(logn) compression
        int compress(Number number) {
            return std::lower_bound(numbers.begin(), numbers.end(), number) - numbers.begin();
        }
        // O(1) decompression
        Number uncompress(int index) {
            return numbers[index];
        }
    };
    class Extra {
       public:
        std::vector<Number> numbers;
        std::unordered_map<Number, int> num_to_index;
        Extra(std::vector<Number>& numbers) {
            this->numbers = numbers;
            std::sort(this->numbers.begin(), this->numbers.end());
            this->numbers.erase(unique(this->numbers.begin(), this->numbers.end()), this->numbers.end());
            for (unsigned i = 0; i < this->numbers.size(); i++) {
                num_to_index[this->numbers[i]] = i;
            }
        }
        // O(1) compression
        int compress(Number number) {
            return num_to_index[number];
        }
        // O(1) decompression
        Number uncompress(int index) {
            return numbers[index];
        }
    };
};