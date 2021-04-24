#include <iostream>
#include <locale>
#include <string>
#include <map>
#include <vector>
#include <codecvt>
#include <windows.h>
#include "C:\Users\86532\Study\1 grade\Proga\Labs\C++\lib\pugixml-master\src\pugixml.hpp"

struct Point{
    double x;
    double y;
};

std::ostream& operator<<(std::ostream& stream, const std::wstring& str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    stream << conv.to_bytes(str);
    return stream;
}

int main(){
     SetConsoleOutputCP(CP_UTF8);
     pugi::xml_document doc;
     pugi::xml_parse_result result = doc.load_file("data.xml");
     pugi::xml_node transport_station = doc.child(L"dataset").child(L"transport_station");

     std::wstring type_of_vehicle =
                     transport_station.child(L"type_of_vehicle").text().as_string();
     std::cout << type_of_vehicle << std::endl;
     std::cout << "Hello";


    return 0;

}


