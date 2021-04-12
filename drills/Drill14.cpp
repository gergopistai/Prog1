#include "Drill.h"

struct Drill14 : Drill
{
	class B1
	{
	public:
		virtual void pvf() = 0;
		virtual void vf() { cout << "B1::vf()" << endl; };
		void f() { cout << "B1::f()" << endl; };
	};

	class D1 : public B1
	{
	public:
		void pvf() override { cout << "D1::pvf()" << endl; };
		void vf() override { cout << "D1::vf()" << endl; };
		void f() { cout << "D1::f()" << endl; };
	};

	class D2 : public D1
	{
	public:
		void pvf() override { cout << "D2::pvf()" << endl; };
	};

	class B2
	{
	public:
		virtual void pvf() = 0;
	};

	class D21 : public B2
	{
	public:
		void pvf() override { cout << sdm << endl; };
		string sdm = "I'm D21";
	};

	class D22 : public B2
	{
	public:
		void pvf() override{ cout << idm << endl; };
		int idm = 2021;
	};

	void f(B2& bref) { 
		bref.pvf();
	};

	void start() override
	{
		// Task 1
		cout << "Task 1" << endl;
		//B1 b;
		//b.vf();
		//b.f();

		// Task 2
		cout << endl << "Task 2" << endl;
		D1 d;
		d.pvf();
		d.vf();
		d.f();

		// Task 3
		cout << endl <<  "Task 3" << endl;
		B1& bref{ d };
		bref.pvf();
		bref.vf();
		bref.f();

		// Task 6
		cout << endl << "Task 6" << endl;
		D2 dd;
		dd.pvf();
		dd.vf();
		dd.f();

		// Task 7
		cout << endl << "Task 7" << endl;
		D21 d21;
		f(d21);

		D22 d22;
		f(d22);
	}
};