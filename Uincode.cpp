// MessageBoxB.cpp // Detta program kan inte kompileras i
 // Visual Studio. K�r det i Borland C++
// Skriver ut text till en MessageBox (meddelanderuta)
// Anrop av funktionen MessageBox() som �r definierad i
// biblioteket windows.h och har fyra parametrar
#include <windows.h> // Kr�vs f�r funktionen MessageBox()
int main()
{
 MessageBox(NULL,
 "Detta �r en MessageBox fr�n C++.",
 "Meddelande",
 NULL);
 MessageBox(NULL,
 "Texten har delats upp \n i tv� rader.",
 "Information",
 MB_ICONINFORMATION);
 MessageBox(NULL,
 "�r det bra v�der idag?",
 "Fr�ga",
 MB_YESNO | MB_ICONQUESTION);
}