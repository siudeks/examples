#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{

    srand(time(NULL));

    // liczba generowanych elementów
    int count = 10;

    int result[count];


    // Stwórz plik 1.txt z wartościami losowymi od 1 do 20
    {
        int numbers1[count];
        int minValue1 = 1;
        int maxValue2 = 20;
        for (int i = 0; i < count; i++)
        {
            auto randomValue = rand() % (maxValue2 - minValue1) + minValue1;
            numbers1[i] = randomValue;
        }
        sort(numbers1, numbers1 + count);
        ofstream file1("1.txt");
        for (int i = 0; i < count; i++)
        {
            int value = numbers1[i];
            file1 << value << "\n";
        }
        file1.close();

        for (int i = 0; i < count; i++)
        {
            auto value = numbers1[i];
            result[i] = value;
        }
    }


    // Stwórz plik 2.txt z wartościami losowymi od 1 do 20
    // Jednocześnie stwórz plik 3.txt z sumą plików 1.txt i 2.txt
    {
        int numbers2[count];
        int minValue1 = 20;
        int maxValue2 = 40;
        for (int i = 0; i < count; i++)
        {
            auto randomValue = rand() % (maxValue2 - minValue1) + minValue1;
            numbers2[i] = randomValue;
        }
        sort(numbers2, numbers2 + count);
        ofstream file2("2.txt");
        for (int i = 0; i < count; i++)
        {
            int value = numbers2[i];
            file2 << value << "\n";
        }
        file2.close();

        ofstream file3("3.txt");
        for (int i = 0; i < count; i++)
        {
            auto value = numbers2[i];
            result[i] += value;
            file3 << result[i] << "\n";
        }
        file3.close();

    }

    return 0;
}