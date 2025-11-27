#include <iostream>
using namespace std;

// Recursive function based on Schaum’s Outline algorithm
void move(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << from << " to " << to << endl;
    }
    else
    {
        move(n - 1, from, aux, to);  // Move top n-1 disks to auxiliary peg
        cout << "Move disk " << n << " from " << from << " to " << to << endl;
        move(n - 1, aux, to, from);  // Move n-1 disks from auxiliary to destination
    }
}

int main()
{
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    cout << "\nSequence of moves:\n";
    move(n, 'A', 'C', 'B');  // A = source, B = auxiliary, C = destination

    return 0;
}

