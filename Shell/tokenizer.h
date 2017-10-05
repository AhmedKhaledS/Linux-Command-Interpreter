#ifndef TOKENIZER_H_INCLUDED
#define TOKENIZER_H_INCLUDED

int sizeOfWords;
char** normalizedCommand;
char** normalize(char* line);
int getNumberOfWords();

#endif // TOKENIZER_H_INCLUDED
