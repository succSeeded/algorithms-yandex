#include <iostream>
#include <vector>

int main() 
{
    int n, m, input, min;
    std::vector<std::vector<int>> sqs;
    std::vector<int> sorted, sqsInput;

    std::cin >> n;

    for (size_t i = 0; i < n; i++) 
    {
        std::cin >> m;
        for (size_t j = 0; j < m; j++) 
        {
            std::cin >> input;
            sqsInput.push_back(input);
        }
        sqs.push_back(sqsInput);
        sqsInput.clear();
    }

    while (!sqs.empty()) {
        min = 0;
        for (auto i = 0; i < sqs.size(); i++)
        {
            if (sqs[i][0] < sqs[min][0]) 
            {
                min = i;
            } 
        }
        sorted.push_back(sqs[min][0]);
        sqs[min].erase(sqs[min].begin());

        auto i = sqs.begin();
        while (i != sqs.end())
        {
            if ((*i).empty()) 
            {
                sqs.erase(i);
            }
            else
            {
                i++;
            }
        }
    }

    for (auto i = sorted.begin(); i != sorted.end()-1; i++) 
    {
        std::cout << *i << " ";
    }
    std::cout << sorted.back() << std::endl;
}