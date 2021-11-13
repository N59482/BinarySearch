#include <iostream>

using namespace std;

void myqs(int* a, int left, int right)
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
        if (il < right) myqs(a,il,right);
        if (left < ir) myqs(a,left,ir);
    };

void sort_fill(int *a, const int size)
	{
		for(int i = 0; i < size+1; i++)
			{
				a[i] = rand() % 11;
			};
		myqs(a,0,size);
	};

int BS(int * a, int size, int x)
	{
		int left = 0;
		int right = size-1;
		while(left != right)
			{ 
				int mid = (right+left)/2;
				cout<<"test4\n";
				if(a[mid] > x) {right = mid;cout<<"test5\n";}
					else if (a[mid] < x) {left = mid;cout<<"test6\n";}
							else {return mid;cout<<"test7\n";};
							cout<<"test8\n";
			};			
		return -404;
	};

int main()
	{
		int a[10];
		sort_fill(a,10);
		for(auto & i : a)
			cout<<i<<" ";
		cout<<endl;
		int x = 0;
		cout<<"What are u looking for?\n";
		cin>>x;
		cout<<"There is "<<BS(a,10,x);
		return 0;
	}; 