#include <iostream>
#include <string>
#include <bitset>
#include <bits/stdc++.h>
#include <bit>

int main(int argc, char** argv){
    std::string bin1 = "0101";
    std::string bin2 = "1111";

    int bin1_i = 0b0101;
    int bin2_i = 0b1111;

    int bin1_stoi = std::stoi(bin1);
    int bin2_stoi = std::stoi(bin2);

    std::bitset<4> b1(bin1);
    std::bitset<4> b2(bin2);

}