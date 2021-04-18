#include <stdlib.h>
#include "http.h"

HashTable *METHODS;
Status *STATUSES[NUM_OF_STATUSES];
char *HEADER_NAMES[NUM_OF_HEADERS];

// call this before calling any other function of this library
void initHttpStructures(){

    // initialize METHODS
    // TODO: add other methods when they are implemented (original specification required only GET and HEAD)
    METHODS = newHashTable();
    addToHashTable(METHODS, "GET", GET);
    addToHashTable(METHODS, "HEAD", HEAD);

    // initialize STATUSES

    // success
    STATUSES[OK] = newStatus();
    STATUSES[OK] -> code = 200;
    STATUSES[OK] -> name = "OK";

    STATUSES[CREATED] = newStatus();
    STATUSES[CREATED] -> code = 201;
    STATUSES[CREATED] -> name = "Created";

    // client side errors
    STATUSES[BAD_REQUEST] = newStatus();
    STATUSES[BAD_REQUEST] -> code = 400;
    STATUSES[BAD_REQUEST] -> name = "Bad Request";

    STATUSES[FORBIDDEN] = newStatus();
    STATUSES[FORBIDDEN] -> code = 403;
    STATUSES[FORBIDDEN] -> name = "Forbidden";

    STATUSES[NOT_FOUND] = newStatus();
    STATUSES[NOT_FOUND] -> code = 404;
    STATUSES[NOT_FOUND] -> name = "Not Found";

    STATUSES[METHOD_NOT_ALLOWED] = newStatus();
    STATUSES[METHOD_NOT_ALLOWED] -> code = 405;
    STATUSES[METHOD_NOT_ALLOWED] -> name = "Method Not Allowed";

    // server side errors
    STATUSES[INTERNAL_SERVER_ERROR] = newStatus();
    STATUSES[INTERNAL_SERVER_ERROR] -> code = 500;
    STATUSES[INTERNAL_SERVER_ERROR] -> name = "Internal Server Error";

    STATUSES[NOT_IMPLEMENTED] = newStatus();
    STATUSES[NOT_IMPLEMENTED] -> code = 501;
    STATUSES[NOT_IMPLEMENTED] -> name = "Not Implemented";

    // initialize HEADER_NAMES
    HEADER_NAMES[ACCEPT] = "Accept";
    HEADER_NAMES[CONTENT_TYPE] = "Content-Type";

}

StatusLine *newStatusLine(){

    return calloc(1, sizeof(StatusLine));
}

StartLine *newStartLine(){

    return calloc(1, sizeof(StartLine));
}

// Creates a new HTTP request
HttpMsg *newHttpRequest(){

    HttpMsg *request = calloc(1, sizeof(HttpMsg));
    StartLine *startLine = newStartLine();
    request -> firstLine = startLine;
    request -> headers = newHashTable();
    return request;
}

// Creates a new Http response
HttpMsg *newHttpResponse(){

    HttpMsg *response = calloc(1, sizeof(HttpMsg));
    StatusLine *statusLine = newStatusLine();
    response -> firstLine = statusLine;
    response -> headers = newHashTable();
    return response;
}

// Destroys http message structure
void destroyHttpMsg(HttpMsg *self){

    free(self -> firstLine);
    destroyHashTable(self -> headers);
    free(self);
}

void destroyStatusLine(StatusLine *self){
    free(self);
}

void destroyStartLine(StartLine *self){
    free(self);
}

Status *newStatus(){
    return calloc(1, sizeof(Status));
}

void destroyStatus(Status *self){
    free(self);
}

void destroyHttpStructures(){

    // destroys METHODS
    destroyHashTable(METHODS);

    // destroys STATUSES
    for (int i = 0; i < NUM_OF_STATUSES; i ++){
        destroyStatus(STATUSES[i]);
    }

}
