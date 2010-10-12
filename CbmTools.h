//CBM - Compressed Bitmaps

unsigned long Tga2CbmA(const char *pFile);
unsigned long Tga2CbmW(const wchar_t *pFile);

unsigned int LoadCBM(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **pPixels);
unsigned int LoadTGA(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **pPixels);
unsigned int LoadPNG(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **pPixels);
unsigned int LoadHWL(const wchar_t *pFile, unsigned int *pWidth, unsigned int *pHeight, unsigned int **pPixels);