/* SECRET LIBRARY -by Paul Hasfjord
* 
*/
#define MAX_FILES_SIZE 850

int encode(const char *inputMessageFile, const char *keyFile, char *encodedStream);
int decode2(const char *inputCodeFile, const char *keyFile, char *decodedMessage);

