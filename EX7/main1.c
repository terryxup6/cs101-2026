// main1.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int lotto[7];
    int i, j, num;
    int duplicate;
    FILE *fp;
    time_t now;
    struct tm *t;

    srand(time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透：");
    scanf("%d", &n);

    if (n < 1 || n > 5)
    {
        printf("輸入錯誤！請輸入 1 ~ 5\n");
        return 0;
    }

    fp = fopen("lotto.txt", "w");

    if (fp == NULL)
    {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    now = time(NULL);
    t = localtime(&now);

    fprintf(fp, "========== lotto649 ==========\n");
    fprintf(fp, "%s", " = ");

    fprintf(fp, "%s", asctime(t));

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 7; j++)
        {
            do
            {
                num = rand() % 69 + 1;
                duplicate = 0;

                for (int k = 0; k < j; k++)
                {
                    if (lotto[k] == num)
                    {
                        duplicate = 1;
                        break;
                    }
                }

            } while (duplicate);

            lotto[j] = num;
        }

        fprintf(fp, "[%d]: ", i + 1);

        for (j = 0; j < 7; j++)
        {
            fprintf(fp, "%02d ", lotto[j]);
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "========== csie@CGU ==========\n");

    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
