/*
    Structs and functions suitable for HTTP 1.1
*/

#ifndef HTTP_H_INCLUDED
#define HTTP_H_INCLUDED

#include "hTable.h"

//TODO: move these constants in parser header file
#define HTTP_LINE_SEPARATOR '\n'
#define HTTP_STARTBODY_SEPARATOR "\n\n"
#define HTTP_WORD_SEPARATOR ' '

// request methods
typedef enum {

    GET,        // requests a representation of the specified resource
    POST,       // used to submit an entity to the specified resource
    OPTIONS,    // used to describe the communication options for the target resource.
    HEAD,       // asks for a response identical to that of a GET request, but without the response body.
    PUT,        // replaces all current representations of the target resource with the request payload.
    DELETE,     // deletes the specified resource.
    TRACE,      // performs a message loop-back test along the path to the target resource.
    CONNECT,    // establishes a tunnel to the server identified by the target resource.
    NUM_OF_METHODS

} Method;

extern HashTable *METHODS;   // name-Method pairs

// response status codes
// TODO: expand this list with further codes if needed
typedef enum {

    // success
    OK,             // target found, serving it
    CREATED,        // Target not found, served after creation

    // Client side errors
    BAD_REQUEST,    // Malformed client request
    FORBIDDEN,      // target found, forbidden access to client
    NOT_FOUND,      // target not found
    METHOD_NOT_ALLOWED,  // Method used by client is not supported for target resource

    // Server side errors
    INTERNAL_SERVER_ERROR,   // Generic error
    NOT_IMPLEMENTED,     // The server either does not recognize the request method, or it lacks the ability to fulfil the request. Usually this implies future availability

    NUM_OF_STATUSES


} StatusCode;

// response status
typedef struct {

    unsigned code;   // status numeric code
    char *name;       // status name

} Status;

extern Status* STATUSES[NUM_OF_STATUSES];   // Names and numeric codes of statuses.

// headers
// TODO: add new headers if needed
typedef enum {

    ACCEPT,             // Which content the client is able to understand
    CONTENT_TYPE,       // Media type of resource
    NUM_OF_HEADERS

} Header;

extern char* HEADER_NAMES[NUM_OF_HEADERS];   // Names of headers.

// Use this as first line for requests
typedef struct {

    Method method;      // GET, POST, ...
    char *url;       // URL of targeted resource
    char *httpVersion;   // Version of protocol http in use

} StartLine;

// Use this as first line for responses
typedef struct {

    char *httpVersion;   // Version of protocol http in use
    StatusCode code;    // Status code

} StatusLine;

// Generic http message
// TODO: write structures for multi part body
typedef struct {

    char* firstLine;         // must be one between StatusLine and StartLine
    HashTable *headers;      // Holds pairs of header-value
    char *body;              // Body of http message, if present

} HttpMsg;

// Creates new status struct
Status* newStatus();

// destroy status struct
void destroyStatus(Status *self);

// Creates a new HTTP request
HttpMsg *newHttpRequest();

// Creates a new Http response
HttpMsg *newHttpResponse();

// Destroys http message structure
void destroyHttpMsg(HttpMsg *self);

// Initializes structures and constants needed for other functions to work
void initHttpStructures();

// call this when you don't need these functions anymore
void destroyHttpStructures();

#endif // HTTP_H_INCLUDED
