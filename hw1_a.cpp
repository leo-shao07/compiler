#include <iostream>
#include <list>
#include <stdlib.h>
#include <vector>

using namespace std;

vector <string> word;
vector <string> category;
int index = 0;
string ans = "";
bool isError = false;

void Program();
void Stmts();
void Stmt();
void Primary();
void Primary_tail();

int main() {
    string temp_line,input,temp_num;
    

    while(cin) {
        getline(cin, temp_line);
        input += temp_line;
        input += "\n";
    };
    //cout << input << endl;

    for (int i = 0; i < input.size(); i++){
        if(input[i]==40){
            word.push_back("(");
            category.push_back("LBR");
        }
        else if(input[i] == 32){

        }
        else if(input[i]==41){
            word.push_back(")");
            category.push_back("RBR");
        }
        else if(input[i] == 46){
            word.push_back(".");
            category.push_back("DOT");
        }
        else if(input[i] == 34){
            string temp = "";
            temp+= "\"";
            i++;
            while(input[i]!=34){
                //cout << input[i] << endl;
                if(input[i]==10){
                    isError = true;
                    break;
                }
                temp+=input[i];
                i++;
            }
            temp += "\"";
            word.push_back(temp);
            category.push_back("STRLIT");
            //i--;
        }
        else if(input[i]>=65 && input[i]<=90 ||
                input[i]>=97 && input[i]<=122 ||
                input[i]==95){
            string temp = "";
            temp+=input[i];
            i++;
            while(input[i]>=65 && input[i]<=90 ||
                  input[i]>=97 && input[i]<=122 ||
                  input[i]>=48 && input[i]<=57 ||
                  input[i]==95){
                temp+=input[i];
                i++;
            }
            i--;
            word.push_back(temp);
            category.push_back("ID");
        }
        else if(input[i]==10){

        }
        else{
            isError = true;
            //cout << input[i] << endl;
        }
    }

    if(isError==true){
        cout << "invalid input" << endl;
    }
    else{
        /*for(int i = 0;i<word.size();i++){
            cout << category[i] << " " << word[i] << endl;
        }*/
        Program();
        if(isError==true){
            cout << "invalid input" << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    
    return 0;
}

void Program() {
  Stmts();
}

void Stmts(){
    if(index >= category.size()){
        return;
    }
    else{
        Stmt();
        Stmts();
    }
}

void Stmt(){
    //cout << "1\n";
    if(category[index] == "STRLIT"){
        //cout << category[index] << " " << word[index] << endl;
        ans = ans + category[index] + " " + word[index] + "\n";
        index++;
    }
    else if(category[index] == "ID"){
        //return;
        Primary();
    }
    else{
        //Primary();
        return;
    }
}

void Primary(){
    //cout << "2\n";
    /*if(category[index] != "ID"){
            isError = true;
    }*/
    //cout << category[index] << " " << word[index] << endl;
    ans = ans + category[index] + " " + word[index] + "\n";
    index++;
    Primary_tail();
}

void Primary_tail(){
    //cout << "3\n";
    if(index >= category.size()){
        return;
    }
    else if(category[index] == "DOT"){
        //cout << category[index] << " " << word[index] << endl;//dot
        ans = ans + category[index] + " " + word[index] + "\n";
        index++;
        /*if(category[index] != "ID"){
            isError = true;
        }*/
        //cout << category[index] << " " << word[index] << endl;//id
        ans = ans + category[index] + " " + word[index] + "\n";
        index++;
        Primary_tail();
    }
    else if(category[index] == "LBR"){
        //cout << category[index] << " " << word[index] << endl;//l
        ans = ans + category[index] + " " + word[index] + "\n";
        index++;
        Stmt();
        /*if(category[index] != "RBR"){
            isError = true;
        }*/
        //cout << category[index] << " " << word[index] << endl;//r
        ans = ans + category[index] + " " + word[index] + "\n";
        index++;
        Primary_tail();
    }
    else{
        return;
    }
}