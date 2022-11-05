template <typename T>
void InsertionSort(T begin, T end)
{
    int i, j, n = end - begin;
    for (i = 0; i < n; i++)
    {
        auto tmp = *(begin + i + 1);
        for (j = i + 1; j >= 1 && tmp < *(begin + j - 1); j--)
        {
            *(begin + j) = *(begin + j - 1);
        }
        *(begin + j) = tmp;
    }
}


template <typename T>
void InsertionSortc(T begin, T end, long long &cs, long long &fz)
{
    int i, j, n = end - begin;
    for (i = 0; i < n; i++)
    {
        auto tmp = *(begin + i + 1);
        ++fz;
        for (j = i + 1; j >= 1&& tmp < *(begin + j - 1); j--)
        {
            ++cs;
            ++fz;
            *(begin + j) = *(begin + j - 1);
        }
        *(begin + j) = tmp;
        ++fz;
    }
}
