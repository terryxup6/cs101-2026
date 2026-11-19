#include <stdio.h>

typedef struct Books
{
    int id;
    int price;
    char title[100];
} book_t;

// 計算所有書籍總價
void total_price(book_t books[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += books[i].price;
    }

    printf("Total Price: %d\n", total);
}

// 輸出所有書籍資料
void list_books(book_t books[], int n)
{
    printf("\n");
    printf("ID\tPrice\tTitle\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%s\n",
               books[i].id,
               books[i].price,
               books[i].title);
    }
}

int main()
{
    book_t books[6] =
    {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    book_t read_books[6];

    FILE *fp;

    // 將書籍資料寫入 Book.bin
    fp = fopen("Book.bin", "wb");

    if (fp == NULL)
    {
        printf("File open error!\n");
        return 1;
    }

    fwrite(books, sizeof(book_t), 6, fp);

    fclose(fp);

    // 從 Book.bin 讀取書籍資料
    fp = fopen("Book.bin", "rb");

    if (fp == NULL)
    {
        printf("File open error!\n");
        return 1;
    }

    fread(read_books, sizeof(book_t), 6, fp);

    fclose(fp);

    // 計算總價
    total_price(read_books, 6);

    // 輸出書籍資料
    list_books(read_books, 6);

    return 0;
}
