// LoginCpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

const string USERS_FILE = "users.txt";

unordered_map<string, string> loadUsers() {
    unordered_map<string, string> users;
    ifstream file(USERS_FILE);
    if (file.is_open()) {
        string username, password;
        while (file >> username >> password) {
            users[username] = password;
        }
        file.close();
    }
    return users;
}

void saveUser(const string& username, const string& password) {
    ofstream file(USERS_FILE, ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
    }
}

bool authenticateUser(const string& username, const string& password, const unordered_map<string, string>& users) {
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }
    return false;
}

void registerUser(unordered_map<string, string>& users) {
    string username, password;
    cout << "Ingrese un nombre de usuario: ";
    cin >> username;
    cout << "Ingrese una contrasenia: ";
    cin >> password;

    if (users.find(username) != users.end()) {
        cout << "El usuario ya existe. Intente otro nombre de usuario." << endl;
    }
    else {
        users[username] = password;
        saveUser(username, password);
        cout << "Usuario registrado exitosamente." << endl;
    }
}

void loginUser(const unordered_map<string, string>& users) {
    string username, password;
    cout << "Ingrese su nombre de usuario: ";
    cin >> username;
    cout << "Ingrese su contrasenia: ";
    cin >> password;

    if (authenticateUser(username, password, users)) {
        cout << "Inicio de sesión exitoso." << endl;
    }
    else {
        cout << "Nombre de usuario o contraseña incorrectos." << endl;
    }
}

int main() {
    unordered_map<string, string> users = loadUsers();
    int choice;

    while (true) {
        cout << "1. Registrarse" << endl;
        cout << "2. Iniciar sesion" << endl;
        cout << "3. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;

        switch (choice) {
        case 1:
            registerUser(users);
            break;
        case 2:
            loginUser(users);
            break;
        case 3:
            return 0;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
        }
    }
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
