#include<iostream>
#include<fstream>
#include <valarray>

struct Saving {
    float Knowledge;
    float money;
    bool Tech20Century;
    bool Transistor;
    bool Computer;
    bool material;
    bool Mathematics;
    bool Being;
    bool NaNtech;
    bool QuatumTech;
    bool ColdNuke;
    bool WarpEngine;
    bool NeuralNetwork;
    bool ArtificialIntellect;
    bool Robot;
    bool Singularit;
    Saving(){
        bool Tech20Century = false;
        bool Transistor = false;
        bool Computer = false;
        bool material = false;
        bool Mathematics = false;
        bool Being = false;
        bool NaNtech = false;
        bool QuatumTech = false;
        bool ColdNuke = false;
        bool WarpEngine = false;
        bool NeuralNetwork = false;
        bool ArtificialIntellect = false;
        bool Robot = false;
        bool Singularit = false;
        float Knowledge = 0.0;
        float money = 0.0;
    }
};

//amount savings
Saving dataGame[3];

void SaveData(std::string path, std::string name){
    std::string extension = ".dat";
    std::string fullNameFile = path + name + extension; 
    std::ofstream file(fullNameFile, std::ios::out | std::ios::binary);
    
    if(!file) {
        std::cout << "Cannot open file!" << std::endl;
    }

    for(int i = 0; i < 3; i++) file.write((char *)&dataGame[i], sizeof(dataGame));
    file.close();

    if(!file.good()) {
       std::cout << "Error occurred at writing time!" << std::endl;
   }
}
void LoadData(std::string path, std::string name){
    std::string extension = ".dat";
    std::string fullNameFile = path + name + extension;
    std::ifstream file(fullNameFile, std::ios::out | std::ios::binary);
    if(!file) {
        std::cout << "Cannot open file!" << std::endl;
    }

    for(int i = 0; i < 3; i++) file.read((char *) &dataGame[i], sizeof(dataGame));
    file.close();
    if(!file.good()) {
        std::cout << "Error occurred at reading time!" << std::endl;
    }

    std::cout<<" Details:"<<std::endl;
    for(int i=0; i < 3; i++) {
        std::cout << "Knowledge: " << dataGame[i].Knowledge << std::endl;
        std::cout << "Money: " << dataGame[i].money << std::endl;
      
    }
   
}
bool CheckExistsFile(const std::string& name){
    std::ifstream f(name.c_str());
    return f.good();
}
