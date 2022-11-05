template <typename T>
void QuickSort_comprehensive(T begin, T end)
{
    // if (begin >= end)return;
    int n = end - begin;
    if (begin + 10 >= end) //锟斤拷锟捷斤拷锟斤拷时锟�?伙拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤�?
    {
        InsertionSort(begin, end);
    }
    else
    {
        // int n = end - begin;
        int i = 1, j = n;
        int h = 0;
        auto middle = begin + n / 2; //取锟斤拷位锟斤拷锟斤拷为锟斤拷准元锟斤拷使锟斤拷准元锟斤拷选取锟斤拷锟斤拷�??
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
        auto tmp = *(begin + h);
        while (i <= j)
        {
            /*
              while (*(begin + j) >= tmp && i < j)j--;
              *(begin + i) = *(begin + j);
              while (*(begin + i) <= tmp && i < j)i++;
              *(begin + j) = *(begin + i);
            */
            if (*(begin + i) < tmp) //使锟斤拷锟斤拷锟�?分匡拷锟脚达拷锟斤拷锟斤拷锟斤拷锟截革拷元锟斤拷
            {
                ++h;
                exchange((begin + i), (begin + h));
                ++i;
            }
            else if (*(begin + i) == tmp)
            {
                ++i;
            }
            else if (*(begin + i) > tmp)
            {
                exchange((begin + i), (begin + j));
                --j;
            }
        }
        exchange((begin), (begin + h));
        //*(begin + i) = tmp;
        // QuickSort(begin, begin + i - 1);
        QuickSort_comprehensive(begin, begin + h);
        QuickSort_comprehensive(begin + i, end);
    }
}

template <typename T>
void QuickSort_comprehensive(T begin, T end, long long &cs, long long &fz)
{
    // if (begin >= end)return;
    int n = end - begin;
    if (begin + 10 >= end)
    {
        InsertionSort(begin, end, cs, fz);
    }
    else
    {
        // int n = end - begin;
        int i = 1, j = n;
        int h = 0;
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
        auto tmp = *(begin + h);
        ++fz;
        while (i <= j)
        {
            /*
              while (*(begin + j) >= tmp && i < j)j--;
              *(begin + i) = *(begin + j);
              while (*(begin + i) <= tmp && i < j)i++;
              *(begin + j) = *(begin + i);
            */
            if (*(begin + i) < tmp) //使锟斤拷锟斤拷锟�?分匡拷锟脚达拷锟斤拷锟斤拷锟斤拷锟截革拷元锟斤拷
            {
                ++cs;
                ++h;
                exchange((begin + i), (begin + h));
                fz += 3;
                ++i;
            }
            else if (*(begin + i) == tmp)
            {
                cs += 2;
                ++i;
            }
            else if (*(begin + i) > tmp)
            {
                cs += 3;
                exchange((begin + i), (begin + j));
                fz += 3;
                --j;
            }
        }
        exchange((begin), (begin + h));
        fz += 3;
        //*(begin + i) = tmp;
        // QuickSort(begin, begin + i - 1);
        QuickSort_comprehensive(begin, begin + h, cs, fz);
        QuickSort_comprehensive(begin + i, end, cs, fz);
    }
}
