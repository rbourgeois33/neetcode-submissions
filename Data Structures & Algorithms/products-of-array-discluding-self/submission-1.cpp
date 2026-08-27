template <typename T>
void print_vec(std::string_view name, const std::vector<T>& v) {
    std::cout << name << " = [";
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]\n";
}


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        const auto n = nums.size();
        std::vector<int> ex_scan(n);
        std::vector<int> ex_scan_r(n);


        std::exclusive_scan(nums.begin() , nums.end() ,ex_scan.begin()  , 1, std::multiplies<>{});
        std::exclusive_scan(nums.rbegin(), nums.rend(),ex_scan_r.rbegin(), 1, std::multiplies<>{}); //rbegin for 3rd argument !

        //print_vec("nums", nums);
        //print_vec("ex_scan", ex_scan);
        //print_vec("ex_scan_r", ex_scan_r);

        std::transform(ex_scan.begin(),
                       ex_scan.end(),
                       ex_scan_r.begin(),
                       ex_scan_r.begin(),
                       std::multiplies<>{});

        //print_vec("ex_scan_r", ex_scan_r);

        return ex_scan_r;

    }
};
