#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Number of menu items
#define NUM_ITEMS 10

// Menu items have item name and price
typedef struct
{
    string item;
    float price;
} menu_item;

// Array of menu items
menu_item menu[NUM_ITEMS];

// Add items to menu
void add_items(void);

// Calculate total cost
float get_cost(string item);

int main(void)
{
    add_items();

    printf("\nWelcome to Beach Burger Shack!\n");
    printf("Choose from the following menu to order. Press enter when done.\n\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("%s: $%.2f\n", menu[i].item, menu[i].price);
    }
    printf("\n");

    float total = 0;
    while (true)
    {
        string item = get_string("Enter a food item: ");
        if (strlen(item) == 0)
        {
            printf("\n");
            break;
        }

        total += get_cost(item);
    }

    printf("Your total cost is: $%.2f\n", total);
}

// Add at least the first four items to the menu array
void add_items(void)
{
    menu[0] = (menu_item){"Burger", 9.5};
    menu[1] = (menu_item){"Vegan Burger", 11.0};
    menu[2] = (menu_item){"Hot Dog", 5.0};
    menu[3] = (menu_item){"Cheese Dog", 7.0};
    menu[4] = (menu_item){"Fries", 5.0};
    menu[5] = (menu_item){"Cheese Fries", 6.0};
    menu[6] = (menu_item){"Cold Pressed Juice", 7.0};
    menu[7] = (menu_item){"Cold Brew", 3.0};
    menu[8] = (menu_item){"Water", 2.0};
    menu[9] = (menu_item){"Soda", 2.0};
}

// Search through the menu array to find an item's cost
float get_cost(string item)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (strcasecmp(menu[i].item, item) == 0)
        {
            return menu[i].price;
        }
    }
    printf("Item not found: %s\n", item);
    return 0.0;
}
