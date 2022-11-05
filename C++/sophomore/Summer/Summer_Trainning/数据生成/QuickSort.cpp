//#include "InsertionSort.cpp"

template <typename T>void exchange(T a, T b);
template <typename T>

void InsertionSort(T begin, T end, long long &cs, long long &fz)
{
    int i;
    int j;
	int n = end - begin;
    for (i = 0; i < n; i++)
    {
        auto tmp = *(begin + i + 1);
		fz++;
        for (j = i + 1; j >= 1 && tmp < *(begin + j - 1); j--)
        {
            *(begin + j) = *(begin + j - 1);
            fz++;
            cs++;
        }
        *(begin + j) = tmp;
        fz++;
    }
}


template <typename T>

//void QuickSort_comprehensive(T begin, T end)
void QuickSort_comprehensivec(T begin, T end, long long &cs, long long &fz)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin + 10 >= end)//数据较少时切换到插入排序
    {
        InsertionSort(begin, end, cs, fz);
    }
    else
    {
        //int n = end - begin;
        int i = 1, j = n;

        int h = 0;

        auto middle = begin + n / 2;//取中位数作为基准元素使基准元素选取随机化

        if (*begin > *end)
        {
            exchange(begin, end);
            fz = fz + 3;
        }
        cs++;
        if (*middle > *end)
        {
            exchange(middle, end);
            fz = fz + 3;
        }
        cs++;
        if (*middle > *begin)
        {
            exchange(middle, begin);
            fz = fz + 3;
        }
        cs++;

        auto tmp = *(begin + h);
        fz++;

        while (i <= j)
        {
            /*
              while (*(begin + j) >= tmp && i < j)j--;
              *(begin + i) = *(begin + j);
              while (*(begin + i) <= tmp && i < j)i++;
              *(begin + j) = *(begin + i);
            */
            if (*(begin + i) < tmp)//使用三路快排处理大量重复元素
            {
                h++;
                exchange(begin + i, begin + h);
                fz = fz + 3;
                i++;
            }
            //CountCompare++;
            else if (*(begin + i) == tmp)
            {
                i++;
            }
            //CountCompare++;
            else if (*(begin + i) > tmp)
            {
                exchange(begin + i, begin + j);
                fz = fz + 3;
                j--;
            }
            cs = cs + 3;

        }
        exchange((begin), (begin + h));
        fz = fz + 3;
        //*(begin + i) = tmp;
        //QuickSort(begin, begin + i - 1);

        QuickSort_comprehensivec(begin, begin + h, cs, fz);
        QuickSort_comprehensivec(begin + i, end, cs, fz);
    }
}





template <typename T>
void QuickSort_Insertionc(T begin, T end, long long &cs, long long &fz)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin + 10 >= end)//数据较少时切换到插入排序
    {
        InsertionSort(begin, end, cs, fz);
    }
    else
    {
        int i = 0, j = n;
        auto tmp = *(begin + i);
        fz++;
        while (i < j)
        {
            while (*(begin + j) >= tmp && i < j)
            {
                j--;
                cs++;
            }
            *(begin + i) = *(begin + j);
            fz++;
            while (*(begin + i) <= tmp && i < j)
            {
                i++;
                cs++;
            }
            *(begin + j) = *(begin + i);
            fz++;
        }
        *(begin + i) = tmp;
        fz++;

        QuickSort_Insertionc(begin, begin + i - 1,cs,fz);
        QuickSort_Insertionc(begin + i + 1, end,cs,fz);
    }
}


template <typename T>

void QuickSort_middlec(T begin, T end, long long &cs, long long &fz)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin >= end)
    {
        return;
    }
    else
    {
        int i = 0, j = n;

        auto middle = begin + n / 2;//取中位数作为基准元素使基准元素选取随机化
        fz++;

        if (*begin > *end)
        {
            exchange(begin, end);
            fz = fz + 3;
        }
        cs++;
        if (*middle > *end)
        {
            exchange(middle, end);
            fz = fz + 3;
        }
        cs++;
        if (*middle > *begin)
        {
            exchange(middle, begin);
            fz = fz + 3;
        }
        cs++;


        auto tmp = *(begin + i);
        fz++;
        while (i < j)
        {
            while (*(begin + j) >= tmp && i < j)
            {
                j--;
                cs++;
            }
            *(begin + i) = *(begin + j);
            fz++;
            while (*(begin + i) <= tmp && i < j)
            {
                i++;
                cs++;
            }
            *(begin + j) = *(begin + i);
            fz++;
        }
        *(begin + i) = tmp;
        fz++;
        QuickSort_middlec(begin, begin + i - 1, cs, fz);
        QuickSort_middlec(begin + i + 1, end, cs, fz);
    }
}


template <typename T>

void QuickSort_threec(T begin, T end, long long &cs, long long &fz)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin >= end)
    {
        return;
    }
    else
    {
        int i = 1, j = n;

        int h = 0;



        auto tmp = *(begin + h);
        fz++;
        while (i <= j)
        {
            /*
              while (*(begin + j) >= tmp && i < j)j--;
              *(begin + i) = *(begin + j);
              while (*(begin + i) <= tmp && i < j)i++;
              *(begin + j) = *(begin + i);
            */
            if (*(begin + i) < tmp)//使用三路快排处理大量重复元素
            {
                h++;
                exchange(begin + i, begin + h);
                fz = fz + 3;
                i++;
            }
            //CountCompare++;
            else if (*(begin + i) == tmp)
            {
                i++;
            }
            //CountCompare++;
            else if (*(begin + i) > tmp)
            {
                exchange(begin + i, begin + j);
                fz = fz + 3;
                j--;
            }
            cs = cs + 3;

        }
        exchange((begin), (begin + h));
        fz = fz + 3;
        //*(begin + i) = tmp;
        //QuickSort(begin, begin + i - 1);

        QuickSort_threec(begin, begin + h, cs, fz);
        QuickSort_threec(begin + i, end, cs, fz);
    }
}


