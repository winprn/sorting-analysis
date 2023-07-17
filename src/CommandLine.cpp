#include "CommandLine.h"
#include "iomanip"

void readFromFile(int *m_array, int &m_size, char *fileName)
{
    std::ifstream ifs(fileName);
    if (!ifs.is_open())
    {
        cerr << "Cannot Open File\n";
        return;
    }
    ifs >> m_size;
    if (m_array != nullptr)
        delete[] m_array;
    m_array = new int[m_size];
    for (int i = 0; i < m_size; i++)
    {
        ifs >> m_array[i];
    }
    ifs.close();
}

void CommandLine1(int argc, char *argv[])
{
    int *array = nullptr, size = 0;
    readFromFile(array, size, argv[3]);

    SortContext sortingObject;
    sortingObject.setStrategy(convertStringToEnum(argv[2]), array, size);
    if (sortingObject.getArray() == nullptr)
    {
        cerr << "Invalid algorithm!\n";
        return;
    }
    sortingObject.startTimer();
    sortingObject.sort();
    sortingObject.stopTimer();

    SortContext compareObject;
    compareObject.setStrategy(convertStringToEnum(argv[2]), array, size);
    compareObject.sortWithComparison();

    // display
    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input file: " << argv[3] << "\n";
    std::cout << "Input size: " << sortingObject.getSize() << "\n";
    std::cout << "-------------------------\n";
    if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
        std::cout << "Running Time: " << fixed << setprecision(5) << sortingObject.getDuration() << " seconds\n";
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
    if (sortingObject.getArray() == nullptr)
    {
        cerr << "Invalid algorithm!\n";
        return;
    }
    sortingObject.startTimer();
    sortingObject.sort();
    sortingObject.stopTimer();

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
    char *Orders[] = {"Randomize", "Sorted", "Reversed", "Nearly Sorted"};

    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input size: " << argv[3] << "\n";

    for (int i = 0; i < 4; i++)
    {
        GenerateData(array, array_size, i);

        SortContext sortingObject;
        sortingObject.setStrategy(convertStringToEnum(argv[2]), array, array_size);
        sortingObject.startTimer();
        sortingObject.sort();
        sortingObject.stopTimer();

        if (sortingObject.getArray() == nullptr)
        {
            cerr << "Invalid algorithm!\n";
            break;
        }

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
