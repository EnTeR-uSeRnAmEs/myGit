template <typename T>
void QuickSort_three(T begin, T end)
{
    // if (begin >= end)return;
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
            if (*(begin + i) < tmp)
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
        // QuickSort(begin, begin + i - 1);

        QuickSort_three(begin, begin + h);
        QuickSort_three(begin + i, end);
    }
}

template <typename T>
void QuickSort_three(T begin, T end, long long &cs, long long &fz)
{
    // if (begin >= end)return;
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
        ++fz;
        while (i <= j)
        {
            /*
              while (*(begin + j) >= tmp && i < j)j--;
              *(begin + i) = *(begin + j);
              while (*(begin + i) <= tmp && i < j)i++;
              *(begin + j) = *(begin + i);
            */
            if (*(begin + i) < tmp) //ʹ�����зֿ��Ŵ��������ظ�Ԫ��
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
        QuickSort_three(begin, begin + h, cs, fz);
        QuickSort_three(begin + i, end, cs, fz);
    }
}
