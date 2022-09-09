#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <limits>

using namespace std;

fstream& onLine(fstream& file, unsigned int num){
    file.seekg(std::ios::beg);
    for(int i=0; i < num-1; i++){ 
      file.ignore(numeric_limits<streamsize>::max(),'\n'); 
    }
    return file;
}
void start(){
  cout<<"    |-----------|"<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"__________          "<<endl;
}
void mistake1(){
  cout<<"    |-----------|"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"__________          "<<endl;
}
void mistake2(){
  cout<<"    |-----------|"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |           |    "<<endl;
  cout<<"    |           | "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"__________          "<<endl;
}
void mistake3(){
  cout<<"    |-----------|"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |           |    "<<endl;
  cout<<"    |       --- | --- "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"    |               "<<endl;
  cout<<"__________          "<<endl;
}
void mistake4(){
  cout<<"    |-----------|"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |        |     |"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |           |    "<<endl;
  cout<<"    |       --- | --- "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |          | |  "<<endl;
  cout<<"    |          | |  "<<endl;
  cout<<"    |          | |  "<<endl;
  cout<<"__________          "<<endl;
}
void mistake5(){
  cout<<"    |-----------|"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |        | | | |"<<endl;
  cout<<"    |        |  n  |"<<endl;
  cout<<"    |         ----- "<<endl;
  cout<<"    |           |    "<<endl;
  cout<<"    |       --- | --- "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |           |   "<<endl;
  cout<<"    |          | |  "<<endl;
  cout<<"    |          | |  "<<endl;
  cout<<"    |          | |  "<<endl;
  cout<<"__________          "<<endl;
}
int main() {
  srand(time(NULL));
  int random = rand()%837+1;
  fstream myfile;
  myfile.open("words.txt");
  string k;
  onLine(myfile,random);
  myfile>>k;
  cout<<"You have 5 tries."<<endl;
  string output="";
  for (int i=0;i<k.length();i++){
    output+="_";
  }
  int failcount = 0;
  bool win = false;
  string correctstr = "";
  string wrongstr = "";
  char a[26];
  int index = 0;
  while((failcount !=5) and !win){
      if (failcount==0){
        start();
      }else if (failcount==1){
        mistake1();
      }else if (failcount==2){
        mistake2();
      }else if (failcount==3){
        mistake3();
      }else if (failcount==4){
        mistake4();
      }
      char c;
      cout<<"Correct Bank: "<<correctstr<<endl;
      cout<<"Incorrect Bank: "<<wrongstr<<endl;
      cout<<"Word: "<<output<<endl;
      bool valid = false;
      while(!valid){
        cout<<"Enter letter: ";
        char tempo;
        cin>>tempo;
        c=tolower(tempo);
        int counter=0;
        for (int i=0;i<index+1;i++){
          if (a[i]==c){
            counter+=1;
          }
        }
        if (counter==0){
          valid = true;
        }else{
          cout<<"Don't repeat letters!"<<endl;
        }
      }
      int correct = 0;
      for (int i=0;i<k.length();i++){
        if (k[i]==c){
          output[i]=c;
          correct+=1;
        }
      }
      if (correct==0){
        failcount+=1;
        wrongstr+=c;
        wrongstr+=" ";
        a[index]=c;
        index+=1;
      }else{
        correctstr+=c;
        correctstr+=" ";
        a[index]=c;
        index+=1;
      }
      bool equality = true;
      for (int i=0;i<k.length();i++){
        if (output[i]!=k[i]){
          equality = false;
        }
      }
      if (equality){
        win = true;
      }
  }

  if (win){
    cout<<"You Won! The word was "<<k<<"."<<endl;
  }else{
    mistake5();
    cout<<"Sorry, the word was "<<k<<"."<<endl;
  }

}
