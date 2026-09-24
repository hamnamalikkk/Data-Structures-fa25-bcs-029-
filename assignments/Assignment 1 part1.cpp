#include <iostream>
#include <cmath>
using namespace std;

const int CAPACITY = 20;

struct ArrayList
{
    int data[CAPACITY];
    int size = 0;
};

// Insert value at the end
bool insertEnd(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;

    list.data[list.size] = value;
    list.size++;

    return true;
}

// Insert value at the beginning
bool insertAtBeginning(ArrayList &list, int value)
{
    if (list.size >= CAPACITY)
        return false;

    // Shift elements one position to the right
    for (int i = list.size; i > 0; i--)
    {
        list.data[i] = list.data[i - 1];
    }

    list.data[0] = value;
    list.size++;

    return true;
}

// Delete element from a given position
bool deleteAtPosition(ArrayList &list, int position)
{
    if (position < 0 || position >= list.size)
        return false;

    // Shift elements one position to the left
    for (int i = position; i < list.size - 1; i++)
    {
        list.data[i] = list.data[i + 1];
    }

    list.size--;

    return true;
}

// Display ArrayList
void displayList(const ArrayList &list)
{
    for (int i = 0; i < list.size; i++)
    {
        cout << list.data[i] << " ";
    }

    cout << endl;
}

int main()
{
    ArrayList list;

    int *ptr = list.data;

    int minimum;
    int maximum;
    int median;
    int closestValue;
    int closestPosition;

    int sum = 0;

    double generalAverage;
    double specialAverage;
    double averageDifference;
    double finalScore;

    // ------------------------------------------------
    // PART A: Create and Populate ArrayList
    // ------------------------------------------------

    // Replace 08 with your own registration number's
    // last two digits.
    insertEnd(list, 18);
    insertEnd(list, 7);
    insertEnd(list, 45);
    insertEnd(list, 11);
    insertEnd(list, 36);
    insertEnd(list, 29);
    insertEnd(list, 21);
    insertEnd(list, 13);
    insertEnd(list, 29);

    cout << "Initial ArrayList: ";
    displayList(list);


    // ------------------------------------------------
    // PART B: Pointer Traversal, Sum, Minimum, Maximum
    // ------------------------------------------------

    ptr = list.data;

    minimum = *ptr;
    maximum = *ptr;

    for (int i = 0; i < list.size; i++)
    {
        // Dereference pointer to get current value
        int value = *ptr;

        sum = sum + value;

        if (value < minimum)
        {
            minimum = value;
        }

        if (value > maximum)
        {
            maximum = value;
        }

        // Move pointer to next element
        ptr++;
    }

    cout << "Minimum Value: " << minimum << endl;
    cout << "Maximum Value: " << maximum << endl;
    cout << "Sum: " << sum << endl;


    // ------------------------------------------------
    // PART C: Find Median
    // ------------------------------------------------

    // Temporary array containing only logical elements
    int temp[CAPACITY];

    for (int i = 0; i < list.size; i++)
    {
        temp[i] = list.data[i];
    }

    // Manual sorting using Bubble Sort
    for (int i = 0; i < list.size - 1; i++)
    {
        for (int j = 0; j < list.size - i - 1; j++)
        {
            if (temp[j] > temp[j + 1])
            {
                int swapValue = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swapValue;
            }
        }
    }

    // Since there are 9 elements
    median = temp[list.size / 2];

    cout << "Median Value: " << median << endl;


    // ------------------------------------------------
    // PART D: Averages and Closest Value
    // ------------------------------------------------

    generalAverage = (double)sum / list.size;

    specialAverage = (minimum + median + maximum) / 3.0;

    // Traverse ArrayList again using ptr
    ptr = list.data;

    closestValue = *ptr;
    closestPosition = 0;

    double smallestDistance =
        fabs(*ptr - specialAverage);

    for (int i = 0; i < list.size; i++)
    {
        double distance =
            fabs(*ptr - specialAverage);

        if (distance < smallestDistance)
        {
            smallestDistance = distance;
            closestValue = *ptr;
            closestPosition = i;
        }

        ptr++;
    }

    cout << "General Average: " << generalAverage << endl;
    cout << "Special Average: " << specialAverage << endl;
    cout << "Closest Value: " << closestValue << endl;
    cout << "Position of Closest Value: "
         << closestPosition << endl;


    // ------------------------------------------------
    // PART E: Final Calculations
    // ------------------------------------------------

    averageDifference =
        fabs(generalAverage - specialAverage);

    finalScore =
        fabs(closestValue - generalAverage)
        + fabs(closestValue - specialAverage)
        + averageDifference;

    cout << "Difference Between Averages: "
         << averageDifference << endl;

    cout << "Final Score: "
         << finalScore << endl;


    // ------------------------------------------------
    // Delete closest value
    // ------------------------------------------------

    deleteAtPosition(list, closestPosition);

    cout << "ArrayList After Deletion: ";
    displayList(list);


    // ------------------------------------------------
    // Round Special Average and insert at beginning
    // ------------------------------------------------

    int roundedSpecialAverage =
        (int)round(specialAverage);

    insertAtBeginning(list, roundedSpecialAverage);

    cout << "Final ArrayList After Insertion: ";
    displayList(list);

    return 0;
}
