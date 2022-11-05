template <typename T>
void InsertionSort_Shell(T begin, T end)
{
    int h = 1, len = end - begin + 1;
    while (h < len / 3) //选取增量(此处为非整除增量)
        h = 3 * h + 1;
    while (h >= 1) //持续循环直到增量为1，即退化为直接插入排序后结束
    {
        for (int i = h; i < len; i++) //选取间隔h的数据进行排序
        {
            for (int j = i; j >= h && *(begin + j) < *(begin + j - h); j -= h) //判断元素位置并交换元素(直接插入排序)
                exchange(*(begin + j), *(begin + j - h));
        }
        h = h / 3;
    }
}

template <typename T>
void InsertionSort_Shell(T begin, T end, int &cs, int &fz)
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
            ++cs; //这边之前漏了
        }
        h = h / 3;
    }
}