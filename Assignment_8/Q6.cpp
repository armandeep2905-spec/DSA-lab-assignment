#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;

class minHeap
{
public:
    int arr[100];
    int index;
    minHeap()
    {
        index = 1;
    }
    int top()
    {
        return arr[1];
    }
    void push(int val)
    {
        cout << "pushing" << "->" << val << endl;
        arr[index] = val;
        int i = index;
        index++;
        while (i != 1)
        {
            int parent = i / 2;
            if (arr[i] < arr[parent])
            {
                swap(arr[i], arr[parent]);
            }
            else
                break;
            i = parent;
        }
    }
void pop()
{
    if (index == 1) return; // heap empty

    index--;                  // reduce index
    arr[1] = arr[index];      // move last element to root

    int i = 1;                // MUST be outside the loop

    while (true)
    {
        int left = 2 * i;
        int right = 2 * i + 1;

        // No children
        if (left >= index)
            break;

        // Pick smaller child
        int smallerChild = left;

        if ( right<index && arr[right] < arr[left])
            smallerChild = right;

        // If parent already smaller → stop
        if (arr[i] <= arr[smallerChild])
            break;

        // Swap with smaller child
        swap(arr[i], arr[smallerChild]);

        // Move downward
        i = smallerChild;
    }
}

   
    
        

    void display()
    {
        for (int i = 1; i <= index - 1; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    minHeap mh;
    mh.push(10);
    mh.push(20);
    mh.push(100);
    mh.push(30);

    mh.push(40);
    mh.push(12);

    mh.push(4);
    mh.display();

    mh.pop();

    mh.display();
}