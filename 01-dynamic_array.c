#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int len = 0, capacity = 10;
int *array;

int size()
{
    return len;
}

int get(int index)
{
    return array[index];
}

int clear()
{
    for (int i = 0; i < capacity; i++)
        array[i] = 0;
}

void checkMoreCapacity()
{
    if (len + 1 >= capacity)
    {
        capacity += 10;
        array = (int *)realloc(array, capacity * sizeof(int));
    }
}
bool isEmpty()
{
    return size() == 0;
}

void set(int index, int element)
{
    array[index] = element;
}

int indexOf(int value)
{
    for (int i = 0; i < size(); i++)
        if (array[i] == value)
            return i;
    return -1;
}

void add(int element)
{
    checkMoreCapacity();
    array[len] = element;
    len++;
}

int removeAt(int index)
{
    int data = -1;
    if (index >= 0 && index <= size())
    {
        for (int i = 0, j = 0; i < size(); i++, j++)
        {
            if (i == index)
            {
                data = array[j];
                j--;
            }
            array[j] = array[i];
        }
    }
    len--;
    return data;
}

void removeValue(int value)
{
    int i = indexOf(value);
    removeAt(i);
}

bool contains(int value)
{
    int i = indexOf(value);
    if (i == -1)
        return false;
    return true;
}

void printAll()
{
    if (isEmpty())
    {
        printf("Empty array!!\n");
        return -1;
    }

    printf("Array: ");
    for (int i = 0; i < size() - 1; i++)
        printf("%d, ", array[i]);
    printf("%d\n", array[size() - 1]);
}

int main()
{
    array = (int *)malloc(capacity * sizeof(int));
    int choice = 0, value, index, element;
    while (choice != 12)
    {
        printf("\n\n01. size \n02. get \n03. clear \n04. isEmpty \n05. set \n06. add \n07. removeAt \n08. removeValue \n09. indexOf \n10. contains \n11. printAll \n12. exit \nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Size: %d\n", size());
            break;
        case 2:
            printf("Enter the index: ");
            scanf("%d", &index);
            printf("Element at %d = %d\n", index, get(index));
            break;
        case 3:
            clear();
            break;
        case 4:
            bool empty = isEmpty();
            if (empty)
                printf("Empty array\n");
            else
                printf("Not empty array\n");
            break;
        case 5:
            printf("Enter the index and the element: ");
            scanf("%d%d", &index, &element);
            set(index, element);
            break;
        case 6:
            printf("Enter the element: ");
            scanf("%d", &element);
            add(element);
            break;
        case 7:
            printf("Enter the index: ");
            scanf("%d", &index);
            removeAt(index);
            break;
        case 8:
            printf("Enter the element: ");
            scanf("%d", &element);
            removeValue(element);
            break;
        case 9:
            printf("Enter the element: ");
            scanf("%d", &value);
            printf("Index of %d = %d\n", value, indexOf(value));
            break;
        case 10:
            printf("Enter the element: ");
            scanf("%d", &value);
            bool containsValue = contains(value);
            if (containsValue)
                printf("Contains %d!!\n", value);
            else
                printf("Doesn't contain %d!!\n", value);
            break;
        case 11:
            printAll();
            break;
        case 12:
            printf("Exiting ... \n");
            break;
        default:
            printf("Invalid choice!! Try again.\n");
            break;
        }
    }
    free(array);
    return 0;
}