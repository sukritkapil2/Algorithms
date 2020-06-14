/*
Heap data structure is a complete binary tree that satisfies the heap property. 
It is also called as a binary heap.

Heapify is the process of creating a heap data structure from a binary tree. 
It is used to create a Min-Heap or a Max-Heap.

Start from the first index of non-leaf node whose index is given by n/2 - 1.

Max Heap Data Structure in C++
*/

#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b) {
  int temp = *b;
  *b = *a;
  *a = temp;
}

void heapify(vector<int> &hT, int i) {
  int size = hT.size();
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if (l < size && hT[l] > hT[largest])
    largest = l;
  if (r < size && hT[r] > hT[largest])
    largest = r;

  if (largest != i)
  {
    swap(&hT[i], &hT[largest]);
    heapify(hT, largest);
  }
}

/*
Insert the new element at the end of the tree.
Heapify the tree.
*/

void insert(vector<int> &hT, int newNum) {
  int size = hT.size();
  if (size == 0)
  {
    hT.push_back(newNum);
  }
  else
  {
    hT.push_back(newNum);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(hT, i);
    }
  }
}

/*
Select the element to be deleted.
Swap it with the last element.
Remove the last element.
Heapify the tree.
*/

void deleteNode(vector<int> &hT, int num) {
  int size = hT.size();
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == hT[i])
      break;
  }
  swap(&hT[i], &hT[size - 1]);

  hT.pop_back();
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(hT, i);
  }
}

void printArray(vector<int> &hT) {
  for (int i = 0; i < hT.size(); ++i)
    cout << hT[i] << " ";
  cout << "\n";
}

int main() {
  vector<int> heapTree;

  insert(heapTree, 3);
  insert(heapTree, 4);
  insert(heapTree, 9);
  insert(heapTree, 5);
  insert(heapTree, 2);

  cout << "Max-Heap array: ";
  printArray(heapTree);

  deleteNode(heapTree, 4);

  cout << "After deleting an element: ";

  printArray(heapTree);
}