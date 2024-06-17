
class __declspec(dllexport) Plus
{
public:
    void SetNumber1(int num);
    void SetNumber2(int num);

    int GetResult() const noexcept;

private:
    int m_number1 { 0 };
    int m_number2 { 0 };
};
