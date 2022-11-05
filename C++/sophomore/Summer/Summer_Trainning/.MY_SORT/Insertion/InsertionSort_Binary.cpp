template <class T>
void InsertionSort_Binary(T begin, T end)
{
    int len = end - begin + 1; //ͨ����β��ַ��������ݳ���
    int i, j, temp, m, low, high;
    for (i = 1; i < len; i++) //��ѭ��������Ҫ���������
    {
        temp = *(begin + i);
        low = 0;
        high = i - 1;
        while (low <= high) //��ѭ��1�����ַ�����Ԫ��Ӧ�����λ��
        {
            m = (low + high) / 2;
            if (*(begin + m) > temp)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; j--) //��ѭ��2������Ԫ��λ��
            *(begin + j + 1) = *(begin + j);
        *(begin + j + 1) = temp;
    }
}

template <class T>
void InsertionSort_Binary(T begin, T end, int &cs, int &fz)
{
    int len = end - begin + 1;
    int i, j, temp, m, low, high;
    for (i = 1; i < len; i++)
    {
        temp = *(begin + i);
        ++fz;
        low = 0;
        high = i - 1;
        while (low <= high)
        {
            m = (low + high) / 2;
            if (*(begin + m) > temp)
                high = m - 1;
            else
                low = m + 1;
            ++cs;
        }
        for (j = i - 1; j >= high + 1; j--)
        {
            *(begin + j + 1) = *(begin + j);
            ++fz;
        }
        *(begin + j + 1) = temp;
        ++fz;
    }
}