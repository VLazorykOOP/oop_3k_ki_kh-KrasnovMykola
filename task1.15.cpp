#include <iostream>

using namespace std;

class Base
{
protected:
	int base;
public:
	Base() : base(0) {}
	Base(int base) : base(base) {}
};

class A1 : protected Base
{
protected:
	int a1;
public:
	A1() : a1(1) {}
	A1(int a1) : a1(a1) {}
	A1(int a1, int base) : Base(base), a1(a1) {}
};

class A2 : protected Base
{
protected:
	int a2;
public:
	A2() : a2(2) {}
	A2(int a2) : a2(a2) {}
	A2(int a2, int base) : Base(base), a2(a2) {}
};

class A3 : protected Base
{
protected:
	int a3;
public:
	A3() : a3(3) {}
	A3(int a3) : a3(a3) {}
	A3(int a3, int base) : Base(base), a3(a3) {}
};

class B1 : protected A1, protected A2
{
protected:
	int b1;
public:
	B1() : b1(4) {}
	B1(int b1) : b1(b1) {}
	B1(int b1, int a1, int base1, int a2, int base2) : A1(a1, base1), A2(a2, base2), b1(b1) {}
};

class B2 : protected A3
{
protected:
	int b2;
public:
	B2() : b2(5) {}
	B2(int b2) : b2(b2) {}
	B2(int b2, int a3, int base) : A3(a3, base), b2(b2) {}
};

class C1 : protected A3, protected B1, protected B2
{
protected:
	int c1;
public:
	C1() : c1(6) {}
	C1(int c1) : c1(c1) {}
	C1(int c1, int a3, int base1, int b1, int a1, int base2, int a2, int base3, int b2, int a31, int base4) : A3(a3, base1), B1(b1, a1, base2, a2, base3), B2(b2, a31, base4), c1(c1) {}
	// void showBase()
	// {
	// 	cout << "A3::Base::base = " << A3::Base::base << endl;
	// 	cout << "B1::A1::Base::base = " << B1::A1::Base::base << endl;
	// 	cout << "B1::A2::Base::base = " << B1::A2::Base::base << endl;
	// 	cout << "B2::A3::Base::base = " << B2::A3::Base::base << endl;
	// }
};

//
// virtual
//

class A1V : virtual protected Base
{
protected:
	int a1;
public:
	A1V() : a1(1) {}
	A1V(int a1) : a1(a1) {}
	A1V(int a1, int base) : Base(base), a1(a1) {}
};

class A2V : virtual protected Base
{
protected:
	int a2;
public:
	A2V() : a2(2) {}
	A2V(int a2) : a2(a2) {}
	A2V(int a2, int base) : Base(base), a2(a2) {}
};

class A3V : virtual protected Base
{
protected:
	int a3;
public:
	A3V() : a3(3) {}
	A3V(int a3) : a3(a3) {}
	A3V(int a3, int base) : Base(base), a3(a3) {}
};

class B1V : virtual protected A1V, virtual protected A2V
{
protected:
	int b1;
public:
	B1V() : b1(4) {}
	B1V(int b1) : b1(b1) {}
	B1V(int b1, int a1, int base1, int a2, int base2) : A1V(a1, base1), A2V(a2, base2), b1(b1) {}
};

class B2V : virtual protected A3V
{
protected:
	int b2;
public:
	B2V() : b2(5) {}
	B2V(int b2) : b2(b2) {}
	B2V(int b2, int a3, int base) : A3V(a3, base), b2(b2) {}
};

class C1V : virtual protected A3V, virtual protected B1V, virtual protected B2V
{
protected:
	int c1;
public:
	C1V() : c1(6) {}
	C1V(int c1) : c1(c1) {}
	C1V(int c1, int a3, int base1, int b1, int a1, int base2, int a2, int base3, int b2, int a31, int base4) : A3V(a3, base1), B1V(b1, a1, base2, a2, base3), B2V(b2, a31, base4), c1(c1) {}
	void showBase()
	{
		cout << "A3V::Base::base = " << A3V::Base::base << endl;
		cout << "B1V::A1V::Base::base = " << B1V::A1V::Base::base << endl;
		cout << "B1V::A2V::Base::base = " << B1V::A2V::Base::base << endl;
		cout << "B2V::A3V::Base::base = " << B2V::A3V::Base::base << endl;
	}
};

int main()
{
	C1 a, b(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	C1V av, bv(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
	cout << "Test!" << endl;
	cout << "Size for Base " << sizeof(Base) << endl;
	cout << "Size for A1 " << sizeof(A1) << endl;
	cout << "Size for A2 " << sizeof(A2) << endl;
	cout << "Size for A3 " << sizeof(A3) << endl;
	cout << "Size for B1 " << sizeof(B1) << endl;
	cout << "Size for B2 " << sizeof(B2) << endl;
	cout << "Size for C1 " << sizeof(C1) << endl;

	cout << "Size for Base " << sizeof(Base) << endl;
	cout << "Size for A1V " << sizeof(A1V) << endl;
	cout << "Size for A2V " << sizeof(A2V) << endl;
	cout << "Size for A3V " << sizeof(A3V) << endl;
	cout << "Size for B1V " << sizeof(B1V) << endl;
	cout << "Size for B2V " << sizeof(B2V) << endl;
	cout << "Size for C1V " << sizeof(C1V) << endl;

	std::cout << "Size for object class C1 " << sizeof(C1) << " or "
		<< sizeof(a) << " or " << sizeof(b) << std::endl;
	std::cout << "Size for object class C1V " << sizeof(C1V) << " or "
		<< sizeof(av) << " or " << sizeof(bv) << std::endl;

	// b.showBase();
	bv.showBase();
}
