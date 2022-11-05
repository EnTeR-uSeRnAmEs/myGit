template <typename T>
void QuickSort(T begin, T end)
{
    if (begin >= end)
        return;
    int n = end - begin;
    int i = 0, j = n;
    auto tmp = *(begin + i);
    while (i < j)
    {
        while (*(begin + j) >= tmp && i < j)
            j--;
        *(begin + i) = *(begin + j);
        while (*(begin + i) <= tmp && i < j)
            i++;
        *(begin + j) = *(begin + i);
    }
    *(begin + i) = tmp;
    QuickSort(begin, begin + i - 1);
    QuickSort(begin + i + 1, end);
}

template <typename T>
void QuickSort(T begin, T end, long long &cs, long long &fz)
{
    if (begin >= end)
        return;
    int n = end - begin;
    int i = 0, j = n;
    auto tmp = *(begin + i);
    ++fz;
    while (i < j)
    {
        while (*(begin + j) >= tmp && i < j)
        {
            ++cs;
            j--;
        }
        ++cs;
        *(begin + i) = *(begin + j);
        ++fz;
        while (*(begin + i) <= tmp && i < j)
        {
            ++cs;
            i++;
        }
        ++cs;
        *(begin + j) = *(begin + i);
        ++fz;
    }
    *(begin + i) = tmp;
    ++fz;
    QuickSort(begin, begin + i - 1, cs, fz);
    QuickSort(begin + i + 1, end, cs, fz);
}
