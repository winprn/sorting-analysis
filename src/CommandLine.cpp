#include "CommandLine.h"
#include "iomanip"

void readFromFile(int*& m_array, int& m_size, const char* fileName)
{
    ifstream ifs(fileName);
    if (!ifs.is_open())
    {
        cerr << "Cannot Open File\n";
        return;
    }
    ifs >> m_size;
    delete[] m_array;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; i++)
    {
        ifs >> m_array[i];
    }
    ifs.close();
}

SortingAlgorithm convertStringToEnum(char* algorithmName)
{
    // cout << algorithmName << endl;
    if (strcmp(algorithmName, "bubble-sort") == 0) {
        // cout << 1 << endl;
        return SortingAlgorithm::BubbleSort;
    }
    else if (strcmp(algorithmName, "radix-sort") == 0) {
        return SortingAlgorithm::RadixSort;
    }
    else if (strcmp(algorithmName, "merge-sort") == 0) {
        return SortingAlgorithm::MergeSort;
    }
    else if (strcmp(algorithmName, "flash-sort") == 0) {
        return SortingAlgorithm::FlashSort;
    }
    else if (strcmp(algorithmName, "bubble-sort") == 0) {
        return SortingAlgorithm::BubbleSort;
    }
    else if (strcmp(algorithmName, "insertion-sort") == 0) {
        return SortingAlgorithm::InsertionSort;
    }
    else if (strcmp(algorithmName, "selection-sort") == 0) {
        return SortingAlgorithm::SelectionSort;
    }
    else if (strcmp(algorithmName, "shell-sort") == 0) {
        return SortingAlgorithm::ShellSort;
    }
    else if (strcmp(algorithmName, "shaker-sort") == 0) {
        return SortingAlgorithm::ShakerSort;
    }
    else if (strcmp(algorithmName, "heap-sort") == 0) {
        return SortingAlgorithm::HeapSort;
    }
    else if (strcmp(algorithmName, "counting-sort") == 0) {
        return SortingAlgorithm::CountingSort;
    }
    return SortingAlgorithm::QuickSort;
}

void CommandLine1(int argc, char *argv[])
{
    int *array = nullptr, size = 0;
    readFromFile(array, size, argv[3]);

    SortContext sortingObject;
    sortingObject.setStrategy(convertStringToEnum(argv[2]), array, size);
    if (sortingObject.getStrategy() == nullptr)
    {
        cerr << "Invalid algorithm!\n";
        return;
    }
    sortingObject.sort();

    SortContext compareObject;
    compareObject.setStrategy(convertStringToEnum(argv[2]), array, size);
    compareObject.sortWithComparison();

    cout << 1 << endl;
    // write to "output.txt"
    sortingObject.writeToFile("output.txt");

    // display
    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input file: " << argv[3] << "\n";
    std::cout << "Input size: " << size << "\n";
    std::cout << "-------------------------\n";
    if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
        std::cout << "Running Time: " << sortingObject.getDuration() << " seconds\n";
    if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
        std::cout << "Comparisions: " << compareObject.getComparison() << "\n";
    delete[] array;
}

void CommandLine2(int argc, char *argv[])
{
    int array_size = std::atoi(argv[3]);
    int *array = new int[array_size];
    if (strcmp(argv[4], "-rand") == 0)
    {
        GenerateRandomData(array, array_size);
    }
    else if (strcmp(argv[4], "-nsorted") == 0)
    {
        GenerateNearlySortedData(array, array_size);
    }
    else if (strcmp(argv[4], "-sorted") == 0)
    {
        GenerateSortedData(array, array_size);
    }
    else if (strcmp(argv[4], "-rev") == 0)
    {
        GenerateReverseData(array, array_size);
    }

    SortContext sortingObject;
    sortingObject.setStrategy(convertStringToEnum(argv[2]), array, array_size);
    if (sortingObject.getStrategy() == nullptr)
    {
        cerr << "Invalid algorithm!\n";
        return;
    }
    sortingObject.sort();

    // write to "output.txt"
    sortingObject.writeToFile("ouput.txt");

    SortContext compareObject;
    compareObject.setStrategy(convertStringToEnum(argv[2]), array, array_size);
    compareObject.sortWithComparison();
    
    // display
    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input size: " << argv[3] << "\n";
    std::cout << "Input order: " << argv[4] << "\n";

    std::cout << "-------------------------\n";
    if (strcmp(argv[5], "-time") == 0 || strcmp(argv[5], "-both") == 0)
        std::cout << "Running Time: " << sortingObject.getDuration() << " seconds\n";
    if (strcmp(argv[5], "-comp") == 0 || strcmp(argv[5], "-both") == 0)
        std::cout << "Comparisions: " << compareObject.getComparison() << "\n";

    // deallocation
    delete[] array;
}

void CommandLine3(int argc, char *argv[])
{
    int array_size = std::atoi(argv[3]);
    int *array = new int[array_size];
    std::string Orders[] = {"Randomize", "Sorted", "Reversed", "Nearly Sorted"};

    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input size: " << argv[3] << "\n";

    int num[] = {1, 3, 4, 2};

    for (int i = 0; i < 4; i++)
    {
        GenerateData(array, array_size, i);

        ofstream ofs("input_" + to_string(num[i]) + ".txt");
        ofs << array_size << "\n";
        for (int i = 0; i < array_size; i++)
        {
            ofs << array[i] << " ";
        }
        ofs.close();

        SortContext sortingObject;
        sortingObject.setStrategy(convertStringToEnum(argv[2]), array, array_size);
        if (sortingObject.getStrategy() == nullptr)
        {
            cerr << "Invalid algorithm!\n";
            break;
        }
        sortingObject.sort();

        SortContext compareObject;
        compareObject.setStrategy(convertStringToEnum(argv[2]), array, array_size);
        compareObject.sortWithComparison();

        // display
        std::cout << "\nInput order: " << Orders[i] << "\n";
        std::cout << "-------------------------\n";
        if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
            std::cout << "Running Time: " << sortingObject.getDuration() << " seconds\n";
        if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
            std::cout << "Comparisions: " << compareObject.getComparison() << "\n";
    }
    // deallocation
    delete[] array;
}

void CommandLine4(int argc, char *argv[])
{
}

void CommandLine5(int argc, char *argv[])
{
}
