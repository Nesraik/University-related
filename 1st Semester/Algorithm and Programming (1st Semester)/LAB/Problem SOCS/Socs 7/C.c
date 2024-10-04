#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptr;
    int caselimit;
    ptr = fopen("testdata.in", "r");
    if (NULL == ptr)
    {
        printf("Error\n");
    }
    fscanf(ptr, "%d", &caselimit);
    fgetc(ptr);
    for (int casenumber = 1; casenumber <= caselimit; casenumber++)
    {
        int size, time;
        int x, y;
        fscanf(ptr, "%d", &size);
        fgetc(ptr);
        fscanf(ptr, "%d", &time);

        char array[1001][1001];
        for (int i = 0; i < size; i++)
        {
            fgetc(ptr);
            for (int j = 0; j <size; j++)
            {
                fscanf(ptr, "%c", &array[i][j]);
                if (array[i][j] == 'F')
                {
                    x = i;
                    y = j;
                }
            }
        }
        fgetc(ptr);
        if (time != 1)
        {
            time--;
            for (int i = x - time; i <= x + time; i++)
            {
                for (int j = y - time; j <= y + time; j++)
                {
                    if (j >= 0 && i >= 0 && i <= size - 1 && j <= size - 1)
                        array[i][j] = 'F';
                }
            }
        }
        printf("Case #%d:\n", casenumber);
        for (size_t i = 0; i <size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                printf("%c", array[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
