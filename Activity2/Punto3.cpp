#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void displayPrimeNumbers(vector<int>& numbers) {
    cout << "Prime numbers in the list: ";
    for (const auto& num : numbers) {
        if (isPrime(num)) {
            cout << num << " ";
        }
    }
    cout << endl;
}

void displayPrimeNumbersInRange(int start, int end) {
    cout << "Prime numbers in the range [" << start << ", " << end << "]: ";
    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    bool exit = 1;
    int choice;
    while(exit){
        cout << "Prime Number Checker Program" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Check if a single number is prime" << endl;
        cout << "2. Identify prime numbers within a list" << endl;
        cout << "3. Display prime numbers within a range" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    
        switch (choice) {
            case 1: {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                if (isPrime(num)) {
                    cout << num << " is a prime number." << endl;
                } else {
                    cout << num << " is not a prime number." << endl;
                }
                break;
            }
            case 2: {
                int count;
                cout << "Enter the number of elements in the list: ";
                cin >> count;
                vector<int> numbers(count);
                cout << "Enter the numbers: ";
                for (auto& num : numbers) {
                    cin >> num;
                }
                displayPrimeNumbers(numbers);
                break;
            }
            case 3: {
                int start, end;
                cout << "Enter the start of the range: ";
                cin >> start;
                cout << "Enter the end of the range: ";
                cin >> end;
                displayPrimeNumbersInRange(start, end);
                break;
            }
            case 4: {
                exit = 0;
            }
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
    

    return 0;
}
