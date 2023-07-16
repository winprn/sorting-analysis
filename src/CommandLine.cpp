#include "CommandLine.h"

SortBase* getSortingObject(char* algorithmName) {
    if (strcmp(algorithmName, "bubble-sort") == 0) {
        return new BubbleSort();
    }
    else if (strcmp(algorithmName, "radix-sort") == 0) {
        return new RadixSort();
    }
    else if (strcmp(algorithmName, "merge-sort") == 0) {
        return new MergeSort();
    }
    else if (strcmp(algorithmName, "flash-sort") == 0) {
        return new FlashSort();
    }
    // ... to be continue
    else {
        return nullptr;
    }
}

void CommandLine1(int argc, char* argv[])
{
    SortBase* sortingObject = getSortingObject(argv[2]);
    sortingObject->readFromFile(argv[3]);
    sortingObject->startTimer();
    sortingObject->sort();
    sortingObject->stopTimer();

    SortBase* compareObject = getSortingObject(argv[2]);
    compareObject->readFromFile(argv[3]);
    compareObject->sortWithComparison();

    // display
    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input file: " << argv[3] << "\n";
    std::cout << "Input size: " << sortingObject->getSize() << "\n";
    std::cout << "-------------------------\n";
    if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
        std::cout << "Running Time: " << sortingObject->getDuration() << " milliseconds\n";
    if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
        std::cout << "Comparisions: " << compareObject->getComparison() << "\n";    
    delete sortingObject;
    delete compareObject;
}

void CommandLine2(int argc, char* argv[])
{
    int array_size = stoi(argv[3]);
    int* array = new int[array_size];
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

    SortBase* sortingObject = getSortingObject(argv[2]);
    sortingObject->copyArray(array, array_size);
    sortingObject->startTimer();
    sortingObject->sort();
    sortingObject->stopTimer();

    SortBase* compareObject = getSortingObject(argv[2]);
    compareObject->copyArray(array, array_size);
    compareObject->sortWithComparison();

    // display
    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input size: " << argv[3] << "\n";
    std::cout << "Input order: " << argv[4] << "\n";

    std::cout << "-------------------------\n";
    if (strcmp(argv[5], "-time") == 0 || strcmp(argv[5], "-both") == 0)
        std::cout << "Running Time: " << sortingObject->getDuration() << " seconds\n";
    if (strcmp(argv[5], "-comp") == 0 || strcmp(argv[5], "-both") == 0)
        std::cout << "Comparisions: " << compareObject->getComparison() << "\n";    
    
    // deallocation
    delete array;
    delete sortingObject;
    delete compareObject;
}

void CommandLine3(int argc, char* argv[])
{
    int array_size = stoi(argv[3]);
    int* array = new int[array_size];
    char* Orders[] = {"Randomize", "Sorted", "Reversed", "Nearly Sorted"};

    std::cout << "ALGORITHM MODE\n";
    std::cout << "ALGORITHM: " << argv[2] << "\n";
    std::cout << "Input size: " << argv[3] << "\n";

    for (int i = 0; i < 4; i++)
    {
        SortBase* sortingObject = getSortingObject(argv[2]);
        GenerateData(array, array_size, i);
        sortingObject->copyArray(array, array_size);
        sortingObject->startTimer();
        sortingObject->sort();
        sortingObject->stopTimer();

        SortBase* compareObject = getSortingObject(argv[2]);
        compareObject->copyArray(array, array_size);
        compareObject->sortWithComparison();

        // display
        std::cout << "\nInput order: " << Orders[i] << "\n";
        std::cout << "-------------------------\n";
        if (strcmp(argv[4], "-time") == 0 || strcmp(argv[4], "-both") == 0)
            std::cout << "Running Time: " << sortingObject->getDuration() << " seconds\n";
        if (strcmp(argv[4], "-comp") == 0 || strcmp(argv[4], "-both") == 0)
            std::cout << "Comparisions: " << compareObject->getComparison() << "\n";    
        
        delete sortingObject;
        delete compareObject;
    }
    
    // deallocation
    delete[] array;
}

void CommandLine4(int argc, char* argv[])
{

}

void CommandLine5(int argc, char* argv[])
{

}
