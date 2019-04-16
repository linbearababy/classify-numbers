// whatever includes you need
#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<cctype>
using std::isdigit; using std::isalpha; using std::isalnum;

// your functions here
bool valid_hex(string str) {
    char ch1, ch2;
    ch1= 'a', ch2 = 'f';
    //check the prefix
    int position = str.find("0x");
    //find the length;
    int length1 = str.length();
    // if it is positive;
    if ( position ==0) {
        //for (int i; i < str.length(); ++i) {
        int times =0;
        for (auto i : str.substr(2)) {
            if (isalpha(i) && i >= ch1 && i <= ch2){
                times +=1;
                //check each char to see if the char in (a,f) ;
            }
            if (isdigit(i) && i >='0' && i <= '9' ) {
                times +=1;
            }
        }
        //check the char to see if it is in (0-9);
        return times == (length1-2);
    }
    // if the string is a negative;
    int position2 = str.find("-");
    if (position2 == 0 && position == 1){
        int times =0;
        for (auto i : str.substr(3)) {
            if (isalpha(i) && i >= ch1 && i <= ch2) {
                times +=1;}
            else if (isdigit(i) && i >='0' && i <= '9') {
                times +=1;
            }
        }
        return times == (length1 - 3);
    }
    else {
        return false;
    }
}



bool valid_octal (string str){
    int position = str.find("0");
    int length1 = str.length();
    //if the string is positive;
    if ( position ==0) {
        int times =0;
        for (auto i :str.substr(1)) {
            if (i >='0' && i<='7'){
                times +=1;
            }

        }
        // if the size is the same,true;
        return times == (length1-1);
    }
    //if the string is negative;
    int position2 = str.find("-");
    if (position2 == 0 && position == 1){
        int times =0;
        for (auto i : str.substr(2)) {
            if (i >='0' && i<='7'){
                times +=1;
            }
        }
        // if the size is the same,true;
        return times == (length1-2); 
    }
    else {
        return false;
    }
}

bool valid_binary (string str){
    int position = str.find("0b");
    int length1 = str.length();
    if (position ==0){
        int times =0;
        for (auto i : str.substr(2)){
            if ( i == '0' || i =='1'){
                times +=1;
            }
        }
        
        /*if (times == (length1-2)){
            return true;
        }
        else {
            return false;
        }*/
        return times == (length1-2);
    }
    int position2= str.find("-");
    if (position2 ==0 && position ==1){
        int  times =0;
        for (auto i : str.substr(3)) {
            if (i == '0' || i == '1') {
                times +=1;
            }
        }
        return times==(length1 -3);
        /*if (times == (length1 -3)){
            return true;
        }
        else {
            return false;
        }*/
    }
    else {
        return false;
    }
}

bool valid_int (string str) {
    int position = str.find("-");
    int length1 = str.length();
    if (position ==0) {
        int times=0;
        for (auto i : str.substr(1)) {
            if (!isalpha(i)) {
                if (isdigit(i)) {
                    times +=1;//return true;
                }
            }
        }
        if (times == (length1-1)){
            return true;
        }
        else {
            return false;
        }
    }
    if (position !=0){
        int times=0;
        for (auto i : str) {
            //check the condiction; 
            if (isalnum(i)) {
                if (isdigit(i) && !isalpha(i)) {
                    //return true;
                    times +=1;
                }
            }
        }
        if (times == length1){
            return true;
        }
        else {
            return false;
        }

    }
    else {
        return false;
    }
}

bool valid_float(string str) {
    int position= str.find("-");
    if (position !=0 || position ==0){
        int times =0;
        int word =0;
        //for each char check if it is alpha or ".","e"
        for (auto i : str){
            if (isalpha(i) && i != 'e'){
                return false;
            }
            if (isdigit(i) || i=='.' || i=='e'){
                if (i ==  '.'){
                    
                    times +=1;
                }
                if (i == 'e'){
                    word +=1;
                }
                
            }
        }
        //check wether it  comforts the condiction
        if ((times ==1 && word ==1 ) || (times==1 && word ==0) || (times ==0 && word ==1)) {
                    return true;
            }
        else {
            return false;
        }
        
    }
        /*else {
            return false;
        }*/
    else {
        return false;
        }
}
    
string classify_string(string str){
    if (valid_hex(str) == true) {
        return "hexadecimal";
    }
    else if (valid_octal (str) ==true ){
            return "octal";
        }
    else if (valid_binary (str) == true) {
            return "binary";
        }

    else if (valid_int (str) ==true) {
            return "int";
        }
    else if (valid_float(str) == true) {
            return "float";
        }
    else {
        return "false";
    }
}

int main (){

    cout << boolalpha;
    int testnum;
    cin >> testnum;

    switch (testnum) {
        case 1 : {
            string to_test;
            cin >> to_test;
            cout << valid_hex(to_test) << endl;
            break;
        }

        case 2:{
            string to_test;
            cin >> to_test;
            cout << valid_octal(to_test) << endl;
            break;
        }

        case 3:{
            string to_test;
            cin >> to_test;
            cout << valid_binary(to_test) << endl;
            break;
        }

        case 4:{
            string to_test;
            cin >> to_test;
            cout << valid_float(to_test) << endl;
            break;
        }

        case 5:{
            string to_test;
            cin >> to_test;
            cout << valid_int(to_test) << endl;
            break;
        }

        case 6:{
            string to_test;
            cin >> to_test;
            cout << classify_string(to_test) << endl;
            break;
        }


    }// of switch
}// of main
