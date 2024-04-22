// thap ha noi
#include <iostream>
using namespace std;
void thaphanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        cout << "Chuyen tu " << a << " sang " << c << endl;
    }
    else
    {
        thaphanoi(n - 1, a, c, b);
        thaphanoi(1, a, b, c);
        thaphanoi(n - 1, b, a, c);
    }
}
int main()
{
    int n;
    cout << "Nhap so dia: ";
    cin >> n;
    thaphanoi(n, 'A', 'B', 'C');
    return 0;
}