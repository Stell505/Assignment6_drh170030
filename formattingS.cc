/*
 * File:     formattingS.cc
 * Author:   David Hebert
 * NetID:   drh170030
 * Email:    drh170030@utdallas.edu
 */


#include "Assignment6.h"

string formatted1(BinaryFileRecord* recordInfo){
  std::ostringstream out;
  out << endl <<"strlen: " << unsigned(recordInfo->strLength) << endl;
  string hold = out.str();

  return hold;
}

string formatted2(BinaryFileRecord* recordInfo){
  std::ostringstream out;
  out << recordInfo->stringBuffer << endl;
  string hold = out.str();

  return hold;
}
