/*
    Parses http messages from text
*/

#include "httpParser.h"
#include "logger.h"
#include <string.h>
#include <stdlib.h>

#define BODY_MAX_LEN 2048
#define UNKNOWN_TEXT ""

const Method INVALID_METHOD = NUM_OF_METHODS;

// parses starting line
void parseStartingLine(char *startLineString, StartLine *startLine){

    if (startLineString != NULL){

        char *savePtr = NULL;

        // parses method
        char *methodText = strtok_r(startLineString, HTTP_WORD_SEPARATOR, &savePtr);
        Method retrievedMethod;
        if (methodText != NULL){
            trim(&methodText);
            retrievedMethod = (Method) getValueFromHashTable(METHODS, methodText);
        }
        startLine ->method = (retrievedMethod != NULL)? retrievedMethod : INVALID_METHOD;

        // parses URL
        char *urlText = strtok_r(NULL, HTTP_WORD_SEPARATOR, &savePtr);
        if (urlText != NULL){
            trim(&urlText);
            startLine -> url = urlText;
        } else {
            startLine -> url = UNKNOWN_TEXT;
        }

        // parses protocol version
        char *httpVersionText = strtok_r(NULL, HTTP_WORD_SEPARATOR, &savePtr);
        if (httpVersionText != NULL){
            trim(&httpVersionText);
            startLine -> httpVersion = httpVersionText;
        } else {
            startLine ->httpVersion = UNKNOWN_TEXT;
        }
    }
}

// parses headers
void parseHeaders(char *headersString, HashTable *headers){

    char *savePtr = NULL;
    char *headerSavePtr = NULL;

    if (headersString != NULL){

        // Parses every line of headers
        char *headerName, *headerValue;
        for (char *currentLine = strtok_r(headersString, HTTP_LINE_SEPARATOR, &savePtr); currentLine != NULL; currentLine = strtok_r(NULL, HTTP_LINE_SEPARATOR, &savePtr)){

            // adds to headers table pairs headerName-headerValue. Pairs are added to the table only if headerName is not null
            headerName = strtok_r(currentLine, HTTP_HEADER_NAME_VALUE_SEPARATOR, &headerSavePtr);
            if (headerName != NULL){
                trim(&headerName);
                headerValue = strtok_r(NULL, HTTP_HEADER_NAME_VALUE_SEPARATOR, &headerSavePtr);
                if (headerValue != NULL){
                    trim(&headerValue);
                    addToHashTable(headers, headerName, headerValue);
                } else {
                    addToHashTable(headers, headerName, UNKNOWN_TEXT);
                }
            }

            // resets headerSavePtr
            *headerSavePtr = NULL;
        }
    }

}


// TODO: parses body
void parseBody(char *bodyString, HttpMsg *msg){


    // TODO: This code will be useful when parseBody method will be actually implemented
    // Uses maximum value between MAX_BODY_LEN and Content-Length value for parsing body
    /*
    int bodyLen;
    int contentLength = getValueFromHashTable(request -> headers, HEADER_NAMES[CONTENT_LENGTH])
    if (contentLength == NULL || contentLength > BODY_MAX_LEN){
        bodyLen = BODY_MAX_LEN;
    } else {
        bodyLen = contentLength;
    }
*/

    // TODO

    msg -> body = UNKNOWN_TEXT; // TODO: remove this line when parseBody is implemented
}

// Searches for delimiter in host, and overwrites it with all 0, then saves address of rest of the host in nextHost, if it's not null
void cut(char *host, char* delimiter, char **nextHost){

    char *endHost = strstr(host, delimiter);
    if (endHost != NULL){

       memset(endHost, '\0', strlen(delimiter));

        if (nextHost != NULL) {

            *nextHost = endHost + strlen(delimiter);
        }
    }

}

typedef enum {

    LEFT = -1,
    RIGHT = 1

} Direction;

// removes all leading spaces in string
void trim(char **string){

    trimCore(string, RIGHT);

    char *lastChar = index(*string, '\0') - 1;
    trimCore(&lastChar, LEFT);
}

void trimCore(char **string, Direction direction){

    switch (**string){
        case ' ':
        case '\n':
        case '\t':
        case '\v':
        case '\f':
        case '\r':
            **string = '\0';
            if (direction == RIGHT){
                *string = *string + direction;
            }
            trimCore(string, direction);
            break;
        default:
            return;
    }
}


// Parses an HTTP request string.
// PLEASE NOTE: the input request string will be modified, so use a copy if you want to save the original
int parseRequest(char *requestString, HttpMsg **requestPointer){

    // initializes request object
    *requestPointer = newHttpRequest();
    HttpMsg *request = *requestPointer;

    // A null request text produces an empty request object
    if (requestString != NULL){

        char *startLineString = NULL, *headersString = NULL, *bodyString = NULL;

        // Parses starting line
        startLineString = requestString;
        cut(startLineString, HTTP_LINE_SEPARATOR, &headersString);
        if (startLineString != NULL){
            parseStartingLine(startLineString, (StartLine *) request -> firstLine);
        } else {
            return UNEXPECTED_END_OF_TEXT;
        }

        // parses headers
        cut(headersString, HTTP_STARTBODY_SEPARATOR, &bodyString);
        if (headersString != NULL){
            parseHeaders(headersString, request -> headers);
        }

        // parses body.
        if (bodyString != NULL){
            parseBody(bodyString, request);
        } else {
            request ->body = UNKNOWN_TEXT;
        }


    }
}

// write forgeResponse function
char *forgeResponse(HttpMsg *response){

    // TODO

}
