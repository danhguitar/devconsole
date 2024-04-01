#include <iostream>
#include <stdlib.h>
#include "headers/handler.h"

using namespace std;

/*void print(string text, bool newline) {
  if (newline) cout<<text<<endl;
  else cout<<text;
}*/

void console(const char* command) {
  system(command);
}

int main() {
  print("hi", 1);
  bool run = 1;
  string command = "clear";
  //string prevcommand = "clear";
  console("clear");
  while (run) {
    //prevcommand = command;
    print("devconsole: ", 0);
    cin >> command;

    if ((command == "exit") or (command == "quit")) {
      console("clear");
      run = 0;
    }

    else if (command == "clear") console("clear");

    else if (command == "run") console("python3 main.py");

    else if (command == "runbuilt") console("./main.bin");

    else if (command == "build") {
      console("rm -rf main.bin");
      console("pyinstaller main.py --onefile --noconsole");
      print("built main.bin; prepping distribution", 1);
      console("mv dist/main $0 && mv sh main.bin");
      console("rm -rf build dist main.spec");
    }

    else if (command == "todo") {
      list<string> lines = readfilelist("todo.txt");
      for (string i : lines) {
        print(i, 0);
      }
    }

    else if (command == "ls") console("ls");

    else if (command == "mkfile") {
      string filename = "";
      cin >> filename;
      mkfile(filename);
    }

    else if (command == "help") {
      print("commands:", 1);
      print("exit/quit : quits devconsole\nclear : clears console\nrun : runs main.py\nrunbuilt : runs main.bin\nbuild : builds main.py to main.bin using pyinstaller\ntodo : prints the todo.txt file\nls : lists files in dir\nmkfile : makes a file\nhelp: this command", 1);
    }

    /*else if (command =="pleasedontrunthiscommandcomeoniknowthiswillremoveallfilesfrommysystem") {
      rmfile("yea");
    }*/

    /*else if (command == "rmfile") {
      string filename = "";
      cin >> filename;
      const char* subcom = "rm -rf "+filename;
      console(subcom);
    }*/

    /*else if (command == "bash") {
      print("bash command: ", 0);
      string subcom = "clear";
      cin >> subcom;
      console(subcom);
    }*/
  
    else print("command: \"" +command+ "\" unrecognized", 1);

  }
  return 0;
}