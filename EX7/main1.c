#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int lotto[7];
    int i, j, k;
    int num, duplicate;

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

    // 取得目前日期與時間
    now = time(NULL);
    t = localtime(&now);

    // 輸出檔案標題
    fprintf(fp, "========== lotto649 ==========\n");
    fprintf(fp, "= %s", asctime(t));

    // 固定輸出五組
    for (i = 0; i < 5; i++)
    {
        fprintf(fp, "[%d]: ", i + 1);

        if (i < n)
        {
            // 產生七個不重複的數字
            for (j = 0; j < 7; j++)
            {
                do
                {
                    num = rand() % 69 + 1;
                    duplicate = 0;

                    for (k = 0; k < j; k++)
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

            // 輸出七個數字
            for (j = 0; j < 7; j++)
            {
                fprintf(fp, "%02d ", lotto[j]);
            }
        }
        else
        {
            // 未購買的組數以 -- 顯示
            fprintf(fp, "-- -- -- -- -- -- --");
        }

        fprintf(fp, "\n");
    }

    // 輸出檔案結尾
    fprintf(fp, "========== csie@CGU ==========\n");

    fclose(fp);

    printf("已為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}


