/*
    Parser for http messages.
*/

#ifndef HTTP_PARSER_H_INCLUDED
#define HTTP_PARSER_H_INCLUDED

#include "http.h"

extern const Method INVALID_METHOD;  // internal code for invalid method

typedef enum {

    UNEXPECTED_END_OF_TEXT = -1

} ParserError;

// parses request string in a http object
int parseRequest(char *requestString, HttpMsg **request);

// Forges a response string from an http object
char *forgeResponse(HttpMsg *response);

#endif // HTTP_PARSER_H_INCLUDED
