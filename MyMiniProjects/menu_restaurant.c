#include <stdio.h>

#define MAX_ORDERS 50

enum Menu {
    COFFE = 0,
    TEA = 1,
    JUICE = 2,
    EXIT = 3,
};

typedef struct{
    const char* name;
    int price;
}Drink;

void print_menu() {
    printf("\n0 - Coffee (100 rub)\n1 - Tea (80 rub)\n2 - Juice (120 rub)\n3 - Exit\n");
}

void print_receipt(Drink menu[], int orders[], int count) {
    int total = 0;
    printf("\nBill:\n");
    for (int i = 0; i < count; i++) {
        printf("%s: %d rub\n", menu[orders[i]].name, menu[orders[i]].price);
        total += menu[orders[i]].price;
    }
    printf("Total: %d rub\n", total);
}

int main() {
    Drink menu[] = {{"Coffee", 100}, {"Tea", 80}, {"Juice", 120}};
    int orders[MAX_ORDERS], order_count = 0, choice;

    do {
        print_menu();
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice < 0 || choice > EXIT) {
            printf("Error\n");
            continue;
        }

        if (order_count >= MAX_ORDERS && choice != EXIT) {
            printf("Order limit reached\n");
            continue;
        }

        switch (choice) {
            case COFFE:
            case TEA:
            case JUICE:
                orders[order_count++] = choice;
                printf("Added %s\n", menu[choice].name);
                break;
            case EXIT:
                print_receipt(menu, orders, order_count);
                break;
        }
    } while (choice != EXIT);

    return 0;
}
