#include <iostream>

using namespace std;

int main() {
    string temp_line,input,temp_num;
    bool isBuffer = false;

    while(cin) {
        getline(cin, temp_line);
        input += temp_line;
    };
    //cout << input << endl;

    for (int i = 0; i < input.size(); i++){
        if(input[i] >= 48 && input[i] <= 57){
            isBuffer= true;
            temp_num += input[i];
        }
        else{
            if(isBuffer == true){
                cout << "NUM " << temp_num << endl;
                temp_num = "";
                isBuffer = false;
            }
            

            if(input[i] == '(') cout << "LPR\n";
            else if(input[i] == ')') cout << "RPR\n";
            else if(input[i] == '+') cout << "PLUS\n";
            else if(input[i] == '-') cout << "MINUS\n";
            else if(input[i] == '*') cout << "MUL\n";
            else if(input[i] == '/') cout << "DIV\n";
            else if(input[i] == ' '){
            }
        }
    }
    if(isBuffer == true){
        cout << "NUM " << temp_num << endl;
    }
    return 0;
}