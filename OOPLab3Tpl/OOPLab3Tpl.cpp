#include <iostream>
using namespace std;

class Parallelogram
{
	double base;
	double height;
	double side;
	unsigned int color;
public:
	Parallelogram() : base(5.0), height(3.0), side(6.0), color(0) {};

	Parallelogram(double Height) : base(5.0), side(6.0), color(0) {
		this->height = Height;
	};

	Parallelogram(double Base, double Height, double Side, int Color) {
		this->base = Base;
		this->height = Height;
		this->side = Side;
		if (Color >= 0) color = Color; else color = 0;
	}


	//base
	double getBase() const {
		return base;
	}
	void setBase(double base) {
		if (base < 0 || base > 1.e+100)
		{
			cout << " Error base! \n";
			return;
		}
		this->base = base;
	}

	//height
	double getHeight() const {
		return height;
	}
	void setHeight(double height) {
		if (height < 0 || height > 1.e+100)
		{
			cout << " Error height! \n";
			return;
		}
		this->height = height;
	}

	// side
	double getSide() const {
		return side;
	}
	void setSide(double side) {
		if (side < 0 || side > 1.e+100)
		{
			cout << "Error side! \n";
			return;
		}
		this->side = side;
	}

	//color
	double getColor() const {
		return color;
	}
	void setColor(int color) {
		if (color < 0 || color > 10000)
		{
			cout << " Error color! \n";
			return;
		}
		this->color = color;
		this->color = color;
	}
	// functions
	double S() {
		return base * height;
	}
	double P() {
		return 2 * base + 2 * side;
	}
	void printInfo()
	{
		cout << "\n Base = " << base << " Side = " << side << " Height = " << height << " Color = " << color << endl;
		cout << " S= " << S() << " P = " << P() << endl;
	}
};


int main()
{
	Parallelogram parallelogram1;
	cout << "Parallelogram 1:" << endl;
	parallelogram1.printInfo();
	Parallelogram parallelogram2(4.0);
	cout << "\nParallelogram 2:" << endl;
	parallelogram2.printInfo();
	Parallelogram parallelogram3(3.0, 5.0, 6.0, 500);
	cout << "\nParallelogram 3:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setBase(7.0);
	cout << "\nParallelogram 3 after setting base to 7.0:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setHeight(4.0);
	cout << "\nParallelogram 3 after setting height to 4.0:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setSide(8.0);
	cout << "\nParallelogram 3 after setting side to 8.0:" << endl;
	parallelogram3.printInfo();
	parallelogram3.setColor(700);
	cout << "\nParallelogram 3 after setting color to 700:" << endl;
	parallelogram3.printInfo();
	return 0;
}

#include <iostream>
class MyVector
{
    short* a;
    int size;
    int value;
    static int Count;
    int errorCode;
public:
    MyVector() : size(1), errorCode(0) {
        a = new short[size];
        a[0] = 0;
        if (a == nullptr)
            errorCode = 1;
        Count++;
    }
    MyVector(int Size) : size(Size), errorCode(0), value(0) {
        a = new short[Size];
        if (a == nullptr)
            errorCode = 1;
        else {
            for (int i = 0; i < Size; i++)
            {
                a[i] = value;
            }
        }
        Count++;
    }
    MyVector(int size, int value1) :size(size), value(value1), errorCode(0) {
        a = new short[size];
        if (a == nullptr)
            errorCode = 1;
        else {
            for (int i = 0; i < size; i++)
            {
                a[i] = value1;
            }
        }
        Count++;
    }
    MyVector(MyVector& X) {
        size = X.size;
        a = new short[size];
        if (a == nullptr)
            errorCode = 1;
        else {
            for (int i = 0; i < size; i++)
            {
                a[i] = X.a[i];
            }
        }
        Count++;
    };

    ~MyVector() {
        delete[] a;
        Count--;
    }

    void ChangeElement(int i, short c) {
        if (i >= 0 && i < size) {
            a[i] = c;
            errorCode = 0;
        }
        else {
            errorCode = 2;
        }
    }
    void OutputElement(int i) {
        std::cout << a[i] << std::endl;
    }
    void Add(short c) {
        for (int i = 0; i < size; i++)
        {
            a[i] += c;
        }
    }
    void Subtraction(short c) {
        for (int i = 0; i < size; i++)
        {
            a[i] -= c;
        }
    }
    void Multiple(unsigned char value) {
        for (int i = 0; i < size; i++)
        {
            a[i] *= value;
        }
    }
    void Comparison(int value, int j) {
        int choose;
        std::cout << "1 - >\n2 - =\n3 - !=\n";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            if (a[j] > value)
            {
                std::cout << true;
            }
            else {
                std::cout << false;
            }
            break;
        case 2:
            if (a[j] == value)
            {
                std::cout << true;
            }
            else {
                std::cout << false;
            }
            break;
        case 3:
            if (a[j] != value)
            {
                std::cout << true;
            }
            else {
                std::cout << false;
            }
            break;
        default:
            break;
        }
    }
    void printInfo() {
        std::cout << std::endl;
        for (int i = 0; i < size; i++) {
            std::cout << a[i] << " ";
        }
        std::cout << std::endl;
    }
    int getErrorCode() {
        return errorCode;
    }
    short& operator[](int index) {
        return a[index];
    }
    static int getObjectCount() {
        return Count;
    }
};

int MyVector::Count = 0;


int main()
{
    MyVector A;
    A.printInfo();
    MyVector B(9);
    B.printInfo();
    MyVector C(10, 7);
    C.printInfo();
    MyVector D = B;
    D.printInfo();
    B.ChangeElement(3, 15);
    B.printInfo();
    B.OutputElement(3);
    C.Add(5);
    C.printInfo();
    C.Subtraction(3);
    C.printInfo();
    D.Multiple(2);
    D.printInfo();
    A.Comparison(10, 2);
    std::cout << D.getErrorCode();
    std::cout << MyVector::getObjectCount();
    return 0;
}
