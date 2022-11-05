template <typename T>
void InsertionSort_Shell(T begin, T end)
{
    int h = 1, len = end - begin + 1;
    while (h < len / 3) //ѡȡ����(�˴�Ϊ����������)
        h = 3 * h + 1;
    while (h >= 1) //����ѭ��ֱ������Ϊ1�����˻�Ϊֱ�Ӳ�����������
    {
        for (int i = h; i < len; i++) //ѡȡ���h�����ݽ�������
        {
            for (int j = i; j >= h && *(begin + j) < *(begin + j - h); j -= h) //�ж�Ԫ��λ�ò�����Ԫ��(ֱ�Ӳ�������)
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
            ++cs; //���֮ǰ©��
        }
        h = h / 3;
    }
}