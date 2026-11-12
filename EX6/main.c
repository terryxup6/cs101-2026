#include <stdio.h>
#include <string.h>

// 1. 定義 employee_t 結構
typedef struct employee {
    int id;
    char name[12];
    int age;
    float salary;
} employee_t;

// 函式宣告
void emp_info(employee_t emp);
int emp_average_age(employee_t emp[], int n);
void emp_writefile(employee_t emp[], int n);
void emp_readfile(employee_t emp[]);

int main() {
    // 建立 3 位員工的測試資料（對應講義範例）
    employee_t emp[3];
    
    emp[0].id = 1;
    emp[0].age = 20;
    emp[0].salary = 30000.0;
    strcpy(emp[0].name, "IU");

    emp[1].id = 2;
    emp[1].age = 26;
    emp[1].salary = 36000.0;
    strcpy(emp[1].name, "taylor");

    emp[2].id = 3;
    emp[2].age = 31;
    emp[2].salary = 90000.0;
    strcpy(emp[2].name, "swift");

    // 計算並印出平均年齡
    int avg_age = emp_average_age(emp, 3);
    printf("Average age: %d\n\n", avg_age);

    // 將結構陣列寫入二進位檔案 employee.bin
    emp_writefile(emp, 3);

    // 宣告一個用來讀取檔案的暫存結構陣列
    employee_t read_emp[10];
    
    printf("--- Read from employee.bin ---\n");
    emp_readfile(read_emp);

    return 0;
}

// 2. 印出單一員工詳細資訊的函式
void emp_info(employee_t emp) {
    printf("employee id = %d\n", emp.id);
    printf("employee name = %s\n", emp.name);
    printf("employee age = %d\n", emp.age);
    printf("employee salary = %f\n\n", emp.salary);
}

// 3. 計算平均年齡的函式
int emp_average_age(employee_t emp[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += emp[i].age;
    }
    return sum / n;
}

// 4. 將結構寫入二進位檔案的函式 (使用指標寫法)
void emp_writefile(employee_t emp[], int n) {
    FILE* fp = fopen("employee.bin", "wb+");
    if (fp == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        // 使用指標寫法 (emp + i) 將資料寫入檔案
        fwrite(emp + i, sizeof(employee_t), 1, fp);
    }

    fclose(fp);
}

// 5. 從二進位檔案讀取結構的函式並印出
void emp_readfile(employee_t emp[]) {
    FILE* fp = fopen("employee.bin", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    int i = 0;
    // 使用指標寫法 (emp + i) 讀取檔案內容
    while (fread(emp + i, sizeof(employee_t), 1, fp)) {
        printf("[%d] id: %d, name: %s\n", i, emp[i].id, emp[i].name);
        // 同時呼叫 emp_info 印出詳細資料
        emp_info(emp[i]);
        i++;
    }

    fclose(fp);
}
