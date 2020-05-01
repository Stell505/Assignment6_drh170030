/*
 * File:   assignment6.h
 * Author:   David Hebert
 * NetID:    drh170030
 * Email:    drh170030@utdallas.edu
 */


#include <iostream>
#include <fstream>
#include <cstring> 	// for memset()
#include <cstdint>
#include "cdk.h"
#include <string>
#include <sstream>

/*
 *  This header file described here:  http://www.cplusplus.com/reference/cstdint/
 */
#include <cstdint>

using namespace std;

const int maxRecordStringLength = 25;

class BinaryFileHeader
{
  public:

    uint32_t magicNumber;
    uint32_t versionNumber;
    uint64_t numRecords;
};

class BinaryFileRecord
{
  public:

    uint8_t strLength;
    char stringBuffer[maxRecordStringLength];
};

string formatted1(BinaryFileRecord*);
string formatted2(BinaryFileRecord*);
