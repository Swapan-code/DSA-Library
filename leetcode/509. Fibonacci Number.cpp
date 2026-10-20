// Notes: https://app.notion.com/p/509-Fibonacci-Number-3fadbda921558062b5c0c6f219c203ec?source=copy_link

// Matrix Exponentiation Approach
// Time = O(log N) , Space = O(1)
class Solution {
private:
    vector<vector<long long>> matrixMultiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        vector<vector<long long>> C(2, vector<long long>(2));
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        return C;
    }

    // Matrix Exponentiation O(log N)
    vector<vector<long long>> matrixPower(vector<vector<long long>>& A, int n) {
        vector<vector<long long>> res = {{1, 0}, {0, 1}}; // Identity Matrix
        while (n > 0) {
            if (n & 1) {
                res = matrixMultiply(res, A);
            }
            A = matrixMultiply(A, A);
            n >>= 1;
        }
        return res;
    }

public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<vector<long long>> A = {{1, 1}, {1, 0}};
        A = matrixPower(A, n - 1);
        return A[0][0];
    }
};
