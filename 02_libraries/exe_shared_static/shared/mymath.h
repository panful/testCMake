
class __declspec(dllexport) MyMath
{
public:
    MyMath(int, int);
    int Add() const;
    int Sub() const;

private:
    int m_number0;
    int m_number1;
};