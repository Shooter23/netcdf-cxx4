/*! Test open() and close() methods for NcFile.
 *
 * Methods contributed by user `Luthaf`. See
 * https://github.com/Unidata/netcdf-cxx4/pull/18/files
 * for more information.
 */
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <netcdf>
#include <iomanip>
#include "test_utilities.h"
using namespace std;
using namespace netCDF;
using namespace netCDF::exceptions;

/*! Standard 'main' function.
 *
 */
int main() {
    NcFile file;

    // Test opening a null file. Should fail.
    cout << "Attempting to open a file that doesn't exist... ";
    try {
      file.open("Doesn't Exist.",NcFile::read);
      cout << "Error. Expected an exception." << endl;
      return -1;
    } catch(NcException &e) {
      cout << "Caught Expected Exception." << endl;
    }

    const char *fileName = "firstFile.cdf";
    // Test opening a file that exists.
    cout << "Opening file \"" << fileName << "\"... ";
    try {
      file.open(fileName,NcFile::replace);
      cout << "Success." << endl;
    } catch(NcException &e) {
      cout << "Caught unexpected exception." << endl;
      return e.errorCode();
    }

    // Test retrieving path from file object.
    cout << "Retrieving path from file object... ";
    if (file.getPath() == fileName) {
      cout << "Success." << endl;
    } else {
      cout << "Retrieved file path did not match input filename." << endl;
      return -1;
    }

    // Test closing a valid file.
    cout << "Closing file... ";
    try {
      file.close();
      cout << "Success." << endl;
    } catch(NcException &e) {
      cout << "Caught unexpected exception." << endl;
      return e.errorCode();
    }


    cout << endl << "Finished." << endl;
    return 0;
}
