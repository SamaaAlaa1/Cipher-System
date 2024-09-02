#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include<algorithm>

using namespace std;
void first_menu(){
    cout<<"Hello to our encryption and decryption program\n";
    cout<<"please enter your choice:"<<endl;
    cout<<"1-cipher a message\n2-decipher a message\n3-exit\n";
}
void cipher_options(){
    cout<<"Enjoy encrypting messages.....\n";
    cout<<"choose a method to use in encrypting:\n";
    cout<<"1-Affine cipher\n2-Simple substitution\n3-morse code\n4-Exit\n";
}
void decipher_options(){
    cout<<"Enjoy dencrypting messages.....\n";
    cout<<"choose a method to use in dencrypting:\n";
    cout<<"1-Affine cipher\n2-Simple substitution\n3-morse code\n4-Exit\n";
}string cipher_simple(){
    cout<<"---------Welcome---------\nHello to our simple substitution cipher method to encrypt a message"<<endl;
    char plain_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q','r', 's', 't', 'u', 'v', 'w', 'x', 'y','z' };
    string cipher_alphabet;
    string key;
    cout<<"Enter the key to use in encryption:\n";
    cin>>key;
    while(true){
        bool repeated = false;   //check the repeated characters in the key
        for(int c=0; c < key.length(); c++){
            for(int t = c+1; t< key.length(); t++){
                if(key[c] == key[t]){
                    repeated = true;
                    break;
                }
            }
        }if(repeated){    //handle the repeated characters
            cout <<"the key should not have repeated characters"<<endl;
            cout<<"Enter the key to use in encryption:\n";
            cin>>key;     //retake the input because of invalidation
        }
        else{
            break;
        }
    }
    while(true){

        bool invalid = false;   //check if the key is only containing english letters
        for(char c :key){
            if(!isalpha(c)){
                invalid = true;
                break;
            }
        }
        if(invalid|| key.length() != 5){         //check the length of the key
            cout<<"invalid input please try again"<<endl;
            if(key.length() != 5){
                cout<<"the key should equal 5 characters\n";
            }
            cout<<"Enter the key to use in encryption:\n";
            cin>>key;     //retake the input because of invalidation
        } else{
            break;     //in case of the input is valid and it is handle the infinite loop
        }
    }
    for (char c :key) {
        if(isalpha(c)){
            c = tolower(c);
            if(cipher_alphabet.find(c) == string::npos){
                cipher_alphabet += c;
            }
        }

    }
    for(char i :plain_alphabet){
        if(cipher_alphabet.find(i) == string::npos){
            cipher_alphabet += i;
        }
    }
    string message;
    cin.ignore();
    cout<<"Enter the message to encrypt:\n";
    getline(cin, message);
    string encrypted_message = "";
    for(char c :message ){
        if(isalpha(c)){
            c = tolower(c);
            if(c >= 'a'&& c <= 'z'){
                size_t index = c - 'a';
                encrypted_message += cipher_alphabet[index];
            }}else{
            encrypted_message += c;
        }
    }cout<<"the encrypted message:"<<encrypted_message;
    cout<<endl;
    return encrypted_message;
}string decipher_simple(){
    cout<<"-----------------Welcome-----------------\nHello to our simple substitution cipher method to decrypt a message"<<endl;
    string key;
    cout<<"Enter the key to use in decryption:\n";
    cin>>key;
    for(char & c :key){
        c = tolower(c);
    }
    while(true){   //check repeated letters
        bool repeated = false;
        for(int c=0; c < key.length(); c++){
            for(int t = c+1; t< key.length(); t++){
                if(key[c] == key[t]){
                    repeated = true;
                    break;
                }
            }
        }if(repeated){    //handle repeated letters
            cout <<"the key should not have repeated characters"<<endl;
            cout<<"Enter the key to use in encryption:\n";
            cin>>key;     //retake the input because of invalidation
        }
        else{
            break;
        }
    }
    while(true){
        bool invalid = false;
        if(key.length() != 5){   //check the key length
            invalid = true;
            cout<<"the key should equal 5 characters please try again\n";
        }else{
            for (char c: key ) {
                if(!isalpha(c)){
                    invalid = true;
                    cout<<"invalid input try again\n";
                    break;
                }

            }
        }
        if(!invalid){
            break;
        }else{
            cout<<"Enter the key to use in decryption:\n";
            cin>>key;
            for(char & c :key){
                c = tolower(c);
            }
        }
    }

    string cipher_alphabet;
    char plain_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q','r', 's', 't', 'u', 'v', 'w', 'x', 'y','z' };
    for(char c : key){
        cipher_alphabet += c;
    }
    for(char t :plain_alphabet){
        if(cipher_alphabet.find(t) == string::npos){
            cipher_alphabet += t;
        }
    }
    string encrypted_message;
    string decrypted_message = "";
    cin.ignore();
    cout<<"Enter the encrypted message to decrypt:\n";
    getline(cin, encrypted_message);
    for(char & i :encrypted_message){
        i = tolower(i);
    }
    for(char i :encrypted_message){
        size_t index = cipher_alphabet.find(i);
        if(index != string::npos){
            decrypted_message += plain_alphabet[index];
        }else{
            decrypted_message += i;
        }
    }cout<<"the decrypted message: "<<decrypted_message;
    cout<<endl;
    return decrypted_message;
}
bool is_morse(string s){
    for(char c : s) {
        if(c != '.' && c != '-' && c != ' ') {
            return false;
        }
    }
    return true;
}
void cipher_morse() {
    //function that check if the string is morse code or not//English characters and numbers and special characters from @ to _
    string morse_code[] = {
            //English characters (65:90)
            ".-", "-...", "-.-.", "-..", ".", "..-.",
            "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--..",
            //numbers (48:57)
            "-----", ".----", "..---", "...--", "....-", ".....",
            "-....", "--...", "---..", "----."};
    string special_morse[] = {".--.-.", //@ (64)
            //Special characters from [ to _ (91:95)
                              "-.--.", "-...-.", "-.--.-", "...--..", "..--.-",
            // from ! to / (33:47)
                              "-.-.--", ".-..-.", "----- .-.-. -----",
                              "...-.-.", ".-.-.- .-.-.-", ".-.-.-", ".----.", "-.-.-",
                              "-.-.-.", ".-.-.", ".-.-.", "--..--", "-....-", ".-.-.-",
                              "-..-.",
            //from : to ?  (58:63)
                              "---...", "-.-.-.", "-.-.-",
                              "-...-", "..-.", "..--.."};
    //English to morse
    bool cipher = true;
    while (cipher) {
        string str;
        cout << "Enter the message to encrypt: ";
        cin.ignore();
        getline(cin, str);
        if (!is_morse(str)) {
            for (int i = 0; i < str.length(); i++) {
                if (str[i] == ' ') {                          //convert form english to morse using ASCii value
                    cout << "   ";
                } else {
                    char element = toupper(str[i]);
                    if (element >= 65 && element <= 90) {
                        cout << morse_code[element - 65] << " ";
                    } else if (element == 64) cout << special_morse[0] << " ";
                    else if (element >= 48 && element <= 57) {
                        cout << morse_code[element - 48 + 26] << " ";
                    } else if (element >= 91 && element <= 95) {
                        cout << special_morse[element - 91 + 1] << " ";
                    } else if (element >= 33 && element <= 47) {
                        cout << special_morse[element - 33 + 6] << " ";
                    } else if (element >= 58 && element <= 63) {
                        cout << special_morse[element - 58 + 21] << " ";
                    } else {
                        cout << "Not Valid!!";
                        break;
                    }
                }
            }
        } else {  //handle validation
            cout << "Error!!:This message is incorrect\n";
            continue;
        }
        while (true) {  //ask the user ti input again or exit program
            char choice;
            cout << "\n1 => Cipher Again\n2 => Exit\n";
            cin >> choice;
            if (choice == '1') {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            } else if (choice == '2') {
                cipher = false;
                break;
            } else {
                cout << "Invalid input. Please enter 1 or 2.\n";   //handle validation
            }
        }
    }
}
void decipher_morse(){
//English characters and numbers and special characters from @ to _
    string morse_code[] = {
            //English characters (65:90)
            ".-", "-...", "-.-.", "-..", ".", "..-.",
            "--.", "....", "..", ".---", "-.-", ".-..",
            "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-",
            "-.--", "--..",
            //numbers (48:57)
            "-----", ".----", "..---", "...--", "....-", ".....",
            "-....", "--...", "---..", "----.",".--.-.", // @ (64)
            //Special characters from [ to _ (91:95)
            "-.--.", "-...-.", "-.--.-", "...--..", "..--.-",
            // from ! to / (33:47)
            "-.-.--", ".-..-.", "----- .-.-. -----", "...-.-.", ".-.-.- .-.-.-", ".-.-.-",
            ".----.", "-.-.-", "-.-.-", "--..--", "-....-", ".-.-.-", "-..-.",
            //from : to ?  (58:63)
            "---...", "-.-.-.", "-.-.-", "-...-", "..-.", "..--.."
    };
    bool decipher = true;
    while(decipher){
        string str;  //take morse code as input
        cout << "Enter your Morse code: ";
        cin.ignore();
        getline(cin, str);
        size_t start = 0;
        string english = "";
        bool spaceFlag = false;     //Handle spaces
        if(is_morse(str)){
            while (start < str.length()) {
                size_t end = str.find(' ', start);
                if (end == string::npos) {
                    end = str.length();
                }
                string temp = str.substr(start, end - start);
                //if it's empty then it's a space
                if (temp.empty()) {
                    if (!spaceFlag) {
                        english += ' '; // Add space for word separation
                        spaceFlag = true;
                    }
                } else {
                    // If temp is not empty then it's Morse code
                    if (spaceFlag) {
                        spaceFlag = false; // Reset flag
                    }
                    //set every char to temp to convert it to english
                    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
                    bool found = false;
                    // Check for English characters and numbers
                    for (int j = 0; j < 36; j++) {
                        if (temp == morse_code[j]) {
                            if (j <= 25) {
                                english += char(j + 65); // Convert to uppercase English character
                            } else if (j >= 26 && j <= 35) {
                                english += char(j - 26 + 48); // Convert to numbers
                            }
                            found = true;
                            break;
                        }
                    }
                    // Check for special characters
                    if (!found) {
                        if (temp == morse_code[36]) {
                            english += "@";
                            found = true;
                        } else {
                            for (int j = 37; j <= 66; j++) {
                                if (temp == morse_code[j]) {
                                    if (j >= 37 && j <= 41) {
                                        english += char(j - 37 + 91);
                                        found = true;
                                        break;
                                    }
                                    if (j >= 42 && j <= 54) {
                                        english += char(j - 42 + 33);
                                        found = true;
                                        break;
                                    }
                                    if (j >= 55 && j <= 63) {
                                        english += char(j - 55 + 58);
                                        found = true;
                                        break;
                                    }
                                }
                            }}
                    }
                    //handle validation
                    if (!found) {
                        cout << "Invalid Morse code: " << temp << endl;
                    }
                }
                start = end + 1;
            }
            cout << "Decoded message: " << english <<endl;
            while (true) {  //ask the user ti input again or exit program
                char choice;
                cout << "\n1 => Decipher Again\n2 => Exit\n";
                cin >> choice;
                if (choice == '1') {cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                } else if (choice == '2') {
                    decipher = false;
                    break;
                } else {
                    cout << "Invalid input. Please enter 1 or 2.\n";   //handle validation
                }
            }
        }
        else{
            cout << "Error!!:Invalid \n";
            continue;
        }
    }
}
string cipher_decipheraffine(){

    int a, b, c;
    string text;
    bool encrypt = false; // new variable to control encryption or decryption

    cout << "attention !!!!! "
         << " a, b, c are arbitrary positive integers that satisfy the condition (a * c) mod 26 = 1 if not code will not worke correctly " << endl;
    cout << " a : ";
    cin >> a;
    cout << " b : ";
    cin >> b;
    cout << " c : ";
    cin >> c;
    cout << " text you want to encrypt or decrypt : ";
    cin >> text;

    // get user input if he want to  encrypt or decrypt
    cout << " for encrypt press (E) or for decrypt press (D) and hit enter ";
    char flag;
    cin >> flag;

    if (flag == 'D') // check if user press D
    {
        encrypt = false; // set encrypt to false for decryption
    }
    else if (flag == 'E') // check if user press E
    {
        encrypt = true; // set encrypt to true for encryption
    }
    else // for invalid inputs
    {
        cout << "please choose invalid choise ,for encrypt press (E) or for decrypt press (D)  " << endl;
        return 0; // exit the program
    }

    string resultText = ""; // store string for result text
    for (char ch : text)
    {
        if (isalpha(ch)) // check if singel char is alphabit becase any thing is not alpha not change
        {
            int y = toupper(ch) - 'A'; // convert character to our index table
            int resultChar; // store result character

            if (encrypt) // check if encryption is true
            {
                resultChar = (a * y + b) % 26; // apply formula for encryption
            }
            else // decryption is true
            {
                resultChar = (c * (y - b + 26)) % 26; // apply formula for decryption
            }

            resultText += char(resultChar + 'A'); // return index back to character to convert the numeric to the value of the real char to display it
        }
        else
        {
            resultText += ch; // unchanged not alpha chars
        }
    }

    cout << "result_text : " << resultText << endl; // display final output

    return 0;
}

