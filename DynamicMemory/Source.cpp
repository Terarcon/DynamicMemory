#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2
#define delimiter "\n------------------------\n"

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows, const int cols);
void FillRand(double** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T* arr, int& n, T value);
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>void push_col_back(T** arr, const int rows, int& cols);

template<typename T>T* push_front(T* arr, int& n, T value);
template<typename T>T** push_row_front(T** arr, int& rows, const int cols);
template<typename T>void push_col_front(T** arr, const int rows, int& cols);

template<typename T>T* insert(T* arr, int& n, T value, int index);
template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T>void insert_col(T** arr, const int rows, int& cols, const int index);

template<typename T>T* pop_back(T* arr, int& n);
template<typename T>T** pop_rows_back(T** arr, int& rows, const int cols);
template<typename T>void pop_cols_back(T** arr, const int rows, int& cols);

template<typename T>T* pop_front(T* arr, int& n);
template<typename T>T** pop_rows_front(T** arr, int& rows, const int cols);
template<typename T>void pop_cols_front(T** arr, const int rows, int& cols);

template<typename T>T* erase(T* arr, int& n, int index);
template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index);
template<typename T>void erase_col(T** arr, const int rows, int& cols, const int index);

void main()
{
	setlocale(LC_ALL, "");
	typedef double DataType;

#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);

	DataType value;
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

#ifdef DYNAMIC_MEMORY2
	int rows, cols;
	cout << "Введите колличество строк: "; cin >> rows;
	cout << "Введите колличество столбцов: "; cin >> cols;
	
	int** arr = Allocate<int>(rows, cols);

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
#endif // DYNAMIC_MEMORY2
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << endl;
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		arr[i] /= 100;
	}
	cout << endl;
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
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
void FillRand(double** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 10000;
			arr[i][j] /= 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T* push_back(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
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

template<typename T>T* push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
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

template<typename T>T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
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

template<typename T>T* pop_back(T* arr, int& n)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	n--;
	return arr;
}

template<typename T>T* pop_front(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;

	return buffer;
}

template<typename T>T* erase(T* arr, int& n, int indexE)
{
	T* buffer = new T[n - 1];
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


template<typename T>T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}

template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}


template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	return push_back(arr, rows, new T[cols] {});
}

template<typename T>T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	arr[0] = new T[cols] {};
	rows++;
	return arr;
}

template<typename T>void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T());
		cols--;
	}
	cols++;
}

template<typename T>void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template<typename T>T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	return insert(arr, rows, new T[cols]{}, index);
}

template<typename T>void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
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

template<typename T>T** pop_rows_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	rows--;
	return arr;
}

template<typename T>T** pop_rows_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;

	arr = buffer;
	rows--;
	return arr;
}

template<typename T>void pop_cols_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = pop_back(arr[i], cols);
		cols++;
	}
	cols--;
}

template<typename T>void pop_cols_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template<typename T>T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	if (index >= rows)
	{
		return arr;
	}
	T** buffer = new T* [rows - 1];
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

template<typename T>void erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
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