#include <iostream>
 
class Fraction
{
    private:
        int Numerator, Denominator;
    public:
        friend std::istream& operator >> (std::istream& in, Fraction& p);
        friend std::ostream& operator << (std::ostream& out, Fraction p);
        
        void set_Tu(int k) { Numerator = k;}
        void set_Mau(int k) { Denominator = k;}
        int get_Tu() { return Numerator; }
        int get_Mau() { return Denominator; }

        void Out_N_D();
        void Reciprocal();
        void Simplify();
        void Addition();
        
        Fraction();
        
        Fraction(int Numerator, int Denominator);
        Fraction(int n);
        Fraction(const Fraction& p);
        
        ~Fraction(){};
};

int Find_GCD(int a, int b);

int main()
{
    Fraction p1,p2;
    std::cin >> p1 >> p2;
    std::cout << p1;
    std::cout << "\n";
    p1.Out_N_D();
    p1.Reciprocal();
    p1.Simplify();
    p1.Addition();
    return 0;
}

std::istream& operator >> (std::istream& in, Fraction& p)
{
    in >> p.Numerator >> p.Denominator;
    return in;
}
std::ostream& operator << (std::ostream& out, Fraction p)
{
    out << p.Numerator << "/" << p.Denominator;
    return out;
}

void Fraction::Out_N_D()
{
    std::cout << Numerator << "\n" << Denominator << "\n";
}

void Fraction::Reciprocal()
{
    std::cout << Denominator << "/" << Numerator << "\n";
}

int Find_GCD(int a, int b)
{
    if(b==0) 
        return a;
    return Find_GCD(b, a % b);
}

void Fraction::Simplify()
{
    if (Numerator != 0)
    {
        int result = Find_GCD(Numerator, Denominator);
        Numerator /= result;
        Denominator /= result;
    }
    std::cout << Numerator << "/" << Denominator << "\n";
}

void Fraction::Addition()
{
    int a,b;
    a = Numerator * Numerator + Denominator * Denominator;
    b = Denominator * Numerator;
    std::cout << a << "/" << b ;
}

Fraction::Fraction()
{
    Numerator = 0;
    Denominator = 1;
}

Fraction::Fraction(int num, int deno)
{
    Numerator = num;
    Denominator = deno;
}

Fraction::Fraction(int n)
{
    Numerator = n;
    Denominator = 1;
}

Fraction::Fraction(const Fraction& p)
{
    Numerator = p.Numerator;
    Denominator = p.Denominator;
}

