#ifndef SORTING_ANALYSIS_COMMAND_LINE_H
#define SORTING_ANALYSIS_COMMAND_LINE_H
#include "../include/SortContext.h"
#include "../include/SortObject.h"
#include "DataGenerator.h"
#include "common.h"
#include "string.h"
#include "iomanip"

void CommandLine1(int argc, char* argv[]);
void CommandLine2(int argc, char* argv[]);
void CommandLine3(int argc, char* argv[]);
void CommandLine4(int argc, char* argv[]);
void CommandLine5(int argc, char* argv[]);
SortingAlgorithm convertStringToEnum(char* algorithmName);

#endif