template <typename T>

void InsertionSort(T begin, T end, int n)
{
    int i;
    int j;
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

void QuickSort_comprehensive(T begin, T end)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin + 10 >= end)//数据较少时切换到插入排序
    {
        InsertionSort(begin, end, n);
    }
    else
    {
        //int n = end - begin;
        int i = 1, j = n;

        int h = 0;

        auto middle = begin + n / 2;//取中位数作为基准元素使基准元素选取随机化

        if (*begin > *end)
        {
            exchange(begin, end);
        }
        if (*middle > *end)
        {
            exchange(middle, end);
        }
        if (*middle > *begin)
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
            if (*(begin + i) < tmp)//使用三路快排处理大量重复元素
            {
                h++;
                exchange((begin + i), (begin + h));
                i++;
            }
            else if (*(begin + i) == tmp)
            {
                i++;
            }
            else if (*(begin + i) > tmp)
            {
                exchange((begin + i), (begin + j));
                j--;
            }

        }
        exchange((begin), (begin + h));
        //*(begin + i) = tmp;
        //QuickSort(begin, begin + i - 1);

        QuickSort_comprehensive(begin, begin + h);
        QuickSort_comprehensive(begin + i, end);
    }
}


template <typename T>

void QuickSort_three(T begin, T end)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin >= end)
    {
        return;
    }
    else
    {
        int i = 1, j = n;

        int h = 0;



        auto tmp = *(begin + h);
        while (i <= j)
        {
            /*
              while (*(begin + j) >= tmp && i < j)j--;
              *(begin + i) = *(begin + j);
              while (*(begin + i) <= tmp && i < j)i++;
              *(begin + j) = *(begin + i);
            */
            if (*(begin + i) < tmp)//使用三路快排处理大量重复元素
            {
                h++;
                exchange((begin + i), (begin + h));
                i++;
            }
            else if (*(begin + i) == tmp)
            {
                i++;
            }
            else if (*(begin + i) > tmp)
            {
                exchange((begin + i), (begin + j));
                j--;
            }

        }
        exchange((begin), (begin + h));
        //*(begin + i) = tmp;
        //QuickSort(begin, begin + i - 1);

        QuickSort_three(begin, begin + h);
        QuickSort_three(begin + i, end);
    }
}


template <typename T>

void QuickSort_middle(T begin, T end)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin >= end)
    {
        return;
    }
    else
    {
        int i = 0, j = n;

        auto middle = begin + n / 2;//取中位数作为基准元素使基准元素选取随机化

        if (*begin > *end)
        {
            exchange(begin, end);
        }
        if (*middle > *end)
        {
            exchange(middle, end);
        }
        if (*middle > *begin)
        {
            exchange(middle, begin);
        }


        auto tmp = *(begin + i);
        while (i < j)
        {
            while (*(begin + j) >= tmp && i < j)j--;
            *(begin + i) = *(begin + j);
            while (*(begin + i) <= tmp && i < j)i++;
            *(begin + j) = *(begin + i);
        }
        *(begin + i) = tmp;
        QuickSort_middle(begin, begin + i - 1);
        QuickSort_middle(begin + i + 1, end);
    }
}


template <typename T>

void QuickSort_Insertion(T begin, T end)
{
    //if (begin >= end)return;
    int n = end - begin;
    if (begin + 10 >= end)//数据较少时切换到插入排序
    {
        InsertionSort(begin, end, n);
    }
    else
    {
        int i = 0, j = n;
        auto tmp = *(begin + i);
        while (i < j)
        {
            while (*(begin + j) >= tmp && i < j)j--;
            *(begin + i) = *(begin + j);
            while (*(begin + i) <= tmp && i < j)i++;
            *(begin + j) = *(begin + i);
        }
        *(begin + i) = tmp;
        QuickSort_Insertion(begin, begin + i - 1);
        QuickSort_Insertion(begin + i + 1, end);
    }
}


template <typename T>
void QuickSort(T begin, T end)
{
    if(begin >= end)return;
    int n = end - begin;
    int i = 0, j = n;
    auto tmp = *(begin + i);
    while(i < j)
    {
        while(*(begin + j) >= tmp && i < j)j--;
        *(begin + i) = *(begin + j);       
        while(*(begin + i) <= tmp && i < j)i++;
        *(begin + j) = *(begin + i);
    }
    *(begin + i) = tmp;
    QuickSort(begin, begin + i - 1);
    QuickSort(begin + i + 1, end);
}


template <typename T>
void QuickSortc(T begin, T end, long long & cs, long long& fz)
{
    if(begin >= end)return;
    int n = end - begin;
    int i = 0, j = n;
    auto tmp = *(begin + i);
    fz++;
    while(i < j)
    {
        while (*(begin + j) >= tmp && i < j)
            {
                j--;
                cs++;
            }
            *(begin + i) = *(begin + j);
            fz++;
            while (*(begin + i) <= tmp && i < j)
            {
                i++;
                cs++;
            }
            *(begin + j) = *(begin + i);
            fz++;
    }
    *(begin + i) = tmp;
    fz++;
    QuickSortc(begin, begin + i - 1, cs, fz);
    QuickSortc(begin + i + 1, end, cs, fz);
}
