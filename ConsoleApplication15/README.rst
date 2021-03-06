==============================================================
csv-cpp
==============================================================

--------------------------------------------------------------
Character-Seperated Values (CSV) Parser
--------------------------------------------------------------

.. image:: https://travis-ci.org/gbmhunter/csv-cpp.svg?branch=master   
	:target: https://travis-ci.org/gbmhunter/csv-cpp

- Author: gbmhunter <gbmhunter@gmail.com> (http://www.cladlab.com)
- Created: 2014/04/07
- Last Modified: 2014/05/27
- Version: v2.3.1.0
- Company: CladLabs
- Project: Free Code Libraries
- Language: C++
- Compiler: GCC	
- uC Model: n/a
- Computer Architecture: n/a
- Operating System: n/a
- Documentation Format: Doxygen
- License: GPLv3

.. role:: bash(code)
	:language: bash

Description
===========

A C++ CSV (character-seperated value, also known as comma-seperated value) parser which can both decode/encode CSV files.

Powerful
--------

You can define what CsvCpp will use as a line delimiter (Parser::lineDelimiter).

Standards Compliant
-------------------

This CSV parsing library follows the speficiations and terminology of RFC 4180, which is accepted as the de-facto standard for CSV files.

Portable (Platform Agnostic)
----------------------------

csv-cpp can be used with ease on both Linux and embedded systems (as long as they are powerful enough to support strings and streams).

All platform-specific operations such as debug and error message printing are handled by providing you with pointer variables to assign to objects at run time.


Easy Including
--------------

All you need to do is include the single header file called :code:`CsvCpp.hpp` which is found in the :code:`api/` directory, and provide the compiler with all the files in the :code:`src/` directory.

Easy To Experiment With
-----------------------

CsvCpp comes with a Makefle with automatic dependcy tracking and example code which is automatically built on running the command :code:`make` from the root directory of the repo.

Once compiled, this example code can be run by typing :code:`example/Example.elf`.


Included Unit Tests
-------------------

CsvCpp used the UnitTest++ library to perform unit testing. They are located under :code:`test/`. The UnitTest++ library is included with this repo.

The unit tests check for:

- Basic funcitonality
- Various line delimiters


Installation
============

1. Clone the git repo onto your local storage.

2. Run :code:`make all` to compile and run unit tests. Do not worry about error messages being printed when unit tests are run, the unit tests are designed to specifically cause errors to test the response.

3. To include CsvCpp into your embedded (or otherwise) firmware/software project, copy the repo into your project folder (or other suitable place) and include the file :code:`/api/CsvCpp.hpp` from your C++ code.


Dependencies
============

The following table lists all of csv-cpp's dependencies.

====================== ==================== ======================================================================
Dependency             Delivery             Usage
====================== ==================== ======================================================================
<iostream>             Standard C++ library std::cin, std::cout
<fstream>              Standard C++ library Writing to files using std::ofstream.
<cstdint>              Standard C++ library Fixed-width variable type definitions (e.g. uint32_t).
UnitTest++             /lib/UnitTest++      Unit test framework (test code in ./test/).
boost::optional        /lib/boost/optional  Use of optional object in the Parser::Status class (returned by Parser::GetStatus()).
====================== ==================== ======================================================================


Issues
======

See GitHub Issues.

Examples
========

Following are some basic examples. See "example/" or "test/" for more examples.

Reading A CSV File Into A CsvTable Object And Then Printing Out Each Field
-------------------------------------------------------------------------- 

::

	#include "api/CsvCpp.hpp"

	
	int main()
	{
		CsvCpp::Parser csvParser;
		
		csvParser.SetFilename("test.csv");
		csvParser.fieldDelimiter = ",";
		csvParser.recordDelimiter = "\n";

		// Attempt to read the entire file into the csvTable object.
		CsvCpp::CsvTable csvTable;
		try
		{
			csvTable = csvParser.ReadEntireFile();
		}
		catch(std::exception& e)
		{
			std::cout << e.what();
			// Something bad happened
			return -1;
		}

		// Print out the CSV table, record by record, field by field
		uint32_t x, y;

		for(x = 0; x < csvTable.NumRecords(); x++)
		{
			for(y = 0; y < csvTable[x].NumFields(); y++)
			{
				std::cout << "csvTable[" << x << "][" << y << "] = " << csvTable[x][y] << std::endl;

			}
		}
		
		// Parsing successful!
		return 0;
	}
	
Writing A CSV File
------------------

::

	#include "api/CsvCpp.hpp"
	
	int main()
	{
	
		CsvCpp::Parser csvParser;
		CsvCpp::CsvTable csvTable;
	
		CsvCpp::CsvRecord record1;
		record1.AddField("element11");
		record1.AddField("element12");
		csvTable.AddRecord(record1);
	
		CsvCpp::CsvRecord record2;
		record2.AddField("element21");
		record2.AddField("element22");
		csvTable.AddRecord(record2);
	
		// Set the filename
		csvParser.SetFilename("output.csv");
	
		// Create CSV file, passing in the CSV table object we wish to create to file with
		csvParser.CreateCsvFile(&csvTable);
	}
	
Checking Various Stats About CsvTable Object
--------------------------------------------


	
	
FAQ
===

Nothing yet...

Changelog
=========

========= ========== ===================================================================================================
Version    Date       Comment
========= ========== ===================================================================================================
v2.3.1.0  2014/05/27 Add 'logger-cpp' into 'lib/logger-cpp' as a git submodule. Updated 'logger-cpp' to fix crash with static initilisation fiasco bug. Makefile clean now cleans 'logger-cpp' library code correctly also.
v2.3.0.0  2014/05/27 Removed manually placed 'lib/logger-cpp' files in preparation for adding it as a git submodule instead.
v2.2.2.0  2014/05/26 Fixed error in code introduced in previous commit, now compiles o.k.
v2.2.1.0  2014/05/26 Filename now returned when invalid filename exception thrown in 'Parser::ReadEntireFile()'., and errorMsg is no longer printed to, closes #42.
v2.2.0.0  2014/05/21 Fixed debug and error printing with addition of Logger library (in 'lib/logger-cpp/'). Added exception throwing for 'Parser::CreateCsvFile()', closes #36.
v2.1.9.0  2014/05/19 Added comment that you can use .get() function on Boost optional variables.
v2.1.8.0  2014/05/19 Fixed bug when the first field of a record was empty, closes #38. Add relevant unit tests for this, closes #39. Added 'Parser::Status' variable which idicates whether every field in CsvTable is numeral or not and added relevant unit tests, closes #37.
v2.1.7.0  2014/05/07 Removed 'Limitations' section of README, closes #35. Added more examples to the 'Example' section of README, closes #33. Correct the exception catch to the correct object type in 'test/ReadEntireFileTests.cpp' and 'test/ReadWriteTests.cpp', closes #34.
v2.1.6.0  2014/05/06 Converted 'const char*' exceptions into standard exceptions from the standard C++ library, modified unit tests to suit, closes #31. Fixed link to TravisCI image in README, closes #32.
v2.1.5.0  2014/05/05 Fixed bug where 'Parser::GetStatus()' would crash if an empty CsvTable object was passed to it, closes #29. Added unit test to make sure 'Parser::GetStatus()' returns 'isWellformed == false' if no records are present in the table, closes #21.
v2.1.4.0  2014/05/05 Parser object no longer prints 'csvLine empty' when debug printing is turned off, closes #19.
v2.1.3.0  2014/05/05 Added out-of-range protection to applicable csv-cpp methods and added relevant unit tests, closes #18. Added ability to delete both records and fields and added unit tests, closes #11. Moved operator overload definitions into '.cpp' files, closes #28.
v2.1.2.0  2014/05/05 Renamed Eclipse project to 'csv-cpp', closes #27. Also renamed in README.
v2.1.1.0  2014/05/05 Made class functions and function arguments 'const' where applicable, closes #25, closes #26. Changed Parser::CreateCsvFile() so that it takes a pointer to a CsvTable, closes #23. Prepended Table and Record objects with 'Csv', closes #22.
v2.1.0.0  2014/05/02 Added 'Parser::GetStatus(Table table)', which returns an object full of status info about the provided CSV table, and added relevant unit tests, closes #15. Improved Makefile code, closes #20. Added parts of the boost library to 'lib/boost/'. Added 'boost::optional' object to list of dependencies in README.
v2.0.6.0  2014/05/01 Added constructor that accepts record and field delimiters, closes #16. Converted default field and record delimiters into macros, closes #17.
v2.0.5.0  2014/05/01 Provided overload of 'Parser::CreateCsvFile()' which uses 'Parser::filename' instead of passing the filename in, and added relevant unit tests, closes #14.
v2.0.4.0  2014/05/01 Provided overload function 'Parser::SetFilename(std::string filename)' which uses given filename rather than the one stored in the 'Parser::filename' variable, and created relevant unit tests, closes #12. Renamed 'BasicTests.cpp' to 'ReadWriteTests.cpp', closes #13.
v2.0.3.0  2014/04/10 Added the ability to clear all records from a table through Table::Clear(), closes #7.
v2.0.2.0  2014/04/09 Added ability to use std::endl with Log objects (i.e. debugMsg and errorMsg), closes #10.
v2.0.1.0  2014/04/09 Added safe guard if output logging stream pointers in the Log class are null, closes #9. Add relevant unit test. Removed slotmachine-cpp from the list of dependencies in README, closes #8.
v2.0.0.0  2014/04/08 Added ability to create a CSV file from a CsvCpp::Table object, closes #4. Added relevant unit test.
v1.1.1.0  2014/04/08 Added constructor for Parser class and set lineDelimiter to default to '\r\n'. Added ability for the user to specify the field delimiter, closes #5. Renamed 'elements' to 'fields', and 'rows' to 'records', to follow RFC 4180, closes #6. Added info to README about being standards complant.
v1.1.0.0  2014/04/08 Added portable logging capability (debug and error messages) with Log.hpp/.cpp. Added ability to specify the line delimiting characters in CsvCpp::Parser, closes #3. Added related unit tests for various types of delimiters. Added unit test for when the last line does not have the line delimiting character. Edited README. Parser no longer causes segmentation fault if last line does not have a line delimitier, closes #1. Unit tests no longer leave left-over test.csv files, closes #2.
v1.0.0.0  2014/04/07 Initial commit. Parser performs basic CSV file decoding into a CsvTable object. Basic unit test makes sure than the Parser object can read a simple CSV file correctly.
========= ========== ===================================================================================================