using namespace std;
int first_choice;
int cipher_choice;
int decipher_choice;
int main(){
    first_menu();
    cout<<"Enter your choice:"<<endl;
    cin>>first_choice;
    while(true){
        if(first_choice == 1){
            cipher_options();
            cout<<"Enter your choice:"<<endl;
            cin>>cipher_choice;
            while(true){
                if(cipher_choice == 1){
                    cipher_decipheraffine();
                }else if(cipher_choice == 2){
                    cipher_simple();
                }else if (cipher_choice == 3){
                    cipher_morse();
                }else if(cipher_choice == 4){
                    cout<<"exiting program.......\n";
                    break;
                }else{
                    cout<<"invalid choice try again\n";
                }cipher_options();
                cout<<"Enter your choice:"<<endl;
                cin>>cipher_choice;
            }}else if(first_choice == 2){
            decipher_options();
            cout<<"Enter your choice:"<<endl;
            cin>>decipher_choice;
            while(true){
                if(decipher_choice == 1){
                    cipher_decipheraffine();
                }else if(decipher_choice == 2){
                    decipher_simple();
                }else if(decipher_choice == 3){
                    decipher_morse();
                }else if(decipher_choice == 4){
                    cout<<"exciting program........"<<endl;
                    break;
                }else{
                    cout<<"invalid choice please try again\n";

                }decipher_options();
                cout<<"Enter your choice:"<<endl;
                cin>>decipher_choice;
            }
        }else if(first_choice == 3){
            cout<<"exciting the program........\n";
            break;
        }else{
            cout<<"invalid choice please try again\n";
        }first_menu();
        cout<<"Enter your choice:"<<endl;
        cin>>cipher_choice;
    }

}