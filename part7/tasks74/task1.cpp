#include <cstddef>
#include <cstdint>
#include <iostream>
#include <vector>

template<class Iter> void print_vector(Iter first, Iter last)
{
    for (auto i = first; i != last-1; i++)
    {
        std::cout << *i << " ";
    }
    std::cout << *(last-1) << std::endl;
}

template<typename T> std::vector<T> subvector(const std::vector<T>& vtr, const size_t& begin, const size_t& end)
{
    std::vector<T> ans(end - begin);
    for (size_t i = begin; i < end; i++)
    {
        ans[i - begin] = vtr[i];
    }
    return ans;
}

template<typename T> uint32_t merge(const std::vector<T>& lhs, const std::vector<T>& rhs, std::vector<T>& vtr)
{
    print_vector(lhs.begin(), lhs.end());
    print_vector(rhs.begin(), rhs.end());
    uint32_t inversions(0);
    size_t lidx(0), ridx(0), l(lhs.size()), r(rhs.size());
    std::vector<T> merged;

    while ((lidx < l) && (ridx < r)) {
        if (lhs[lidx] <= rhs[ridx])
        {
            merged.push_back(lhs[lidx]);
            lidx++;
        }
        else
        {
            merged.push_back(rhs[ridx]);
            inversions += l - lidx;
            ridx++;
        }
    }

    if (lidx < l)
    {
        for (auto i = lhs.begin()+lidx; i != lhs.end(); i++)
        {
            merged.push_back(*i);
        }
    }
    else
    {
        for (auto i = rhs.begin()+ridx; i != rhs.end(); i++)
        {
            merged.push_back(*i);
        }
    }
    vtr = std::move(merged);
    print_vector(vtr.begin(), vtr.end());
    std::cout << "------" << std::endl;
    return inversions;
}

template<typename T> uint32_t msort(std::vector<T>& vtr, const size_t& n)
{
    if (vtr.size() <= 1)
    {
        return 0;
    }

    uint32_t inversions(0);
    size_t pivot = n / 2;
    std::vector<T> lhs(subvector(vtr, 0, pivot)), rhs(subvector(vtr, pivot, n));
    inversions += msort(lhs, pivot);
    inversions += msort(rhs, n - pivot);
    inversions += merge(lhs, rhs, vtr);
    return inversions;
}

// template<class Iter> uint32_t merge(const Iter& l_begin, const Iter& l_end, const Iter& r_begin, const Iter& r_end)
// {
//     uint32_t inversions(0);

//     std::cout << "current step:" << std::endl;
//     print_vector(l_begin, r_end);

//     for (Iter i = r_begin; i != r_end; i++)
//     {
//         for (size_t j = i - l_begin; j >= 1; j--)
//         {
//             if (*(l_begin + j) < *(l_begin + j - 1))
//             {
//                 inversions++;
//                 std::iter_swap(l_begin + j, l_begin + j - 1);
//             }
//             else
//             {
//                 break;
//             }
//         }
//     }
//     print_vector(l_begin, r_end);
//     return inversions;
// }

// template<class Iter> uint32_t msort(const Iter& begin, const Iter& end)
// {
//     if (end - begin > 1)
//     {
//         uint32_t inversions(0);
//         size_t pivot = (end - begin) / 2;
//         std::cout << end - begin << ": " << *begin << " " << *(end-1) << std::endl;
//         std::cout << pivot + (end - begin) % 2 - 1 << " " << pivot << std::endl;
//         inversions += msort(begin, begin + pivot + (end - begin) % 2);
//         inversions += msort(begin + pivot, end);
//         inversions += merge(begin, begin + pivot + (end - begin) % 2, begin + pivot, end);
//         return inversions;
//     }
//     else
//     {
//         return 0;
//     }
// }

int main()
{
    size_t n;
    int32_t input;
    std::vector<int32_t> vtr;

    std::cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        vtr.push_back(input);
    }
    std::cout << msort(vtr, vtr.size()) << std::endl;
    print_vector(vtr.begin(), vtr.end());

    return 0;
}
