#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
//#define DYNAMIC_MEMORY1
#define delimiter "\n------------------------\n"

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);

int* push_front(int* arr, int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);

int* insert(int* arr, int& n, int value, int index);
int** insert_row(int** arr, int& rows, const int cols, const int index);
void insert_col(int** arr, const int rows, int& cols, const int index);

int* pop_back(int* arr, int& n);
int** pop_rows_back(int** arr, int& rows, const int cols);
void pop_cols_back(int** arr, const int rows, int& cols);

int* pop_front(int* arr, int& n);
int** pop_rows_front(int** arr, int& rows, const int cols);
void pop_cols_front(int** arr, const int rows, int& cols);

int* erase(int* arr, int& n, int index);
int** erase_row(int** arr, int& rows, const int cols, const int index);
void erase_col(int** arr, const int rows, int& cols, const int index);

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	int indexE;
	cout << "Введите индекс удаляемого элемента: "; cin >> indexE;
	arr = erase(arr, n, indexE);
	Print(arr, n);

	delete[] arr;
#endif //DYNAMIC_MEMORY1

	int rows, cols;
	cout << "Введите колличество строк: "; cin >> rows;
	cout << "Введите колличество столбцов: "; cin >> cols;
	
	int** arr = Allocate(rows, cols);

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Добавление пустой строки в конце" << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Добавление пустой строки в начале" << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Добавление пустого столбца в конце" << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Добавление пустого столбца в начале" << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Удаление последней строки" << endl;
	arr = pop_rows_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Удаление первой строки" << endl;
	arr = pop_rows_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Удаление последнего столбца" << endl;
	pop_cols_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter;
	cout << "Удаление первого столбца" << endl;
	pop_cols_front(arr, rows, cols);
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс добавляемой строки : "; cin >> index;
	cout << delimiter << endl;
	cout << "Добавление пустой строки по индексу" << endl;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс добавляемого столбца: "; cin >> index;
	cout << delimiter << endl;
	cout << "Добавление пустого столбца по индексу" << endl;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: "; cin >> index;
	cout << delimiter << endl;
	cout << "Удаление строки по индексу" << endl;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Введите индекс удаляемого столбца: "; cin >> index;
	cout << delimiter << endl;
	cout << "Удаление столбца по индексу" << endl;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows);
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << endl;
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* push_back(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	buffer = nullptr;
	cout << typeid(nullptr).name() << endl;

	arr[n] = value;
	n++;

	return arr;
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;

	return arr;
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	arr[index] = value;
	n++;

	return arr;
}

int* pop_back(int* arr, int& n)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;

	return arr;
}

int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;

	return buffer;
}

int* erase(int* arr, int& n, int indexE)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = indexE; i < n; i++)
	{
		buffer[i - 1] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;

	return arr;
}


int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}


int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	arr[rows] = new int[cols] {};
	rows++;
	return arr;
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	arr[0] = new int[cols] {};
	rows++;
	return arr;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	arr[index] = new int[cols] {};
	rows++;
	return arr;
}

void insert_col(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

int** pop_rows_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	rows--;
	return arr;
}

int** pop_rows_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	rows--;
	return arr;
}

void pop_cols_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

void pop_cols_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	if (index >= rows)
	{
		return arr;
	}
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < rows - 1; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;

	arr = buffer;
	rows--;
	return arr;
}

void erase_col(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < index; j++) 
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];

		arr[i] = buffer;
	}
	cols--;
}