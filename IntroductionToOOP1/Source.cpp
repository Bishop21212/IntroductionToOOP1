#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

class Point
{
	double x;
	double y;
public:
	//get-������ ����� ���� ������������
	//����������� ���������� �����, ������� �� �������� ������, 
	//��� �������� ����������.
	//��� ������������ ������� ����� ���� ������� ������ ����������� ������
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//					Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	//Point(double x)
	//{
	//	this->x = x;
	//	this->y = double();	//double() - �������� �� ��������� ��� ���� double
	//	//double() - ����� �������� ����������� �� ��������� ��� double
	//	cout << "1argConstrcutor:" << this << endl;
	//}
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator++()	//Prefix increment
	{
		this->x++;
		this->y++;
		return *this;	//���������� ���������� ��������
	}
	Point operator++(int)//Postfix increment
	{
		Point old = *this;	//��������� ������ �������� �������
		x++;
		y++;
		return old;	//������ (�� ����������) �������� �������
	}

	//				Methods:
	double distance(const Point& other)const //���������� ����� - �� �������� ������, ��� �������� ���������� �����
	{
		//other - ������ (������ �����)
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		//sqrt - Square Root (���������� ������)
		//this->x *= 100;//� ����������� ������ ������ ������� ������
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}

Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

//Point G;	//Global object (���������� ������)
int g;		//Global variable (���������� ����������)	DEPRECATED(����������)

//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT
	//type name;
	int a;	//���������� ���������� 'a' ���� 'int'
	Point A;//���������� ���������� 'A' ���� 'Point'
			//���������� ������� 'A' ��������� 'Point'
			//�������� ���������� 'A' ��������� 'Point'
	//instance - ���������
	//instantiate - ������� ���������
	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A;	//��������� ��������� �� Point 'pA', 
					//� �������������� ��� ������� ������� 'A'
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;
#endif // STRUCT_POINT

#ifdef CONSTRUCTORS_CHECK
	Point A;//Default constructor
/*A.set_x(2);
A.set_y(3);*/
//cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B(4, 5);
	B.print();

	Point C = 5;	//Single-argumen constructor
	C.print();
	//cout << C.get_x() << endl;

	Point D(8);	//Single-argument constructor
	D.print();

	Point E = D;	//CopyConstructor
	E.print();
	Point F(B);		//CopyConstructor
	F.print();
	/*cout << "\n------------------------------\n";
	cout << Point(123, 234).distance(Point(345, 456)) << endl;
	cout << "\n------------------------------\n";*/

	Point G;//Default constructor
	G = F;	//CopyAssignment (operator=)
	G.print();
#endif 

#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(3, 4);
	cout << "\n----------------------------------------------\n";
	cout << "���������� �� ����� A �� ����� B:" << A.distance(B) << endl;
	cout << "\n----------------------------------------------\n";
	cout << "���������� �� ����� B �� ����� A:" << B.distance(A) << endl;
	cout << "\n----------------------------------------------\n";

	cout << "���������� ����� ������� A � B:  " << distance(A, B) << endl;
	cout << "\n----------------------------------------------\n";
	cout << "���������� ����� ������� B � A:  " << distance(B, A) << endl;
	cout << "\n----------------------------------------------\n";
#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << tab << b << tab << c << endl;

	Point A, B, C;
	cout << "\n----------------------------------------------\n";
	A = B = C = Point(2, 3);
	//Point(2,3); - ���� �������� �����������, ������� ������� ��������� ���������� ������
	cout << "\n----------------------------------------------\n";
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(4, 5);
	//Point C = A + B;
	//C.print();
	//C++;
	//C.print();
	B = ++A;
	A.print();
	B.print();
	A += B;
}