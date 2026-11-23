#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <numeric>
using namespace std;


// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// ----------------------------CHATGPT CORRECTED CODE----------------------------------------------------------------
// Display a matrix
void displayMatrix(const string& name,
                   const vector<vector<int>>& mat) {
    cout << "\n" << name << " Matrix:\n";

    for (int i = 0; i < mat.size(); ++i) {
        cout << "P" << i << ": ";

        for (int val : mat[i])
            cout << setw(3) << val;

        cout << "\n";
    }
}

// Display a vector
void displayVector(const string& name,
                   const vector<int>& vec) {
    cout << "\n" << name << ": ";

    for (int val : vec)
        cout << setw(3) << val;

    cout << "\n";
}

// Banker's Algorithm - Safety Check
bool isSafe(int n, int m,
            const vector<vector<int>>& alloc,
            const vector<vector<int>>& maxNeed,
            const vector<int>& avail) {

    // Calculate Need Matrix
    vector<vector<int>> need(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            need[i][j] = maxNeed[i][j] - alloc[i][j];
        }
    }

    displayMatrix("Need", need);

    vector<bool> finish(n, false);
    vector<int> work = avail;
    vector<int> safeSeq;

    // Find processes that can finish
    for (int count = 0; count < n; ++count) {

        bool found = false;

        for (int i = 0; i < n; ++i) {

            if (finish[i])
                continue;

            bool canProceed = true;

            // Check Need[i] <= Work
            for (int j = 0; j < m; ++j) {
                if (need[i][j] > work[j]) {
                    canProceed = false;
                    break;
                }
            }

            if (canProceed) {

                // Release allocated resources
                for (int j = 0; j < m; ++j) {
                    work[j] += alloc[i][j];
                }

                finish[i] = true;
                safeSeq.push_back(i);
                found = true;
            }
        }

        // No unfinished process can proceed
        if (!found) {
            cout << "\nSystem is NOT in a safe state.\n";
            return false;
        }
    }

    cout << "\nSystem is in a SAFE state.\n";
    cout << "Safe Sequence: ";

    for (int p : safeSeq)
        cout << "P" << p << " ";

    cout << "\n";

    return true;
}


void runBankersAlgorithm() {

    srand(time(0));

    int n, m, mode;

    cout << "\n=== Banker's Algorithm - Safety Check ===\n";

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resource types: ";
    cin >> m;

    // Validate dimensions
    if (!cin || n <= 0 || m <= 0) {
        cout << "Invalid number of processes or resources.\n";
        return;
    }

    vector<vector<int>> alloc(n, vector<int>(m));
    vector<vector<int>> maxNeed(n, vector<int>(m));
    vector<int> avail(m);

    cout << "\nChoose input mode:\n";
    cout << "1. Manual Input\n";
    cout << "2. Random Values\n";
    cout << "Enter choice: ";

    cin >> mode;

    if (!cin || (mode != 1 && mode != 2)) {
        cout << "Invalid input mode.\n";
        return;
    }

    // ---------------- MANUAL INPUT ----------------
    if (mode == 1) {

        cout << "\nEnter Allocation Matrix:\n";

        for (int i = 0; i < n; ++i) {
            cout << "P" << i << ": ";

            for (int j = 0; j < m; ++j) {
                cin >> alloc[i][j];

                if (!cin || alloc[i][j] < 0) {
                    cout << "Invalid allocation value.\n";
                    return;
                }
            }
        }

        cout << "\nEnter Max Matrix:\n";

        for (int i = 0; i < n; ++i) {
            cout << "P" << i << ": ";

            for (int j = 0; j < m; ++j) {
                cin >> maxNeed[i][j];

                if (!cin || maxNeed[i][j] < 0 ||
                    maxNeed[i][j] < alloc[i][j]) {

                    cout << "Invalid Max value for P"
                         << i << ", resource " << j << ".\n";

                    return;
                }
            }
        }

        cout << "\nEnter Available Resources: ";

        for (int j = 0; j < m; ++j) {
            cin >> avail[j];

            if (!cin || avail[j] < 0) {
                cout << "Invalid available resource value.\n";
                return;
            }
        }

        // Validate maximum claims against total resources
        for (int j = 0; j < m; ++j) {

            long long total = avail[j];

            for (int i = 0; i < n; ++i)
                total += alloc[i][j];

            for (int i = 0; i < n; ++i) {
                if (maxNeed[i][j] > total) {
                    cout << "\nInvalid input: Maximum claim of P"
                         << i << " exceeds total instances of resource "
                         << j << ".\n";
                    return;
                }
            }
        }
    }

    // ---------------- RANDOM INPUT ----------------
    else {

        vector<int> totalResources(m);

        // Generate total resources first
        for (int j = 0; j < m; ++j) {
            totalResources[j] = n * 4 + 5;
        }

        // Distribute allocated resources without
        // exceeding the total resource count
        for (int j = 0; j < m; ++j) {

            int remaining = totalResources[j];

            for (int i = 0; i < n; ++i) {

                int upper = min(4, remaining);

                alloc[i][j] = rand() % (upper + 1);

                remaining -= alloc[i][j];
            }

            avail[j] = remaining;
        }

        // Generate valid maximum requirements
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                int remaining =
                    totalResources[j] - alloc[i][j];

                maxNeed[i][j] =
                    alloc[i][j] + rand() % (remaining + 1);
            }
        }

        cout << "\nRandomly Generated Data:\n";
    }

    // Display input matrices
    displayMatrix("Allocation", alloc);
    displayMatrix("Max", maxNeed);
    displayVector("Available", avail);

    // Perform safety check and capture result
    bool safe = isSafe(n, m, alloc, maxNeed, avail);

    if (safe) {
        cout << "\nBanker's Algorithm: Execution can proceed safely.\n";
    }
    else {
        cout << "\nBanker's Algorithm: Safe execution cannot be guaranteed.\n";
    }
}

// int main() {
//     runBankersAlgorithm();
//     return 0;
// }
