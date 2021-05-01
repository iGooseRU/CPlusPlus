#include <iostream>
#include <locale>
#include <string>
#include <vector>
#include <codecvt>
#include <windows.h>
#include <cstdlib>
#include <unordered_map>
#include <cmath>
#include "C:\Users\86532\Study\1 grade\Proga\Labs\C++\lib\pugixml-master\src\pugixml.hpp"

#define EARTH_RADIUS 6372795

struct Point{
    double x;
    double y;
};

typedef std::unordered_map<std::wstring, std::unordered_map<std::string, std::vector<Point>>> type;

double calculateDist(double lat1, double lon1, double lat2, double lon2){

    // переводим координаты в радианы
    double Rlat1 = lat1 * M_PI / 180;
    double Rlon1 = lon1 * M_PI / 180;
    double Rlat2 = lat2 * M_PI / 180;
    double Rlon2 = lon2 * M_PI / 180;

    // косинусы и синусы широт и разницы долгот
    double cl1 = cos(Rlat1);
    double cl2 = cos(Rlat2);
    double sl1 = sin(Rlat1);
    double sl2 = sin(Rlat2);
    double delta = Rlon2 - Rlon1;
    double cdelta = cos(delta);
    double sdelta = sin(delta);

    // вычисления длины большого круга
    double y = sqrt(pow(cl2 * sdelta, 2) + pow(cl1 * sl2 - sl1 * cl2 * cdelta, 2));
    double x = sl1 * sl2 + cl1 * cl2 * cdelta;

    double ad = atan2(y, x);
    double dist = ad * EARTH_RADIUS;

    return dist;
}

class Data{
protected:
    pugi::xml_document doc;
    pugi::xml_node dataset;
    type all_data;

public:
    void read_xml();
    static void parsingRoutes(std::wstring &routes, std::vector <std::string> &vectorRoutes);
    static void parsingCoords(std::wstring &coords, Point &parsedCoords);
    void task1();
    void task2();

    Data(){
        read_xml();
        pugi::xml_node transport_station = dataset.child(L"transport_station");

        while (transport_station){

            std::wstring routes = transport_station.child(L"routes").text().as_string();
            std::vector <std::string> vectorRoutes;
            parsingRoutes(routes, vectorRoutes);

            std::wstring coords =  transport_station.child(L"coordinates").text().as_string();
            Point parsedCoords{};
            parsingCoords(coords, parsedCoords);


            for (auto & vectorRoute : vectorRoutes){
              all_data[transport_station.child(L"type_of_vehicle").text().as_string()]
                        [vectorRoute].push_back(parsedCoords);
            }
            transport_station = transport_station.next_sibling(L"transport_station");
        }

        // print_data();

        task1();
        task2();
    };

    friend std::ostream& operator<<(std::ostream& stream, const std::wstring& str);


    static std::string convert_ws_to_st(std::wstring get_wstr){
        std::string temp;
        for (int i = 0; i <= get_wstr.size(); i++){
            temp += get_wstr[i];
        }
        return temp;
    }
};


std::ostream& operator<<(std::ostream& stream, const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    stream << conv.to_bytes(str);
    return stream;
}

void Data::read_xml(){

    std::cout << "Opening XML..." << std::endl;
    pugi::xml_parse_result result = doc.load_file("data.xml");

    std::cout << "Success: " << result.description() << std::endl << std::endl;
    dataset = doc.child(L"dataset");


}

void Data::parsingRoutes(std::wstring &routes, std::vector <std::string> &vectorRoutes){

    std::string currentRoute;
    for (int i = 0; i < routes.length(); i++){

        if (routes[i] == '.' || routes[i] == ','){
            vectorRoutes.push_back(currentRoute);
            currentRoute = "";
        }
        else {
            currentRoute += routes[i];
            if (i == routes.length() - 1){
                vectorRoutes.push_back(currentRoute);
            }
        }
    }

}

void Data::parsingCoords(std::wstring &coords, Point &parsedCoords){
    std::string currentCoord;

    for (int i = 0; i < coords.length(); i++) {
        if (coords[i] == ',') {
            parsedCoords.x = strtod(currentCoord.c_str(), nullptr);
            currentCoord = "";
        }
        else {
            currentCoord += coords[i];
            if (i == coords.length() - 1){
                parsedCoords.y = strtod(currentCoord.c_str(), nullptr);
            }
        }
    }
}

void Data::task1(){
    std::cout << "======== TASK 1 ======== \n";
    auto it = all_data.begin();


    for (; it != all_data.end(); it++){
        int MAX_stations = 0;
        std::string route;
        auto it2 = it->second.begin();

        for (; it2 != it->second.end(); it2++){
            if (it2->second.size() > MAX_stations) {
                MAX_stations = it2->second.size();
                route = it2->first;
            }
        }
        std::cout << it->first << " has " << route << " route(s) with " << MAX_stations
                                                                            << " stations" << std::endl;
    }
    std::cout << std::endl;
}

void Data::task2(){
    std::cout << "======== TASK 2 ======== \n";

    auto it = all_data.begin();
    for (; it != all_data.end(); it++) {
        int MAX_dist = 0;
        std::string distance;

        auto it2 = it->second.begin();

        for (int i = 0; i < it2->second.size(); i++) {
            double lan1 = it2->second[i].x;
            double lot1 = it2->second[i].y;
            double lan2 = it2->second[i].x;
            double lot2 = it2->second[i].y;

            if (calculateDist(lan1, lot1, lan2, lot2) > MAX_dist)
                MAX_dist = it2->second.size();
                distance = it2->first;
        }
        std::cout << it->first << ": max distance = " << distance << " km\n";
    }
}


int main(){
     SetConsoleOutputCP(CP_UTF8);
     Data firstData;


    return 0;

}


