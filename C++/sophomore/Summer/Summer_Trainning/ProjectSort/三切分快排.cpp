template <typename T>
void InsertionSort(T begin, T end, int n)
{
    int i;
    int j;

    for (i = 0; i < n; i++)
    {
        auto tmp = *(begin + i + 1);

        for (j = i + 1; j >= 0 && tmp < *(begin + j - 1); j--)
        {
            *(begin + j) = *(begin + j - 1);
        }
        *(begin + j) = tmp;
    }
}

template <typename T>
void QuickSort(T begin, T end)
{
    // if (begin >= end)return;
    int n = end - begin;
    if (begin + 10 >= end) //���ݽ���ʱ�л�����������
    {
        InsertionSort(begin, end, n);
    }
    else
    {
        // int n = end - begin;
        int i = 1, j = n;

        int h = 0;

        auto middle = begin + n / 2; //ȡ��λ����Ϊ��׼Ԫ��ʹ��׼Ԫ��ѡȡ�����

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
            if (*(begin + i) < tmp) //ʹ�����зֿ��Ŵ�������ظ�Ԫ��
            {
                h++;
                swap(*(begin + i), *(begin + h));
                i++;
            }
            else if (*(begin + i) == tmp)
            {
                i++;
            }
            else if (*(begin + i) > tmp)
            {
                swap(*(begin + i), *(begin + j));
                j--;
            }
        }
        swap(*(begin), *(begin + h));
        //*(begin + i) = tmp;
        // QuickSort(begin, begin + i - 1);

        QuickSort(begin, begin + h);
        QuickSort(begin + i, end);
    }
}
