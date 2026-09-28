#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h" // Include the header file that defines the Item structure and related functions

void add_item(Item *item_list, double price, char *sku, char *category, char *name, int index)
{
    item_list[index].price = price; // Set the price of the item at the specified index

    item_list[index].sku = malloc((strlen(sku) + 1) * sizeof(char)); // Allocate memory for the SKU string
    strcpy(item_list[index].sku, sku);

    item_list[index].category = malloc((strlen(category) + 1) * sizeof(char)); // Allocate memory for the category string
    strcpy(item_list[index].category, category);

    item_list[index].name = malloc((strlen(name) + 1) * sizeof(char)); // Allocate memory for the name string
    strcpy(item_list[index].name, name);
}

void free_items(Item *item_list, int size) 
{
    for (int i = 0; i < size; i++) // Free the dynamically allocated memory for each item's strings
    {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
    free(item_list);
}

double average_price(Item *item_list, int size) 
{
    double total = 0.0; // Initialize a variable to hold the total price of all items

    for (int i = 0; i < size; i++) // Calculate the total price of all items in the list
    {
        total += item_list[i].price; // Add the price of the current item to the total
    }

    return total / size; // Return the average price by dividing the total price by the number of items
}

void print_items(Item *item_list, int size) 
{
    for (int i = 0; i < size; i++) // Loop through each item in the list and print its details
    {
        printf("###############\n"); // Print a separator line for each item
        printf("item name = %s\n", item_list[i].name); // Print the name of the item
        printf("item sku = %s\n", item_list[i].sku); // Print the SKU of the item
        printf("item category = %s\n", item_list[i].category);  // Print the category of the item
        printf("item price = %.6f\n", item_list[i].price); // Print the price of the item with 6 decimal places
    }
}

int main(int argc, char *argv[]) 
{
    int size = 5;
    Item *item_list = malloc(size * sizeof(Item)); // Dynamically allocate memory for an array of Item structures

    add_item(item_list, 5.00, "19282", "breakfast", "reese's cereal", 0); // Add the first item to the list
    add_item(item_list, 3.95, "79862", "dairy", "milk", 1); // Add the second item to the list
    add_item(item_list, 2.50, "14512", "snacks", "granola bar", 2); // Add the third item to the list
    add_item(item_list, 9.99, "55021", "baking", "flour", 3); // Add the fourth item to the list
    add_item(item_list, 7.25, "31241", "produce", "apples", 4); // Add the fifth item to the list

    print_items(item_list, size); // Print the details of all items in the list
    printf("average price of items = %.6f\n", average_price(item_list, size)); // Print the average price of all items in the list

    if (argc > 1)
    {
        int i = 0;
        while (i < size && strcmp(item_list[i].sku, argv[1]) != 0) // Search for the item with the specified SKU
        {
            i++; // Increment the index until the item is found or the end of the list is reached
        }

        if (i < size) // If the item with the specified SKU is found, print its details
        {
            printf("###############\n"); // Print a separator line for the found item
            printf("item name = %s\n", item_list[i].name); // Print the name of the found item
            printf("item sku = %s\n", item_list[i].sku); // Print the SKU of the found item
            printf("item category = %s\n", item_list[i].category);  // Print the category of the found item
            printf("item price = %.6f\n", item_list[i].price); // Print the price of the found item with 6 decimal places
        }
        else // If the item with the specified SKU is not found, print a message indicating that the item was not found
        {
            printf("item not found\n"); // Print a message if the item with the specified SKU is not found
        }
    }

    free_items(item_list, size);  // Free the dynamically allocated memory for the item list and its strings

    return 0;
}