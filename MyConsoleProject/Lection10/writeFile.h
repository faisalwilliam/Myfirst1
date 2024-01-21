#pragma once
// writeFile.h
// Funktion som skriver texten t bestående av antal
// tecken till filen fileName
void writeFile(char t[], string fileName, int antal)
{
	ofstream fileForWrite(fileName);
	for (int i = 0; i < antal; i++)
		fileForWrite << t[i];
	fileForWrite.close();
}