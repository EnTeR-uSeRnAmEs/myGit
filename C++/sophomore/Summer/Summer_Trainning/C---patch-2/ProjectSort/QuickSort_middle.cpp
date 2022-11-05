template <typename T>
void QuickSort_middle(T begin, T end)
{
    // if (begin >= end)return;
    int n = end - begin;
    if (begin >= end)
    {
        return;
    }
    else
    {
        int i = 0, j = n;
        auto middle = begin + n / 2;
        if (&begin > &end)
        {
            exchange(begin, end);
        }
        if (&middle > &end)
        {
            exchange(middle, end);
        }
        if (&middle > &begin)
        {
            exchange(middle, begin);
        }
        auto tmp = *(begin + i);
        while (i < j)
        {
            while (*(begin + j) >= tmp && i < j)
                --j;
            *(begin + i) = *(begin + j);
            while (*(begin + i) <= tmp && i < j)
                ++i;
            *(begin + j) = *(begin + i);
        }
        *(begin + i) = tmp;
        QuickSort_middle(begin, begin + i - 1);
        QuickSort_middle(begin + i + 1, end);
    }
}

template <typename T>
void QuickSort_middle(T begin, T end, long long &cs, long long &fz)
{
    // if (begin >= end)return;
    int n = end - begin;
    if (begin >= end)
    {
        return;
    }
    else
    {
        int i = 0, j = n;
        auto middle = begin + n / 2;
        if (&begin > &end)
        {
            exchange(begin, end);
            fz += 3;
        }
        if (&middle > &end)
        {
            exchange(middle, end);
            fz += 3;
        }
        if (&middle > &begin)
        {
            exchange(middle, begin);
            fz += 3;
        }
        cs += 3;
        auto tmp = *(begin + i);
        ++fz;
        while (i < j)
        {
            while (*(begin + j) >= tmp && i < j)
            {
                ++cs;
                --j;
            }
            ++cs;
            *(begin + i) = *(begin + j);
            ++fz;
            while (*(begin + i) <= tmp && i < j)
            {
                ++cs;
                ++i;
            }
            ++cs;
            *(begin + j) = *(begin + i);
            ++fz;
        }
        *(begin + i) = tmp;
        ++fz;
        QuickSort_middle(begin, begin + i - 1, cs, fz);
        QuickSort_middle(begin + i + 1, end, cs, fz);
    }
}
