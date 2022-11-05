template <typename T>
void BubbleSort_sorted(T begin, T end) //模仿sort()函数的输入参数
{
    int n = (end - begin); //获取数据长度, n为实际长度-1
    // std::cout << *begin;
    bool sorted = false;                        //(sorted优化)判断是否已经有序
    for (int i = 0; i <= n - 1 && !sorted; i++) //从首数据开始遍历，直到倒数第二个数据为止，若有序则结束循环
    {
        for (int j = 0, sorted = true; j <= n - i - 1; j++) //内循环控制排序的数据交换，若有序则结束循环
        {
            if (*(begin + j) > *(begin + j + 1))
            {
                auto tmp = *(begin + j + 1);
                *(begin + j + 1) = *(begin + j);
                *(begin + j) = tmp;
                sorted = false; // (sorted优化)
            }
        }
    }
}

template <typename T>
void BubbleSort_Cocktail(T begin, T end) //模仿sort()函数的输入参数
{
    int n = end - begin; //获取数据长度, n为实际长度-1
    int left = 0, right = n;
    while (left < right)
    {
        bool sorted = true;                     //(sorted优化)
        for (int i = right - 1; i >= left; i--) //从右向左做冒泡排序
        {
            if (*(begin + i) > *(begin + i + 1))
            {
                exchange(begin + i, begin + i + 1);
                sorted = false; //(sorted优化)
            }
        }
        left++; //每从右向左排一次序，左侧有序数列+1，右移left

        for (int i = left + 1; i <= right; i++) //从左向右做冒泡排序
        {
            if (*(begin + i) < *(begin + i - 1))
            {
                exchange(begin + i, begin + i - 1);
                sorted = false; //(sorted优化)
            }
        }
        right--;    //每从左向右排一次序，右侧有序数列+1，左移right
        if (sorted) //(sorted优化)如果已经有序，则提前跳出循环
            break;
    }
}

template <typename T>
void BubbleSort_Comb(T begin, T end) //模仿sort()函数的输入参数
{
    const double RATE = 1.3; //定义步长系数
    int n = end - begin;     //获取数据长度, n为实际长度-1
    int increment = n + 1;   //计算步长
    while (increment > 1)
    {
        increment = (int)(increment / RATE); //更新步长
        bool sorted = true;                  //(sorted优化)
        for (int i = 0; i < increment; i++)
        {
            for (int j = i + increment; j <= n; j += increment)
            {
                if (*(begin + j) < *(begin + j - increment)) //间隔increment项作比较，并作冒泡排序
                {
                    exchange(begin + j, begin + j - increment);
                    sorted = false; //(sorted优化)
                }
            }
        }
        if (sorted) //(sorted优化)
            break;
    }

    bool sorted = false;                    //(sorted优化)
    for (int i = 0; i <= n && !sorted; i++) //从首数据开始遍历，直到倒数第二个数据为止，若有序则结束循环
    {
        for (int j = n, sorted = true; j > i; j--) //内循环控制排序的数据交换，若有序则结束循环
        {
            if (*(begin + j) < *(begin + j - 1))
            {
                exchange(begin + j, begin + j - 1);
                sorted = false; //(sorted优化)
            }
        }
    }
}

template <typename T>
void BubbleSort(T begin, T end, long long &cs, long long &fz)
{
    int n = (end - begin);
    // std::cout << *begin;
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            ++cs;
            if (*(begin + j) > *(begin + j + 1))
            {
                auto tmp = *(begin + j + 1);
                *(begin + j + 1) = *(begin + j);
                *(begin + j) = tmp;
                fz += 3;
            }
        }
    }
}

template <typename T>
void BubbleSort_Cocktailc(T begin, T end, long long &cs, long long &fz)
{
    int n = end - begin;
    int left = 0, right = n;
    while (left < right)
    {
        for (int i = right - 1; i >= left; i--)
        {
            if (*(begin + i) > *(begin + i + 1))
            {
                exchange(begin + i, begin + i + 1);
                fz = fz + 3;
            }
            cs++;
        }
        left++;

        for (int i = left + 1; i <= right; i++)
        {
            if (*(begin + i) < *(begin + i - 1))
            {
                exchange(begin + i, begin + i - 1);
                fz = fz + 3;
            }
            cs++;
        }
        right--;
    }
    BubbleSort(begin, end, cs, fz);
}

template <typename T>
void BubbleSort_Combc(T begin, T end, long long &cs, long long &fz)
{
    const double RATE = 1.3;
    int n = end - begin;
    int increment = n + 1;
    while (increment > 1)
    {
        increment = (int)(increment / RATE);
        fz++;
        for (int i = 0; i < increment; i++)
        {
            for (int j = i + increment; j <= n; j += increment)
            {
                if (*(begin + j) < *(begin + j - increment))
                {
                    exchange(begin + j, begin + j - increment);
                    fz += 3;
                }
                cs++;
            }
        }
    }
}