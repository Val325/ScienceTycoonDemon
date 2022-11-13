#include <iostream>
#include <string>
#include "D:/Program/raylib/Sourse/include/raylib-cpp.hpp"

std::string DownloadJson(std::string pathJson){
    std::string jsonData;
    std::string jsonTemp;
    std::ifstream file;
    
    //"src/location/laboratory/Tiles/jsonFloor.json"
    file.open(pathJson);
    //raylib::DrawText(jsonData, 30, 20, 20, WHITE);
    
    while (getline(file,jsonTemp))
    {
        jsonData = jsonData + jsonTemp + "\n";    
    }
    
    
    
    
    return jsonData;
    
    file.close(); 
}
std::vector<int> JsonToArray(std::string JsonData, int AmountArray){
    int PositionFirstOccurenceArray;
    
    std::vector<int> idArray;
    idArray.resize(AmountArray);
    
    std::string ArrayBegin = ":[";
    std::string ArrayEnd = "]";
    
    //std::size_t PositionFirstOccurenceArray = JsonData.find(ArrayBegin);
    
    std::cout << "JSON text:" << JsonData << "\n";
   // std::cout << "First occurence array from JSON:" << PositionFirstOccurenceArray << "\n";
    
    //std::size_t PositionEndOccurenceArray = JsonData.find(ArrayEnd);
    
    //std::cout << "End occurence array from JSON:" << PositionEndOccurenceArray << "\n";   
}
//Test void
void JsonToArray(std::string JsonData){
    
    JsonData = DownloadJson(JsonData);
    
    std::string ArrayBegin = ":[";
    std::string ArrayEnd = "]";
    
    std::size_t PositionFirstOccurenceArray = JsonData.find(ArrayBegin);
    
    std::cout << "JSON text:" << JsonData << "\n";
    std::cout << "First occurence array from JSON:" << PositionFirstOccurenceArray << "\n";
    
    std::size_t PositionEndOccurenceArray = JsonData.find(ArrayEnd);
    
    std::cout << "End occurence array from JSON:" << PositionEndOccurenceArray << "\n"; 
    
}
//Return from JSON first to end subString
/*
std::string JsonToArray(std::string JsonData, int first, int end){
    
    JsonData = DownloadJson(JsonData);
    
    std::string ArrayBegin = ":[";
    std::string ArrayEnd = "]";
    
    std::size_t PositionFirstOccurenceArray = JsonData.find(ArrayBegin);
    
    std::cout << "JSON text:" << JsonData << "\n";
    std::cout << "First occurence array from JSON:" << PositionFirstOccurenceArray << "\n";
    
    std::size_t PositionEndOccurenceArray = JsonData.find(ArrayEnd);
    
    std::cout << "End occurence array from JSON:" << PositionEndOccurenceArray << "\n"; 
    
    std::cout << "--------------------------------------" << "\n";
    return string::substr(first, end);
}*/
