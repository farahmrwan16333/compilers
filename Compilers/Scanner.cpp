#include "Scan.h"



/* putting all the reserved words in a map */
map<string, string> reserved = { {"if", "IF"},
                                 {"then", "THEN"},
                                 {"else", "ELSE" },
                                 {"end" , "END"},
                                 {"repeat" , "REPEAT"},
                                 {"until" , "UNTIL"},
                                 {"read" , "READ"},
                                 {"write" , "WRITE"} };
queue<Token> scanned;
Token token;


string reservedWords(string s) {
    return reserved[s];
}


/* Convert the input file to string */
/*string convert_file_to_string(string& str, string fileName) {

    ifstream myfile(fileName);

    str = string((istreambuf_iterator<char>(myfile)), std::istreambuf_iterator<char>());

    myfile.close();

    return str;
}
*/
void addToken(string& scanned_character, string tokenValue)
{
    token.value = scanned_character;
    token.type = tokenValue;
    scanned_character = "";
    scanned.push(token);
}

/* Convert the string to tokens */
queue<Token>* scanning(string &in_string) {
    string scanned_character = "";


    for (int i = 0; i < in_string.length(); i++) {

        /* check if the characters of the string is an alphabetic letter */
        if (isalpha(in_string[i])) {

            while (isalpha(in_string[i])) {
                scanned_character += in_string[i];
                i++;
                if (!reservedWords(scanned_character).empty()) {
                    token.type = reservedWords(scanned_character);
                    break;
                }

                if (!isalpha(in_string[i])) {
                    token.type = "IDENTIFIER";
                    break;
                }
            }
            //look ahead character
            i--;
            token.value = scanned_character;
            scanned_character = "";
            scanned.push(token);
        }
            /* Check if the character of the string is a number */
        else if (isdigit(in_string[i])) {
            while (isdigit(in_string[i])) {
                scanned_character += in_string[i];
                i++;
            }
            i--;
            addToken(scanned_character, "NUMBER");

        }
        else if (isspace(in_string[i])) {
            continue;
        }
            /* Check Comments */
        else if (in_string[i] == '{') {
            while (in_string[i] != '}') {
                i++;
            }
        }
            /* Check assignment of value */
        else if (in_string[i] == ':' && in_string[i + 1] == '=') {
            token.value = ":=";
            token.type = "ASSIGN";
            scanned.push(token);
            i++;
        }
            /* Check if the character of the string is any arithmetic operation */
        else if (in_string[i] == '+') {
            scanned_character += in_string[i];
            addToken(scanned_character, "PLUS");
        }
        else if (in_string[i] == '-') {
            scanned_character += in_string[i];
            addToken(scanned_character, "MINUS");
        }
        else if (in_string[i] == '/') {
            scanned_character += in_string[i];
            addToken(scanned_character, "DIV");

        }
        else if (in_string[i] == '*') {
            scanned_character += in_string[i];
            addToken(scanned_character, "MULT");

        }
        else if (in_string[i] == '=') {
            scanned_character += in_string[i];
            addToken(scanned_character, "EQUAL");

        }
        else if (in_string[i] == '<') {
            scanned_character += in_string[i];
            addToken(scanned_character, "LESSTHAN");

        }
            /* Check brackets */
        else if (in_string[i] == '(') {
            scanned_character += in_string[i];
            addToken(scanned_character, "OPENBRACKET");

        }
        else if (in_string[i] == ')') {
            scanned_character += in_string[i];
            addToken(scanned_character, "CLOSEDBRACKET");

        }
            /* Check semicolon */
        else if (in_string[i] == ';') {
            scanned_character += in_string[i];
            addToken(scanned_character, "SEMICOLON");

        }
    }
    return scanned;
}


/* Convert the vector of tokens to output file */
/*void outputFile(vector<Token> s) {
    ofstream myfile;
    myfile.open("output.txt");
    int i = 0;
    while (i != s.size()) {
        myfile << s[i].type << "\t" << s[i].value << "\n";
        i++;
    }
    myfile.close();
}
*/


