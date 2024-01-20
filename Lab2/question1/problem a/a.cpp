#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> merge_sorted_arrays(const std::vector<int> &A, const std::vector<int> &B)
{
    int m = A.size();
    int n = B.size();
    std::vector<int> C(m + n, 0);
    int i = 0, j = 0, k = 0;

    while (i < m && j < n)
    {
        if (A[i] < B[j])
        {
            C[k++] = A[i++];
        }
        else
        {
            C[k++] = B[j++];
        }
    }

    while (i < m)
    {
        C[k++] = A[i++];
    }

    while (j < n)
    {
        C[k++] = B[j++];
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

    std::vector<int> result_merge = merge_sorted_arrays(A, B);

    std::ofstream output_file("output_merge.txt");
    if (!output_file.is_open())
    {
        std::cerr << "Error opening the output file.\n";
        return 1;
    }

    for (int num : result_merge)
    {
        output_file << num << " ";
    }

    output_file.close();

    return 0;
}
