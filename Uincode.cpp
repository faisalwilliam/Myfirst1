// MessageBoxB.cpp // Detta program kan inte kompileras i
 // Visual Studio. Kör det i Borland C++
// Skriver ut text till en MessageBox (meddelanderuta)
// Anrop av funktionen MessageBox() som är definierad i
// biblioteket windows.h och har fyra parametrar
#include <windows.h> // Krävs för funktionen MessageBox()
int main()
{
 MessageBox(NULL,
 "Detta är en MessageBox från C++.",
 "Meddelande",
 NULL);
 MessageBox(NULL,
 "Texten har delats upp \n i två rader.",
 "Information",
 MB_ICONINFORMATION);
 MessageBox(NULL,
 "Är det bra väder idag?",
 "Fråga",
 MB_YESNO | MB_ICONQUESTION);
}