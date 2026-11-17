#include "csv.hpp"
#include <iostream>
#include <fstream>
int main(int argc,char** argv) {
    if(argc!=2){std::cerr<<"usage: csvjoin FILE\n";return 2;}
    std::ifstream in(argv[1]);std::string line;std::size_t n=0;
    try{while(std::getline(in,line)){auto row=split_record(line);++n;}}
    catch(...){std::cerr<<"ERROR\n";return 2;}
    std::cout<<n<<"\n";
}
