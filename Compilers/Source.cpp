
#include "Parse.h"

using namespace std;

int main()
{
    while (1) {
        queue<Token> scanned;
        string f = "";
        getline(cin, f);
        cin.ignore();
        Node* root = program(scanning(f));
    }


    return 0;
}