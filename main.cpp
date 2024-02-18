#include <iostream>
#include <string>

using namespace std;

// Función para cifrar un texto utilizando el cifrado César
string cifrar(string texto, int clave) {
    string textoCifrado = "";

    // Iterar sobre cada carácter del texto
    for (char &c : texto) {
        if (isalpha(c)) { // Verificar si el carácter es una letra del alfabeto
            char base = isupper(c) ? 'A' : 'a'; // Determinar la base del alfabeto (mayúscula o minúscula)
            c = (c - base + clave) % 26 + base; // Aplicar el cifrado César a la letra
        }
        textoCifrado += c; // Agregar el carácter cifrado al texto cifrado
    }

    return textoCifrado; // Devolver el texto cifrado
}

// Función para descifrar un texto cifrado utilizando el cifrado César
string descifrar(string textoCifrado, int clave) {
    string textoDescifrado = "";

    // Iterar sobre cada carácter del texto cifrado
    for (char &c : textoCifrado) {
        if (isalpha(c)) { // Verificar si el carácter es una letra del alfabeto
            char base = isupper(c) ? 'A' : 'a'; // Determinar la base del alfabeto (mayúscula o minúscula)
            c = (((c - base) - clave + 26) % 26) + base; // Aplicar el descifrado César a la letra
        }
        textoDescifrado += c; // Agregar el carácter descifrado al texto descifrado
    }

    return textoDescifrado; // Devolver el texto descifrado
}

// Función principal
int main() {
    string textoOriginal;
    int clave = 19;

    // Solicitar al usuario que ingrese el texto a cifrar
    cout << "Ingrese el texto a cifrar:";
    cin >> textoOriginal;

    // Cifrar el texto utilizando la clave especificada
    string textoCodificado = cifrar(textoOriginal, clave);
    cout << "Texto codificado: " << textoCodificado << endl;

    // Descifrar el texto cifrado utilizando la misma clave
    string textoDescodificado = descifrar(textoCodificado, clave);
    cout << "Texto descodificado: " << textoDescodificado << endl;

    return 0;
}
