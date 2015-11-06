/* SECRET LIBRARY -by Paul Hasfjord
* 
*/

char *encode(const char *inputMessageFile, const char *keyFile, int *status);
/*
* Returns the char *array of encoded stream and status into the references
*/

int encode2(const char *inputMessageFile, const char *keyFile, char *encodedStream);
/*
* Returns the status and takes the reference to the encoded stream as an argument.
*/

char *decode(const char *inputCodeFile, const char *keyFile, int status);
/*
*  Returns the char *array of decoded stream and status into the references
*/
int decode2(const char *inputCodeFile, const char *keyFile, char *decodedMessage);
/*
* Returns the status and takes the reference to the decoded stream 
*/
