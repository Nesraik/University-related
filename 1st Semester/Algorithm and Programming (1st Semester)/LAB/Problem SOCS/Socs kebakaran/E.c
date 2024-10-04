#include <stdio.h>

void quickSort(int *num, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = num[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (num[i] <= pivot)
        {
            int temp = num[i];
            num[i] = num[pIndex];
            num[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = num[end];
    num[end] = num[pIndex];
    num[pIndex] = temp;
    quickSort(num, start, pIndex - 1);
    quickSort(num, pIndex + 1, end);
}
int main(void)
{
    int t;
    scanf("%d", &t);
    for (int tt = 1; tt <= t; tt++)
    {
        int num[25], ans[5], ind = 1, sum = 0;
        int done[25] = {0};

        for (int i = 0; i < 25; i++)
        {
            scanf("%d", &num[i]);
            sum += num[i];
        }
        quickSort(num, 0, 24);

        ans[0] = num[0] / 2;
        done[0] = 1;

        int j = 0;
        for (; ind < 5; ind++)
        {
            while (j < 25 && done[j])
                j++;

            ans[ind] = num[j] - ans[0];

            for (int i = 0; i < ind; i++)
            {
                int cnt = 0;
                for (int k = 0; (k < 25 && cnt < 2); k++)
                {
                    if (!done[k] &&  num[k] == (ans[i] + ans[ind]))
                    {
                        done[k] = 1;
                        cnt++;
                    }
                }
            }

            for (int i = 0; i < 25; i++)
            {
                if (!done[i] && num[i] == (ans[ind] * 2))
                {
                    done[i] = 1;
                    break;
                }
            }
        }

        printf("Case #%d: ", tt);
        for (int i = 0; i < 5; i++)
            (i == 4) ? printf("%d", ans[i]) : printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}
