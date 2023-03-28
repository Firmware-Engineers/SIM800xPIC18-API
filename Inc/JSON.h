/**
*************************************************************************
*  	@file: JSON.h
*
*  	@brief: Header file for the JSON parser library
*  	@brief: This file provide function declarations, macros and constants
*			used to implement a lightweight JSON file parser for embedded applications.
*			**The parser is not fully compliant with ECMA 404, development is still ongoing.**
*
*	@note 	history:
*				- 03/25/2023: v0.2
*                   * Modified AddEntryToJsonObject function to automatically make keys strings.
*                   * Changed char pointer variable type from unsigned char to unsigned short
*                   * Modified documentation for further doxygen compatibility.
* 
*				- Initial release   : v0.1, June 10 2021
* 
*				- 09/13/2021
*                   * Added Doxygen tags for documentation generation
*                   * Added JSON tokens definitions
*                   * Added some deserialization functions
*                       * GetValueFromJsonArray function
*                       * GetEntryFromJsonObject
*                       * GetKeyFromJsonEntry
*                       * GetValueFromJsonEntry
*
*
*	@note	IDE:
*				- Code::Blocks v20.03
*				- Originally ECLIPSE CPP 2019 12R
*************************************************************************
*/

//==========================================================================//
//								Includes									//
//==========================================================================//
#include <stdio.h>															
#include <string.h>															
//==========================================================================//

//===================================
/**
* @brief				Add a value to a JSON array, value could be any of the JSON values (See ECMA 404)
* @param	JsonArray	: pointer to a char array to store the value in
* @param    value		: Value to add in the array
* @param	Cpos		: pointer to a byte to store the current character position in the JSON array
* @retval  	byte		:
*/
extern unsigned char AddValueToJsonArray(char * JsonArray, const char * value, unsigned int *Cpos);
//===================================

//===================================
/**
* @brief				: Add an entry to a JSON object
* @param	JsonObject	: Pointer to a char array to store the entry in
* @param    key			: Pointer to a char array for the current entry key (Only strings)
* @param    value		: Pointer to a char array for the current entry value, could be any of the JSON values (See ECMA 404)
* @param    Cpos		: Pointer to a byte to store the current character position in the JSON object pointer
* @retval  	byte		:
*/
extern unsigned char AddEntryToJsonObject(char * JsonObject, const char * key, const char * value, unsigned int *Cpos);
//===================================

//===================================
/**
* @brief				: Get value from a JSON array, value could be any of the JSON values (See ECMA 404)
* @param	JsonArray	: Pointer to a char array that contains a valid JSON array
* @param	value		: Pointer to a char array to store the value
* @param	idx			: Zero base index of the value in the array
* @note					: An index of 0 means the first value in the JSON array
* @retval  	0			: Operation succeeded
* @retval	1			: Operation failed
*/
extern unsigned char GetValueFromJsonArray(char * JsonArray, char* value, unsigned char idx);
//===================================

//===================================
/**
* @brief				: Get an entry from a JSON object ("key":value pair)
* @param	JsonObject	: Pointer to a char array that contains a valid JSON object
* @param	entry		: Pointer to a char array to store the entry
* @param	idx			: Zero base index of the entry in the JSON object
* @note					: An index of 0 means the first entry in the JSON object
* @retval  	0			: Operation succeeded
* @retval	1			: Operation failed
*/
extern unsigned char GetEntryFromJsonObject(char * JsonObject, char* entry, unsigned char idx);
//===================================

//===================================
/**
* @brief				: Get a key from a JSON entry
* @param	JsonObject	: Pointer to a char array that contains a valid JSON entry
* @param	entry		: Pointer to a char array to store the entry key
* @retval  	0			: Operation succeeded
* @retval	1			: Operation failed
*/
extern unsigned char GetKeyFromJsonEntry(char * JsonEntry, char* key);
//===================================

//===================================
/**
* @brief				: Get a value from a JSON entry
* @param	JsonObject	: Pointer to a char array that contains a valid JSON entry
* @param	value		: Pointer to a char array to store the entry value
* @retval  	0			: Operation succeeded
* @retval	1			: Operation failed
*/
extern unsigned char GetValueFromJsonEntry(char * JsonEntry, char* value);
//===================================
