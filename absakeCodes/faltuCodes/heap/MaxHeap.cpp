#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{

    vector<int> arr;
    int size;
    int total_size;

public:
    MaxHeap(int _n) : arr(_n), size(0), total_size(_n) {}

    void insert(int num)
    {
        // check if it's overflow
        if (size == total_size)
        {
            cout << "Heap Overflow\n";
            return;
        }

        arr[size] = num;
        int index = size;
        size++;

        while (index > 0 && arr[(index - 1) / 2] < num)
        {

            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << arr[index] << " is inserted into heap " << endl;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    MaxHeap H(6);

    H.insert(4);
    H.insert(14);
    H.insert(24);
    H.insert(214);
    H.insert(40);
    H.insert(10);
    H.insert(13);
    H.print();
}