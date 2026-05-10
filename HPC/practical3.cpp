//HPC PRACTICAL-03

#include <iostream>
#include <omp.h>
#include <climits>

using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum = 0;
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    // Parallel Reduction
    #pragma omp parallel for reduction(+:sum) reduction(min:minimum) reduction(max:maximum)
    for(int i = 0; i < n; i++) {

        sum += arr[i];

        if(arr[i] < minimum)
            minimum = arr[i];

        if(arr[i] > maximum)
            maximum = arr[i];
    }

    double average = (double)sum / n;

    cout << "\nResults using Parallel Reduction:\n";

    cout << "Sum = " << sum << endl;
    cout << "Minimum = " << minimum << endl;
    cout << "Maximum = " << maximum << endl;
    cout << "Average = " << average << endl;

    return 0;
}

/*
To execute :

g++ practical1.cpp -fopenmp
./a.out

*/

