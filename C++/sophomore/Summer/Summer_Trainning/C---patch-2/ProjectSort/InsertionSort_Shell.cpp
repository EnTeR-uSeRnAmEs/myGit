template <typename T>
void InsertionSort_Shell(T begin, T end)
{
    int h = 1, len = end - begin + 1;
    while (h < len / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < len; i++)
        {
            for (int j = i; j >= h && *(begin + j) < *(begin + j - h); j -= h)
                swap(*(begin + j), *(begin + j - h));
        }
        h = h / 3;
    }
}

template <typename T>
void InsertionSort_Shell(T begin, T end, long long &cs, long long &fz)
{
    int h = 1, len = end - begin + 1;
    while (h < len / 3)
        h = 3 * h + 1;
    while (h >= 1)
    {
        for (int i = h; i < len; i++)
        {
            for (int j = i; j >= h && *(begin + j) < *(begin + j - h); j -= h)
            {
                ++cs;
                exchange(*(begin + j), *(begin + j - h));
                fz += 3;
            }
            ++cs;
        }
        h = h / 3;
    }
}