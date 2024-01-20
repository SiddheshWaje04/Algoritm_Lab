#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> intersection_sorted_arrays(const std::vector<int> &A, const std::vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    std::vector<int> C;
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            i++;
        }
        else if (A[i] > B[j])
        {
            j++;
        }
        else
        {
            C.push_back(A[i]); // or C.push_back(B[j]);
            i++;
            j++;
        }
    }

    return C;
}

int main()
{
    std::ifstream input_file("input.txt");
    if (!input_file.is_open())
    {
        std::cerr << "Error opening the input file.\n";
        return 1;
    }

    int m, n;
    input_file >> m >> n;

    std::vector<int> A(m);
    std::vector<int> B(n);

    for (int i = 0; i < m; ++i)
    {
        input_file >> A[i];
    }

    for (int j = 0; j < n; ++j)
    {
        input_file >> B[j];
    }

    input_file.close();

    std::vector<int> result_intersection = intersection_sorted_arrays(A, B);

    std::ofstream output_file("output_intersection.txt");
    if (!output_file.is_open())
    {
        std::cerr << "Error opening the output file.\n";
        return 1;
    }

    for (int num : result_intersection)
    {
        output_file << num << " ";
    }

    output_file.close();

    return 0;
}
