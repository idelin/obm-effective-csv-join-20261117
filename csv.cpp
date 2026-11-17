#include "csv.hpp"
#include <stdexcept>
std::vector<std::string> split_record(const std::string& row) {
    std::vector<std::string> out; std::string word; bool quoted=false;
    for (std::size_t i=0;i<row.size();++i) {
        char c=row[i];
        if(c=='"') { if(quoted && i+1<row.size() && row[i+1]=='"') {word+='"';++i;} else quoted=!quoted; }
        else if(c==',' && !quoted) {out.push_back(word);word.clear();}
        else word+=c;
    }
    if(quoted) throw std::runtime_error("open quote");
    out.push_back(word);return out;
}
std::string quote(const std::string& field) {
    if(field.find_first_of(",\"\r\n")==std::string::npos)return field;
    std::string out="\"";for(char c:field){out+=c;if(c=='"')out+=c;}return out+"\"";
}
