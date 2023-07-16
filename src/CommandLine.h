#ifndef SORTING_ANALYSIS_COMMAND_LINE_H
#define SORTING_ANALYSIS_COMMAND_LINE_H
#include "string.h"
#include "../include/BubbleSort.h"
#include "../include/FlashSort.h"
#include "../include/InsertionSort.h"
#include "../include/MergeSort.h"
#include "../include/RadixSort.h"
#include "../include/SelectionSort.h"
#include "../include/SortBase.h"

using namespace std;

void CommandLine1(int argc, char* argv[]);
void CommandLine2(int argc, char* argv[]);
void CommandLine3(int argc, char* argv[]);
void CommandLine4(int argc, char* argv[]);
void CommandLine5(int argc, char* argv[]);
SortBase* getSortingObject(char* algorithmName);

#endif