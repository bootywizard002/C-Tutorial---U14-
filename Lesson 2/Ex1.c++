#include <iostream>

class Fraction
{
private:
    int numerator {};
    int dinomenator {};

public:
    Fraction (int num, int din)
        : numerator {num}, dinomenator {din}
        {}
    
    void print() const
    {
        std::cout<< numerator << "/" << dinomenator << "\n";
    }

    friend Fraction operator* (const Fraction& one, const Fraction& two);
    friend Fraction operator* (const Fraction& one, const int integer);
    friend Fraction operator* (const int integer,  const Fraction& one);

};

Fraction operator* (const Fraction& one, const Fraction& two)
{
    return {one.numerator * two.numerator, one.dinomenator * two.dinomenator};
}

Fraction operator* (const Fraction& one, const int integer)
{
    return {one.numerator * integer, one.dinomenator};
}

Fraction operator* (const int integer,  const Fraction& one)
{
    return {one.numerator * integer, one.dinomenator};
}

int main()
{
Fraction f1{2, 5};
	f1.print();

	Fraction f2{3, 8};
	f2.print();

	Fraction f3{ f1 * f2 };
	f3.print();

	Fraction f4{ f1 * 2 };
	f4.print();

	Fraction f5{ 2 * f2 };
	f5.print();

	Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
	f6.print();
}