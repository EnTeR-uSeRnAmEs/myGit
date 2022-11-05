template <typename T>
void BubbleSort_sorted(T begin, T end) //ģ��sort()�������������
{
    int n = (end - begin); //��ȡ���ݳ���, nΪʵ�ʳ���-1
    // std::cout << *begin;
    bool sorted = false;                        //(sorted�Ż�)�ж��Ƿ��Ѿ�����
    for (int i = 0; i <= n - 1 && !sorted; i++) //�������ݿ�ʼ������ֱ�������ڶ�������Ϊֹ�������������ѭ��
    {
        for (int j = 0, sorted = true; j <= n - i - 1; j++) //��ѭ��������������ݽ����������������ѭ��
        {
            if (*(begin + j) > *(begin + j + 1))
            {
                auto tmp = *(begin + j + 1);
                *(begin + j + 1) = *(begin + j);
                *(begin + j) = tmp;
                sorted = false; // (sorted�Ż�)
            }
        }
    }
}

template <typename T>
void BubbleSort_Cocktail(T begin, T end) //ģ��sort()�������������
{
    int n = end - begin; //��ȡ���ݳ���, nΪʵ�ʳ���-1
    int left = 0, right = n;
    while (left < right)
    {
        bool sorted = true;                     //(sorted�Ż�)
        for (int i = right - 1; i >= left; i--) //����������ð������
        {
            if (*(begin + i) > *(begin + i + 1))
            {
                exchange(begin + i, begin + i + 1);
                sorted = false; //(sorted�Ż�)
            }
        }
        left++; //ÿ����������һ���������������+1������left

        for (int i = left + 1; i <= right; i++) //����������ð������
        {
            if (*(begin + i) < *(begin + i - 1))
            {
                exchange(begin + i, begin + i - 1);
                sorted = false; //(sorted�Ż�)
            }
        }
        right--;    //ÿ����������һ�����Ҳ���������+1������right
        if (sorted) //(sorted�Ż�)����Ѿ���������ǰ����ѭ��
            break;
    }
}

template <typename T>
void BubbleSort_Comb(T begin, T end) //ģ��sort()�������������
{
    const double RATE = 1.3; //���岽��ϵ��
    int n = end - begin;     //��ȡ���ݳ���, nΪʵ�ʳ���-1
    int increment = n + 1;   //���㲽��
    while (increment > 1)
    {
        increment = (int)(increment / RATE); //���²���
        bool sorted = true;                  //(sorted�Ż�)
        for (int i = 0; i < increment; i++)
        {
            for (int j = i + increment; j <= n; j += increment)
            {
                if (*(begin + j) < *(begin + j - increment)) //���increment�����Ƚϣ�����ð������
                {
                    exchange(begin + j, begin + j - increment);
                    sorted = false; //(sorted�Ż�)
                }
            }
        }
        if (sorted) //(sorted�Ż�)
            break;
    }

    bool sorted = false;                    //(sorted�Ż�)
    for (int i = 0; i <= n && !sorted; i++) //�������ݿ�ʼ������ֱ�������ڶ�������Ϊֹ�������������ѭ��
    {
        for (int j = n, sorted = true; j > i; j--) //��ѭ��������������ݽ����������������ѭ��
        {
            if (*(begin + j) < *(begin + j - 1))
            {
                exchange(begin + j, begin + j - 1);
                sorted = false; //(sorted�Ż�)
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