#include <iostream>
#include <string>
#include <stdlib.h>
#include "raylib-cpp.hpp"
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <chrono>
#include <ctime>
#include <cmath>

#pragma once
using json = nlohmann::json;

/*
typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
} Timer;

void StartTimer(Timer *timer, double lifetime)
{
    timer->startTime = GetTime();
    timer->lifeTime = lifetime;
}

bool TimerDone(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer)
{
    return GetTime() - timer.startTime;
}
*/


std::string DownloadJson(std::string pathJson){
    std::string jsonData;
    std::string jsonTemp;
    std::ifstream file;


    file.open(pathJson);


    while (getline(file,jsonTemp))
    {
        jsonData = jsonData + jsonTemp + "\n";
    }




    return jsonData;

    file.close();
}

//Return from JSON first to end subString
std::string JsonToArraySubStrSquare(std::string JsonData, int first, int end){

    JsonData = DownloadJson(JsonData);

    std::string ArrayBegin = ":[";
    std::string ArrayEnd = "]";

    std::size_t PositionFirstOccurenceArray = JsonData.find(ArrayBegin);

    std::cout << "JSON text:" << JsonData << "\n";
    std::cout << "First occurence array from JSON:" << PositionFirstOccurenceArray << "\n";

    std::size_t PositionEndOccurenceArray = JsonData.find(ArrayEnd);

    std::cout << "End occurence array from JSON:" << PositionEndOccurenceArray << "\n";

    std::cout << "--------------------------------------" << "\n";
    std::cout << JsonData.substr(first, end) << "\n";

    return JsonData.substr(first, end);
}

//AmountArray without separator string, if AmountArray have separator then need divide 3. AmountArray = AmountArray / 3


//JsonToArrayNumber

std::vector<int> JsonToArrayNumber(std::string JsonData, std::string NameData, int num){
    //Amount array need be 391
    // 9 and 1172 subString
    // "src/location/laboratory/Tiles/TiledMapLAboratory.json"


    json data = json::parse(DownloadJson(JsonData));
    std::vector<int> ArrayId;
    ArrayId.resize(num);
    data[NameData].get_to(ArrayId);

    
    for (int i = 0; i < num; i++){
        std::cout << ArrayId[i];
    }

    for (auto i : ArrayId)
    {
        std::cout << i << '\n';
    }

    return ArrayId;




}

//Test void, useless
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




