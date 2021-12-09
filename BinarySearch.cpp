#include <iostream>
#define SIZE 10

using namespace std;

/*
* Алгоритм быстрой сортировки.
*/
void QuickSort(int* a, int left, int right)
    {
        int il = left;
        int ir = right;
        int mid = a[(left + right) / 2];
        while(il <= ir)
            {
                while(a[il] < mid) il++;
                while(a[ir] > mid) ir--;
                if(il <= ir)
                    {
                        if (a[il]>a[ir]) swap(a[il], a[ir]);
                        il++;
                        ir--;
                    };
            };
        if (il < right) QuickSort(a,il,right);
        if (left < ir) QuickSort(a,left,ir);
    };

/*
* Функция sort_fill принимает:
* массив в виде укателя типа int,
* размерность этого массива в виде константного знчения.
* максимальное значения для элемента массива Max_val в виде константного значения.
* Далее заполняет полученный массив случайными числами в диапазоне от 0 до Max_val и сортирует массив быстрой сортировкой описанной выше.
*/
void sort_fill(int *a, const int size, const int Max_val)
	{
		for(int i = 0; i < size; i++)
			{
				a[i] = rand() % Max_val;
			};
		QuickSort(a,0,size-1);
	};

int BinarySearch(int * a, int size, int x)
	{
		int left = 0;
		int right = size-1;
		while(left != right)
			{ 
				int mid = (right+left)/2;
				if(a[mid] > x) right = mid;
					else if (a[mid] < x) left = mid;
							else return mid;
			};			
		return -404;
	};

/*
* Функция для вывода массива в консоль.
* Принимает указатель на первый элемент массива типа int 
* Функция использует логику указателей для быстроты, хотя возможно в данном случае это не так актуально.
*/
void show(int *a, const int size)
	{
		int * end = a + size;
		for(a; a < end; a++)
			cout<<*a<<" ";
		cout<<endl;
	}; 

int main()
	{
		int a[10];
		int index[] = {0,1,2,3,4,5,6,7,8,9};
        
		sort_fill(a,SIZE,10);
        
        show(index, SIZE);
		show(a, SIZE);

		int x = 0;
		cout<<"What are u looking for?\n";
		cin>>x;
		cout<<"index is "<<BinarySearch(a,10,x);
		return 0;
	}; 
