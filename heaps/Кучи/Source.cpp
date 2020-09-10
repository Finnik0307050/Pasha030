
#include <iostream>
#include <ctime>
using namespace std;


#pragma once
struct AAA
{
	int x;
	void print();
	int getPriority() const;
};
namespace heap
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Heap
	{
		int size;
		int maxSize;
		void** storage; // данные
		CMP(*compare)(void*, void*);
		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			size = 0;
			storage = new void* [maxSize = maxsize];
			compare = f;
		};
		int left(int ix);
		int right(int ix);
		int parent(int ix);
		bool isFull() const
		{
			return (size >= maxSize);
		};
		bool isEmpty() const
		{
			return (size <= 0);
		};
		bool isLess(void* x1, void* x2) const
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2) const
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2) const
		{
			return compare(x1, x2) == EQUAL;
		};
		void swap(int i, int j);
		void heapify(int ix);
		void insert(void* x);
		void* extractMax();
		void scan(int i) const;
		void* extractMin();
		int unionHeap(int i);
		void* extractI();
	};
	Heap create(int maxsize, CMP(*f)(void*, void*));
};


heap::CMP cmpAAA(void* a1, void* a2) //Функция сравнения
{
#define A1 ((AAA*)a1)
#define A2 ((AAA*)a2)
	heap::CMP
		rc = heap::EQUAL;
	if (A1->x > A2->x)
		rc = heap::GREAT;
	else
		if (A2->x > A1->x)
			rc = heap::LESS;
	return rc;
#undef A2
#undef A1
}


//левый 2*i+1
//правый 2*i+2
//-----------------------------—
int main()
{
	setlocale(LC_ALL, "rus");
	int k, choice, num, size;
	bool task = true;
	heap::Heap h1 = heap::create(30, cmpAAA);
	heap::Heap h2 = heap::create(30, cmpAAA);
	heap::Heap h3 = heap::create(30, cmpAAA);
	for (;;)
	{
		cout << "1 - вывод 1 кучи на экран" << endl;
		cout << "2 - вывод 2 кучи на экран" << endl;
		cout << "3 - добавить элемент в 1 кучу" << endl;
		cout << "4 - добавить элемент во 2 кучу" << endl;
		cout << "5 - добавить рандомный элемент в 1 кучу" << endl;
		cout << "6 - добавить рандомный элемент в 2 кучу" << endl;
		cout << "7 - удалить максимальный элемент в 1 куче" << endl;
		cout << "8 - удалить максимальный элемент во 2 куче" << endl;
		cout << "9 - удалить минимальный элемент в 1 куче" << endl;
		cout << "10 - удалить минимальный элемент во 2 куче" << endl;
		cout << "11 - удалить i элемент в 1 куче" << endl;
		cout << "12 - удалить i элемент во 2 куче" << endl;
		cout << "13 - объеденить 2 кучи" << endl;
		cout << "14 - вывод 3 кучи на экран" << endl;
		cout << "0 - выход" << endl;
		cout << "сделайте выбор" << endl; cin >> choice;
		switch (choice)
		{
		case 0: exit(0);
		case 1: h1.scan(0);
			system("pause");
			system("cls");
			break;
		case 2: h2.scan(0);
			system("pause");
			system("cls");
			break;
		case 3: { AAA* a = new AAA;
			cout << "введите ключ" << endl; cin >> k;
			a->x = k;
			h1.insert(a);
		}
				system("cls");
				break;
		case 4: { AAA* a = new AAA;
			cout << "введите ключ" << endl; cin >> k;
			a->x = k;
			h2.insert(a);
		}
				system("cls");
				break;
		case 5: {
			cout << "сколько элементов добавить: " << endl;
			cin >> num;
			srand(time(NULL));
			for (int i = 0; i < num; i++)
			{
				AAA* a = new AAA;
				k = rand() % +100;
				a->x = k;
				h1.insert(a);
			}
		}
				system("cls");
				break;
		case 6: {
			cout << "сколько элементов добавить: " << endl;
			cin >> num;
			srand(time(NULL));
			for (int i = 0; i < num; i++)
			{
				AAA* a = new AAA;
				k = rand() % +100;
				a->x = k;
				h2.insert(a);
			}
		}
				system("cls");
				break;
		case 7: h1.extractMax();
			system("cls");
			break;
		case 8: h2.extractMax();
			system("cls");
			break;
		case 9: h1.extractMin();
			system("cls");
			break;
		case 10: h2.extractMin();
			system("cls");
			break;
		case 11: h1.extractI();
			system("cls");
			break;
		case 12: h2.extractI();
			system("cls");
			break;
		case 13:
		{
			size = h1.size;
			if (size > 0)
			{
				for (int i = 0; i < size; i++)
				{
					AAA* a = new AAA;
					k = h1.unionHeap(i);
					a->x = k;
					h3.insert(a);
				}
			}
			else
				cout << "1 куча пуста" << endl;
			size = h2.size;
			if (size > 0)
			{
				for (int i = 0; i < size; i++)
				{
					AAA* a = new AAA;
					k = h2.unionHeap(i);
					a->x = k;
					h3.insert(a);
				}
			}
			else
				cout << "2 куча пуста" << endl;
		}
		system("cls");
		break;
		case 14:
			h3.scan(0);
			system("pause");
			system("cls");
			break;
		default: cout << endl << "Введена неверная команда!" << endl;
		}
	} return 0;
}


#include <iostream>
#include <iomanip>
using namespace std;
void AAA::print()
{
	std::cout << x;
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
	void Heap::scan(int i) const //Вывод значений элементов на экран
	{
		int probel = 20;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
	}
	void* Heap::extractMin()
	{
		int num, n = 0;
		void* rc = nullptr;
		if (!isEmpty())
		{
			num = ((AAA*)storage[0])->getPriority();
			for (int i = 0; i < size; i++)
			{
				//cout << ((AAA*)storage[i])->getPriority() << endl;
				if (num > ((AAA*)storage[i])->getPriority())
				{
					num = ((AAA*)storage[i])->getPriority();
					n = i;
				}
			}
			cout << "Минимальный элемент: " << num << endl;
			rc = storage[n];
			storage[n] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}

	int Heap::unionHeap(int i)
	{
		return ((AAA*)storage[i])->getPriority();
	}

	void* Heap::extractI()
	{
		int num, n = 0;
		void* rc = nullptr;
		if (!isEmpty())
		{
			do {
				cout << "Какой элемент хотите удалить: " << endl;
				cin >> num;
				if (num > size)
					cout << "Вы ввели слишком большое число" << endl;
			} while (num > size);
			rc = storage[num];
			storage[num] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
}

