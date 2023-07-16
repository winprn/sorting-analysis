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
}

void CommandLine2(int argc, char* argv[])
{

}

void CommandLine3(int argc, char* argv[])
{

}

void CommandLine4(int argc, char* argv[])
{

}

void CommandLine5(int argc, char* argv[])
{

}
