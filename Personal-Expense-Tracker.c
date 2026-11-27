#include <stdio.h>
#include <string.h>

struct Record
{
    int id;
    char type[20];
    char category[30];
    char description[50];
    float amount;
};

struct Record r[500];

int count = 0;
int nextId = 1;
float monthlyIncome = 0;

void loadRecords();
void saveRecords();
void addExpense();
void addIncome();
void displayIncome();
void displayRecords();
void remainingBalance();
void monthlySaving();
void updateExpense();
void searchCategory();
void totalExpense();
void deleteExpense();

int main()
{
    int choice;

    loadRecords();

    do
    {
        printf("\n====================================");
        printf("\n PERSONAL EXPENSE MANAGEMENT SYSTEM");
        printf("\n====================================");

        printf("\n1. Add Expense");
        printf("\n2. Add Income");
        printf("\n3. Display Monthly Income");
        printf("\n4. Display Expense Records");
        printf("\n5. Remaining Balance");
        printf("\n6. Monthly Saving");
        printf("\n7. Update Expense");
        printf("\n8. Search Category");
        printf("\n9. Calculate Total Expense");
        printf("\n10. Delete Expense");
        printf("\n11. Save Records");
        printf("\n12. Save and Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addExpense();
                break;

            case 2:
                addIncome();
                break;

            case 3:
                displayIncome();
                break;

            case 4:
                displayRecords();
                break;

            case 5:
                remainingBalance();
                break;

            case 6:
                monthlySaving();
                break;

            case 7:
                updateExpense();
                break;

            case 8:
                searchCategory();
                break;

            case 9:
                totalExpense();
                break;

            case 10:
                deleteExpense();
                break;

            case 11:
                saveRecords();
                break;

            case 12:
                saveRecords();
                printf("\nRecords saved successfully!");
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.");
        }

    } while(choice != 12);

    return 0;
}

// Load saved records
void loadRecords()
{
    FILE *fp;

    fp = fopen("records.dat", "r");

    if(fp == NULL)
        return;

    fscanf(fp, "%f %d %d\n",
           &monthlyIncome, &count, &nextId);

    for(int i = 0; i < count; i++)
    {
        fscanf(fp, "%d\n", &r[i].id);

        fgets(r[i].type, 20, fp);
        r[i].type[strcspn(r[i].type, "\n")] = '\0';

        fgets(r[i].category, 30, fp);
        r[i].category[strcspn(r[i].category, "\n")] = '\0';

        fgets(r[i].description, 50, fp);
        r[i].description[strcspn(r[i].description, "\n")] = '\0';

        fscanf(fp, "%f\n", &r[i].amount);
    }

    fclose(fp);
}

// Save records
void saveRecords()
{
    FILE *fp;

    fp = fopen("records.dat", "w");

    if(fp == NULL)
    {
        printf("\nFile error!");
        return;
    }

    fprintf(fp, "%.2f %d %d\n",
            monthlyIncome, count, nextId);

    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "%d\n", r[i].id);
        fprintf(fp, "%s\n", r[i].type);
        fprintf(fp, "%s\n", r[i].category);
        fprintf(fp, "%s\n", r[i].description);
        fprintf(fp, "%.2f\n", r[i].amount);
    }

    fclose(fp);

    printf("\nRecords saved successfully!");
}

// Add expense
void addExpense()
{
    if(count >= 500)
    {
        printf("\nStorage is full!");
        return;
    }

    r[count].id = nextId++;

    strcpy(r[count].type, "Expense");

    printf("\nEnter category: ");
    scanf(" %29[^\n]", r[count].category);

    printf("Enter description: ");
    scanf(" %49[^\n]", r[count].description);

    printf("Enter amount: ");
    scanf("%f", &r[count].amount);

    if(r[count].amount <= 0)
    {
        printf("\nInvalid amount!");
        return;
    }

    count++;

    printf("\nExpense added successfully!");
}

// Add income
void addIncome()
{
    float amount;

    printf("\nEnter new income amount: ");
    scanf("%f", &amount);

    if(amount <= 0)
    {
        printf("\nInvalid amount!");
        return;
    }

    monthlyIncome += amount;

    printf("\nIncome added successfully!");
}

// Display monthly income
void displayIncome()
{
    printf("\nTotal Monthly Income: Rs. %.2f",
           monthlyIncome);
}

// Display records
void displayRecords()
{
    printf("\n========== ALL RECORDS ==========\n");

    if(count == 0)
    {
        printf("No records found!");
        return;
    }

    for(int i = 0; i < count; i++)
    {
        printf("\nID: %d", r[i].id);
        printf("\nType: %s", r[i].type);
        printf("\nCategory: %s", r[i].category);
        printf("\nDescription: %s", r[i].description);
        printf("\nAmount: Rs. %.2f\n", r[i].amount);
    }
}

// Calculate total expense
void totalExpense()
{
    float total = 0;

    for(int i = 0; i < count; i++)
    {
        if(strcmp(r[i].type, "Expense") == 0)
            total += r[i].amount;
    }

    printf("\nTotal Expense: Rs. %.2f", total);
}

// Remaining balance
void remainingBalance()
{
    float total = 0;

    for(int i = 0; i < count; i++)
    {
        if(strcmp(r[i].type, "Expense") == 0)
            total += r[i].amount;
    }

    printf("\nRemaining Balance: Rs. %.2f",
           monthlyIncome - total);
}

// Monthly savings
void monthlySaving()
{
    float total = 0;

    for(int i = 0; i < count; i++)
    {
        if(strcmp(r[i].type, "Expense") == 0)
            total += r[i].amount;
    }

    printf("\nMonthly Savings: Rs. %.2f",
           monthlyIncome - total);
}

// Update expense
void updateExpense()
{
    int id, found = 0;

    printf("\nEnter Expense ID: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(r[i].id == id &&
           strcmp(r[i].type, "Expense") == 0)
        {
            printf("Enter new category: ");
            scanf(" %29[^\n]", r[i].category);

            printf("Enter new description: ");
            scanf(" %49[^\n]", r[i].description);

            printf("Enter new amount: ");
            scanf("%f", &r[i].amount);

            if(r[i].amount <= 0)
            {
                printf("\nInvalid amount!");
                return;
            }

            found = 1;
            printf("\nExpense updated successfully!");
            break;
        }
    }

    if(found == 0)
        printf("\nExpense not found!");
}

// Search by category
void searchCategory()
{
    char category[30];
    int found = 0;

    printf("\nEnter category to search: ");
    scanf(" %29[^\n]", category);

    for(int i = 0; i < count; i++)
    {
        if(strcmp(r[i].category, category) == 0 &&
           strcmp(r[i].type, "Expense") == 0)
        {
            printf("\nID: %d", r[i].id);
            printf("\nCategory: %s", r[i].category);
            printf("\nDescription: %s", r[i].description);
            printf("\nAmount: Rs. %.2f\n", r[i].amount);

            found = 1;
        }
    }

    if(found == 0)
        printf("\nCategory not found!");
}

// Delete expense
void deleteExpense()
{
    int id, found = 0;

    printf("\nEnter Expense ID to delete: ");
    scanf("%d", &id);

    for(int i = 0; i < count; i++)
    {
        if(r[i].id == id &&
           strcmp(r[i].type, "Expense") == 0)
        {
            for(int j = i; j < count - 1; j++)
            {
                r[j] = r[j + 1];
            }

            count--;
            found = 1;

            printf("\nExpense deleted successfully!");
            break;
        }
    }

    if(found == 0)
        printf("\nExpense not found!");
}