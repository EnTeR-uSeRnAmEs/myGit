
template <typename T> void BubbleSort(T begin, T end);
template <typename T>
void BubbleSort_Cocktail(T begin, T end)
{
    int n = end - begin;
    int left = 0, right = n;
    while(left < right)
    {
        for(int i = right - 1; i >= left; i--)
        {
            if(*(begin + i) > *(begin + i + 1))
            {
                exchange(begin + i, begin + i + 1);
            }
        }
        left++;

        for(int i = left + 1; i <= right; i++)
        {
            if(*(begin + i) < *(begin + i - 1))
            {
                exchange(begin + i, begin + i - 1);
            }
        }
        right--;

    }
}

template <typename T>
void BubbleSort_Comb(T begin, T end)
{
    const double RATE = 1.3;
    int n = end - begin;
    int increment = n + 1;
    while(increment > 1)
    {
        increment = (int)(increment / RATE);
        for(int i = 0; i < increment; i++)
        {
            for(int j = i + increment; j <= n; j += increment)
            {
                if(*(begin + j) < *(begin + j - increment))
                {
                    exchange(begin + j, begin + j - increment);
                }

            }
        }
    }
    BubbleSort(begin, end);
}

template <typename T>
void BubbleSort_Cocktailc(T begin, T end, long long &cs, long long &fz)
{
    int n = end - begin;
    int left = 0, right = n;
    while(left < right)
    {
        for(int i = right - 1; i >= left; i--)
        {
            if(*(begin + i) > *(begin + i + 1))
            {
                exchange(begin + i, begin + i + 1);
                fz = fz + 3;
            }
            cs++;
        }
        left++;

        for(int i = left + 1; i <= right; i++)
        {
            if(*(begin + i) < *(begin + i - 1))
            {
                exchange(begin + i, begin + i - 1);
                fz = fz + 3;
            }
            cs++;
        }
        right--;

    }
    BubbleSort(begin, end);
}

template <typename T>
void BubbleSort_Combc(T begin, T end, long long &cs, long long &fz)
{
    const double RATE = 1.3;
    int n = end - begin;
    int increment = n + 1;
    while(increment > 1)
    {
        increment = (int)(increment / RATE);
        fz++;
        for(int i = 0; i < increment; i++)
        {
            for(int j = i + increment; j <= n; j += increment)
            {
                if(*(begin + j) < *(begin + j - increment))
                {
                    exchange(begin + j, begin + j - increment);
                    fz = fz + 3;
                }
                cs++;

            }
        }
    }
}


template <typename T>
void BubbleSort(T begin, T end)
{
    int n = (end - begin);
    //std::cout << *begin;
    for(int i = 0; i <= n - 1; i++)
    {
        for(int j = 0; j <= n - i - 1; j++)
        {
            if(*(begin + j) > *(begin + j + 1))
            {
                auto tmp = *(begin + j + 1);
                *(begin + j + 1) = *(begin + j);
                *(begin + j) = tmp;
            }
        }
    }
}


template <typename T>
void BubbleSortc(T begin, T end, long long &cs, long long &fz)
{
    int n = (end - begin);
    //std::cout << *begin;
    for(int i = 0; i <= n - 1; i++)
    {
        for(int j = 0; j <= n - i - 1; j++)
        {
            if(*(begin + j) > *(begin + j + 1))
            {
                ++cs;
                auto tmp = *(begin + j + 1);
                *(begin + j + 1) = *(begin + j);
                *(begin + j) = tmp;
                fz += 3;
            }
        }
    }
}
