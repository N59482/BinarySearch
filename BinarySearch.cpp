#include <iostream>
#include <ctime>
#define SIZE 10

using namespace std;

/*
* Алгоритм быстрой сортировки. QuickSort()
*/
void QuickSort(int* a, const int left,const int right)
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
* Функция sort_fill() принимает:
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

/*
* Алгоритм бинарного поиска. BinarySearch()
* Алгорим работает с упорядоченным массивом типа int и возвращает индекс искомого значения (индекс первого если начения дублируются)
* Если значение не найдено возвращается -1 - что не может быть индексом.
* Входными пораметрами являются:
* - массив a[] - в виде указателя на первый элемент,
* - количество элементов массива size в виде константного значения
* - искомое значение x  в виде константного значения
*
* Определение значения элемента в середине структуры данных. Полученное значение сравнивается с ключом.
* Если ключ меньше значения середины, то поиск осуществляется в первой половине элементов, иначе — во второй.
* Поиск сводится к тому, что вновь определяется значение серединного элемента в выбранной половине и сравнивается с ключом.
* Процесс продолжается до тех пор, пока не будет найден элемент со значением ключа или не станет пустым интервал для поиска.
*/

int BinarySearch(int * a, const int size, const int x)
	{
		int left = 0;
		int right = size-1;
		while(left < right)
			{ 
				int mid = (right+left)/2;
				// cout<<left<<" = left\n"<<right<<" = right\n"<<mid<<" = mid\n";
				if(a[mid] > x) right = mid - 1;
					else if (a[mid] < x) left = mid + 1;
							else return mid;
				// cout<<endl;
				
			};
		if(a[left] == x) return left;
		return -1;
	};

/*
* Функция show() для вывода массива в консоль.
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

/*
* Функция BinarySearch_tests() тестирует алгоритм бинарного поиска
* Функция принимает константные значения типа int: 
* размер массива arr_size и его максимальное возможноe значениe Max_val
* количество проводимых тестов pool_tests и bool модификтор info
* код 1 для модификатора info добавляет вывод комментариев в консоль в каждом тесте а код 0 отключает их.
* Функция проводит всего pool_tests тестов.
* Каждый тест включает инициализацию, заполнение и сортировку массива a[arr_size] сотоящего из элементов от 0 до Max_val включительно.
* Далее Бинарный поиск ищет в массиве рандомное число от 0 до Max_val включительно.
* После нахождения которого алгоритм проверяет его правильность сверяя искомое значения с индексом котоый возвращает бинарный поиск.
* Если же бинарный поиск не нашёл в массиве искомое число и вернул -1 то алгорим тесте ищет в массиве искомое число перебирая массив.
* Если при каких то обстоятелствах бинарный поиск не проходит тест то дальнейшее тестирование прекращается и BinarySearch_tests() возвращяет 0.
* Если все pool_tests пройдены успешно - возвращет 1
*/
bool BinarySearch_tests(const int arr_size = 10, const int Max_val = 9, const int pool_tests = 1, const bool info = 1)
	{
		for(int i = 0; i < pool_tests; i++)
			{
			    if(info) cout<<"\n================= "<<"TEST "<<i+1<<" ================="<<endl;
				int a[arr_size]; // создаём массив
				sort_fill(a,arr_size,Max_val); // заполняем и сортируем его
				if(info) show(a,arr_size);
				int x = rand() % Max_val; // формируем число которое будем искать в массиве
				if(info) cout<<"X = "<<x<<endl;
				int ix = BinarySearch(a,arr_size,x);// ищем его индекс проверяемым алгоритмом
				if(info) cout<<"iX = "<<ix<<endl;
				if (ix != -1)  
					{
						if(info) cout<<"BinarySearch find index of X = "<<ix<<endl;
						// если оно присутствует в массиве (по результату проверяемого алогорима)
						// проверяем правильно ли алгоримт нашёл индекс
						if(a[ix] != x) 
							{
								if(info) cout<<"But a["<<ix<<"] = "<<a[ix]<<endl<<a[ix]<<" != "<<x<<"\n TEST is fallen";
								return false; // если занчения не совпадают заканчиваем тестирование.
							};
					}
				else
					{
						if(info) cout<<"BinarySearch cant find "<<x<<" in array\n";
						// если оно НЕ присутствует в массиве (по результату проверяемого алогорима)
						// ищем его в массиве
						for(int it = 0; it < arr_size; it++)
							if(a[it] == x) 
								{
									if(info) cout<<"But TEST find "<<x<<" with index "<<it<<"\n TEST is fallen";
									return false; // если число всё таки есть в массиве - заканчиваем тестирование провалом.
								};
					};
				if(info) cout<<endl;
			};
		if(info) cout<<"All tests is good\n";
		return true;// если все тесты прошли успешно.
	};

int main()
	{
 	    srand(time(0));
		int a[SIZE];
		sort_fill(a,SIZE,10);
		show(a, SIZE); 
		int x = 0;
		cout<<"What are u looking for?\n";
		cin>>x;
		cout<<"index is "<<BinarySearch(a,SIZE,x);

        BinarySearch_tests();

        cout<<"Starting 200000 tests\n";
        getchar();
     	if(BinarySearch_tests(1000,999,2000,0)) cout<<"All tests is good\n";
    
    	return 0;
	}; 
