#include <iostream>
#include <vector>

using namespace std;

vector<int> readInputArray(int n) {
    vector<int> input(n);
    cout << "Enter " << n << " binary values (0 or 1): ";
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
        if (input[i] != 0 && input[i] != 1) {
            cout << "Invalid binary value. Please enter only 0 or 1.\n";
            --i;
        }
    }
    return input;
}

vector<int> applyPermutation(const vector<int>& input, const vector<int>& permTable) {
    vector<int> result(permTable.size());
    for (size_t i = 0; i < permTable.size(); ++i) {
        int idx = permTable[i] - 1;
        if (idx < 0 || idx >= input.size()) {
            cerr << "Invalid permutation index: " << permTable[i] << endl;
            exit(1);
        }
        result[i] = input[idx];
    }
    return result;
}

void printVector(const vector<int>& vec) {
    for (int val : vec) cout << val;
    cout << endl;
}

int sBoxLookup(const vector<int>& sbox, int index) {
    return (index >= 0 && index < sbox.size()) ? sbox[index] : -1;
}

vector<int> swapHalves(const vector<int>& vec) {
    int half = vec.size() / 2;
    vector<int> swapped(vec.begin() + half, vec.end());
    swapped.insert(swapped.end(), vec.begin(), vec.begin() + half);
    return swapped;
}

int main() {
    int n, psize, sboxSize, inputA, inputB;

    cout << "Enter size of the input array: ";
    cin >> n;
    vector<int> input = readInputArray(n);

    cout << "Enter size of the permutation table: ";
    cin >> psize;
    vector<int> permTable(psize);
    cout << "Enter " << psize << " values for permutation table (1-based index): ";
    for (int& val : permTable) cin >> val;

    vector<int> permuted = applyPermutation(input, permTable);
    cout << "Output after permutation: ";
    printVector(permuted);

    cout << "Enter size of the S-box: ";
    cin >> sboxSize;
    vector<int> sbox(sboxSize);
    cout << "Enter " << sboxSize << " values for S-box: ";
    for (int& val : sbox) cin >> val;

    cout << "Enter input A: ";
    cin >> inputA;
    cout << "Output from S-box for A: " << sBoxLookup(sbox, inputA) << endl;

    cout << "Enter input B: ";
    cin >> inputB;
    cout << "Output from S-box for B: " << sBoxLookup(sbox, inputB) << endl;

    cout << "Output after swapping halves: ";
    vector<int> swapped = swapHalves(permuted);
    printVector(swapped);

    return 0;
}
