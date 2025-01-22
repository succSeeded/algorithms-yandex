#include <iostream>
#include <vector>

std::vector<int> merge(const std::vector<int>& lhs, const std::vector<int>& rhs) {

    int min, lidx = 0, ridx = 0, l = lhs.size(), r = rhs.size();
    std::vector<int> sorted;

    while ((lidx < l) && (ridx < r)) {
        if (lhs[lidx] < rhs[ridx]) 
        {
            min = lhs[lidx];
            lidx++;
        }
        else
        {
            min = rhs[ridx];
            ridx++;
        }
        sorted.push_back(min);
    }

    if (lidx < l)
    {
        for (auto i = lhs.begin()+lidx; i != lhs.end(); i++)
        {
            sorted.push_back(*i);
        }
    }
    else
    {
        for (auto i = rhs.begin()+ridx; i != rhs.end(); i++)
        {
            sorted.push_back(*i);
        }
    }
    return sorted;
}

std::vector<int> merge_sort(const std::vector<int>& v)
{
    if (v.size() == 1)
    {
        return v;
    }

    auto d = (int) v.size() / 2;
    std::vector<int> lhalf, rhalf;
    for (size_t i = 0; i < v.size(); i++)
    {
        if ((i+1) <= d)
        {
            lhalf.push_back(v[i]);
        }
        else
        {
            rhalf.push_back(v[i]);
        }
    }
    return merge(merge_sort(lhalf), merge_sort(rhalf));
}

int main() 
{
    int n, input;
    std::vector<int> sorted, input_v;

    std::cin >> n;

    for (size_t j = 0; j < n; j++) 
    {
        std::cin >> input;
        input_v.push_back(input);
    }

    sorted = merge_sort(input_v);

    for (auto i = sorted.begin(); i != sorted.end()-1; i++) 
    {
        std::cout << *i << " ";
    }
    std::cout << sorted.back() << std::endl;
}