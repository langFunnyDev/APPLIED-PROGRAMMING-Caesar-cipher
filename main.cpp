#include <iostream>

char encrypt(char stringSymbol, int key){     // Функция шифрования
    return char ( int(stringSymbol) + key );
}

char decrypt(char stringSymbol, int key){     // Функция дешифрования
    return char ( int(stringSymbol) - key );
}

int main() {
    std::string inputString;                   // Входная строка
    std::string outputString;                  // Выходная строка
    int key, mode;                             // Переменные управления состоянием

    std::cout << "Hello, please select one of the following operating modes !" << std::endl
    << "1. Encrypt the string" << std::endl
    << "2. Decrypt the string" << std::endl
    << "Enter mode number: ";
    std::cin >> mode;                          // Ввод пользователем выбранного режима работы

    switch (mode) {                            // Управление потоком выполнения
        case 1:
            std::cout << std::endl << "You're selected encryption mode." << std::endl
            << "Please enter your unencrypted string and key (a count of offset symbols)" << std::endl
            << "Separating the string and key with a space" << std::endl << "Enter here: ";
            std::cin >> inputString >> key;    // Ввод строки нешифрованного сообщения и ключа шифрования

            for (int i = 0; i < inputString.length(); i++){ // Процесс посимвольного шифрования сообщения
                outputString += encrypt(inputString[i], key);
            }

            std::cout << "You're encrypted string: " << outputString << std::endl // Вывод шифрованной строки
            << " You're decryption key: " << key << std::endl;

            break;
        case 2:
            std::cout << std::endl << "You're selected decryption mode." << std::endl
                      << "Please enter your encrypted string and key" << std::endl
                      << "Separating the string and key with a space" << std::endl
                      << "Enter here: ";
            std::cin >> inputString >> key;    // Ввод строки шифрованного сообщения и ключа дешифровки

            for (int i = 0; i < inputString.length(); i++){ // Процесс посимвольного дешифрования сообщения
                outputString += decrypt(inputString[i], key);
            }

            std::cout << "You're decrypted string: " << outputString << std::endl; // Вывод дешифрованной строки
            break;
        default: // Отработка ошибки ввода
            std::cout << "You're entered wrong number of mode !";
            break;
    }

    return 0;
}
