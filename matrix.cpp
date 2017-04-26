#include <iostream>
#include <iomanip>
using namespace std;

typedef int ElemType;
class Matrix
{
        ElemType **p;
        int row, col;
public:
        Matrix(int x, int y);
        void get_element(int i, int j, ElemType value)
        {
                p[i][j] = value;
        }
        ElemType &put_element(int i, int j)
        {
                return p[i][j];
        }
        void matrixCreate(void);
	void showMatrix(void);
};

Matrix::Matrix(int x, int y)
{
        row = x;
        col = y;
        p = new ElemType*[row]; //create pointer array
        for(int i = 0; i < row; i++)
        {
                p[i] = new ElemType[col]; //allocate memory for every row
        }
}

void Matrix::matrixCreate(void)
{
        cout<<"Enter matrix elements row by row \n";
        ElemType value;
	
        for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++)
		{
			cin>>value;
			p[i][j] = value;
		}
}
		
void Matrix::showMatrix(void)
{
	cout<<"Print the matrix: \n";
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			cout<<setw(10)<<p[i][j]<<' ';
		}
		cout<<'\n';
	}
	cout<<'\n';
}

int main()
{
	int m, n;
	cout<<"Enter size of matrix mxn:";
	cin>>m>>n;

	Matrix A(m, n);
	//create a matrix
	A.matrixCreate();
	//print a matrix
	A.showMatrix();
	//show a element of a matrix
	cout<<A.put_element(1,2);
	cout<<endl;
	return 0;
}
