template <class T>
void InsertionSort_Binary(T begin, T end)
{
    int len = end - begin + 1; //通过首尾地址计算出数据长度
    int i, j, temp, m, low, high;
    for (i = 1; i < len; i++) //外循环表里需要插入的数字
    {
        temp = *(begin + i);
        low = 0;
        high = i - 1;
        while (low <= high) //内循环1：二分法查找元素应插入的位置
        {
            m = (low + high) / 2;
            if (*(begin + m) > temp)
                high = m - 1;
            else
                low = m + 1;
        }
        for (j = i - 1; j >= high + 1; j--) //内循环2：交换元素位置
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