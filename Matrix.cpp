#define mod (int)(1e9 + 7)

template <typename T>
class Matrix {

public:

    vector < vector <T> > A;
    int r,c;

    //Default Constructor
    Matrix()
    {
        this->r = 0;
        this->c = 0;
    }

    //Matrix with given dimensions and random values
    Matrix(int r,int c)
    {
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }

    //Matrix with given value and dimensions
    Matrix(int r,int c,const T &val)
    {

        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }

    //Identity matrix with given dimension
    Matrix(int n)
    {
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
            A[i][i] = (T)1;
    }

    //Print the matrix
    void display()
    {
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
                cout << A[i][j] << " ";

            cout << endl;
        }
    }

    //Input called to get input
    //Put custom code
    void input()
    {
        // for(int i=0;i<r;i++)
        //     for(int j=0;j<c;j++)
        //         define inout here
    }

    Matrix operator * (const Matrix<T> &B)
    {

        assert(c == B.r);
        int i,j,k;
        int x = r;
        int y = c;
        int z = B.c;

        Matrix <T> C(x,z,0);

        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                {
                    C[i][j] = (C[i][j] + ( (long long )A[i][k] * (long long)B[k][j] ) );
                    #ifdef mod
                    C[i][j] %= mod;
                    #endif
                }

        return C;
    }

    //Overloaded + operator to add 2 matrices
    //with same dimensions
    Matrix operator + (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] + B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                #endif
            }

        return C;
    }


    //Overload unary - to get negative of a matrix
    Matrix operator - ()
    {
        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = -A[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }

    //Overload binary - to subtract a matrix
    //from other with same dimensions
    Matrix operator - (const Matrix<T> &B)
    {
        assert(r == B.r);
        assert(c == B.c);

        Matrix <T> C(r,c,0);
        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
            {
                C[i][j] = A[i][j] - B[i][j];
                #ifdef mod
                C[i][j] %= mod;
                if(C[i][j] < 0)
                    C[i][j] += mod;
                #endif
            }

        return C;
    }

    //Using binary matrix exponentiation
    Matrix operator ^ (long long n)
    {
        assert(r == c);

        int i,j;
        Matrix <T> C(r);

        Matrix <T> X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];

        while(n)
        {
            if(n&1)
                C = (C*X);

            X = (X*X);
            n /= 2;
        }
        return C;
    }

    //transpose operation
    Matrix transpose()
    {
        Matrix <T> C(c,r);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        return C;
    }

    //transpose inplace
    void transposeInplace()
    {
        Matrix <T> C(c,r);

        int i,j;
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                C[j][i] = A[i][j];

        this->r = C.r;
        this->c = C.c;
        this->A = C.A;
    }

    vector<T>& operator [] (int i)
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    const vector<T>& operator [] (int i) const
    {
        assert(i < r);
        assert(i >= 0);
        return A[i];
    }

    //help quicken the debugging process
    friend ostream& operator << (ostream &out,const Matrix<T> &M)
    {
        for (int i = 0; i < M.r; ++i) {
            for (int j = 0; j < M.c; ++j) {
                out << M[i][j] << " ";
            }
            out << '\n';
        }
        return out;
    }

};
