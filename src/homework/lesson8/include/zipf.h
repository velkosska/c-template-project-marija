#ifndef ZIPF_H
#define ZIPF_H

void readBook(const char* fileName, char** contents);
void countWords(const char* book, char*** words, int** frequencies, int* nWords);

#endif
