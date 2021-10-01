include<iostream> using namespace std;
int checkLeap(int);
int main()
{
    int yr, val;
    cout << "Enter the Year: ";
    cin >> yr;
    val = checkLeap(yr);
    if (val == 1)
        cout << "\nIt is a Leap Year";
    else
        cout << "\nIt is not a Leap Year";
    cout << endl;
    return 0;
}
int checkLeap(int yr)
{
    if ((yr % 4 == 0) && (yr % 100 != 0))
        return 1;
    else if (yr % 400 == 0)
        return 1;
    else
        return 0;
}