#ifndef RES_H
#define RES_H

typedef struct {
	char* basePath;
	char* baseResourcePath;

}IoData;

char* getBasePath(void);
char* getResourcePath(const char* subDir);


void freeIoData(IoData* data);
IoData* initIoData(void);
#endif