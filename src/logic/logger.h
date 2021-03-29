#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#define MSG_MAX_LEN 1024

enum Tag {I, W, E, D};

// prints msg on screen with given tag. Except for tag, args are the same of printf
void logMsg(enum Tag tag, const char* msg, ...);

#endif // LOGGER_H_INCLUDED

