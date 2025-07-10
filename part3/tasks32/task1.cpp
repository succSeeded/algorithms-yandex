#include <iostream>
#include <vector>

int main() 
{
    int l, r, n;
    std::vector<int> min_r;
    std::cin >> n;

    std::vector<std::vector<int>> lr, res;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> l >> r;
        lr.push_back({r, l});
    }

    std::vector<int> v;
    while (!lr.empty()) {

        min_r = {50, 50};
        for (auto interval : lr)
        {
            if (interval < min_r) 
            {
                min_r = interval;
            }
        }

        for (std::vector<std::vector<int>>::iterator it = lr.begin(); it != lr.end();)
        {
            v = *it;
            if (v[1] <= min_r[0])
            {
                it = lr.erase(it);
            }
            else
            {
                it++;
            }
        }
        res.emplace_back(min_r);
    }

    std::cout << res.size() << std::endl;

    return 0;
}