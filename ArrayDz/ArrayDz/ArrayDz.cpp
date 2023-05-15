// ArrayDz.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> // general streams
#include <fstream> // file streams
#include <string> // for file name
#include <cstdlib> // for random

const std::size_t ARRAY_SIZE = 5;

const std::string INPUT_FILE = "input.txt";

int Remainder(int arr[], std::size_t n)
{
    int k = 3; // заданное число
    int x = 0; // переменная для подсчета количество элементов, 
    // которые делятся на заданное число без остатка
    for (std::size_t i = 0; i < n; ++i)
    {
        if (arr[i] % k == 0)
        {
            x++;
        }
    }
    return x;
}

int main()
{
    // static array(1) 
    std::cout << "static array with fixed values" << '\n';
    int arrStatic[ARRAY_SIZE]{ -9, 2, 3, 4, 9 };

    std::cout << "static array: " << Remainder(arrStatic, ARRAY_SIZE) << '\n';

    // dynamic array with random(2)
    std::cout << "dynamic array with random numbers, input array size: ";
    std::size_t arraySize;
    std::cin >> arraySize;
    
    if (!std::cin)
    {
        std::cout << "Incorrect input" << '\n';
        return 1;
    }
    
    int* arrDynamic = new int[arraySize];
    
    // fill with random numbers
    for (std::size_t i = 0; i < arraySize; ++i)
    {
        arrDynamic[i] = 1 + std::rand() / ((RAND_MAX + 1u) / 6);;
    }
    
    // print array
    for (std::size_t i = 0; i < arraySize; ++i)
    {
        std::cout << arrDynamic[i] << " ";
    }
    
    std::cout << '\n';
    std::cout << "dynamic array: " << Remainder(arrDynamic, arraySize) << '\n';

    delete[] arrDynamic;

    // read file into dynamic array(3)
    std::cout << "dynamic array from file" << '\n';

    std::ifstream input(INPUT_FILE);
    if (!input)
    {
        std::cout << "Error by opening file " << INPUT_FILE << '\n';
        return 2;
    }

    input >> arraySize; // read array size
    if (!input)
    {
        std::cout << "Incorrect input" << '\n';
        return 1;
    }
    int* arrDynamicFromFile = new int[arraySize]; // get array

    // read array elements
    for (std::size_t i = 0; i < arraySize; ++i)
    {
        input >> arrDynamicFromFile[i];
        if (!input)
        {
            std::cout << "Incorrect input" << '\n';
            return 1;
        }
    }

    input.close(); // close file

    // print array 
    for (std::size_t i = 0; i < arraySize; ++i)
    {
        std::cout << arrDynamicFromFile[i] << " ";
    }
    std::cout << '\n';

    std::cout << "dynamic array from file: " << Remainder(arrDynamicFromFile, arraySize) << '\n';

    delete[] arrDynamicFromFile; // RETURN MEMORY TO OPERATING SYSTEM TO AVOID MEMORY LEAKS

    return 0;
}
    

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
