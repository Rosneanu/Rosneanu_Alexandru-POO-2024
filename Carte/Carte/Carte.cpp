#include "pch.h"
#include "Carte.h"

using namespace System;
ref class Carte
{
public:
        int legs;
Carte::Carte(String^ autor1, String^ editura1, int anAparitie1, int vechime1)
{
    autor = autor1;
    editura = editura1;
    anAparitie = anAparitie1;
    vechime = vechime1;
}

String^ Carte::getDetails()
{
    return String::Format("\nNume: {0}, Editura: {1}, An aparitie: {2}, Vechime: {3}", autor, editura, anAparitie, vechime);
}