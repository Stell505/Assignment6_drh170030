/*
 * File:   assignment6.cc
 * Author: David Hebert
 * NetID: drh170030
 * Email:  drh170030@utdallas.edu
 */

#include <iostream>
#include <fstream>
#include <cstring> 	// for memset()
#include <cstdint>
#include "cdk.h"
#include "Assignment6.h"
#include <string>
#include <sstream>

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5 
#define BOX_WIDTH 20 
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


int main()
{
	
  ifstream binInfile;

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"C0", "a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */

  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
 
 drawCDKMatrix(myMatrix, true);

  BinaryFileHeader *headF = new BinaryFileHeader();

  binInfile.open ("/scratch/perkins/cs3377.bin", ios::in | ios::binary);
  
  binInfile.read((char *) headF, sizeof(BinaryFileHeader));
 
  std::ostringstream out;
  out << "Magic: 0x" << std::hex << std::uppercase << headF->magicNumber<< std::dec << std::nouppercase << endl;
  setCDKMatrixCell(myMatrix,1,1, out.str().c_str());
  
  out.str("");
  out << "Version: "  << headF->versionNumber << endl;
  setCDKMatrixCell(myMatrix,1,2, out.str().c_str());

  out.str("");
  out << "NumRecords: " << headF->numRecords << endl;
  setCDKMatrixCell(myMatrix,1,3, out.str().c_str());

for(int i = 2; i < 6; i++){
  BinaryFileRecord *recordInfo = new BinaryFileRecord();
  binInfile.read((char *) recordInfo, sizeof(BinaryFileRecord));
  
  out.str("");
  string hold1 = formatted1(recordInfo);
  setCDKMatrixCell(myMatrix, i, 1, hold1.c_str());
  
  out.str("");
//  out << recordInfo->stringBuffer << endl;
 string hold2 = formatted2(recordInfo);
 setCDKMatrixCell(myMatrix, i, 2, hold2.c_str());
}
	

   drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (10);


  // Cleanup screen
  endCDK();


}
